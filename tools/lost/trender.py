"""Textured z-buffer orthographic preview. meshes: list of dict(pos Nx3, tris [(i0,i1,i2)], uvs [(uv0,uv1,uv2)] or None,
tex RGBA array or None, col rgb)."""
import numpy as np
from PIL import Image
import os
CULL=int(os.environ.get('TR_CULL','0')); ALPHA=os.environ.get('TR_ALPHA')=='1'
VIEWS={'side':(1,2,0,1),'front':(0,2,1,1),'top':(0,1,2,1),'iso':None}
def _proj(P,view):
    if view=='iso':
        a=np.radians(35); b=np.radians(60)
        Rz=np.array([[np.cos(a),-np.sin(a),0],[np.sin(a),np.cos(a),0],[0,0,1]])
        Rx=np.array([[1,0,0],[0,np.cos(b),-np.sin(b)],[0,np.sin(b),np.cos(b)]])
        Q=P@Rz.T@Rx.T
        return np.stack([Q[:,0],Q[:,2],-Q[:,1]],1)
    if view=='side2': return np.stack([-P[:,1],P[:,2],-P[:,0]],1)
    if view=='back': return np.stack([-P[:,0],P[:,2],-P[:,1]],1)
    if view=='iso2': return _proj(P*np.array([-1,-1,1]),'iso')
    ua,va,da,_=VIEWS[view]
    return np.stack([P[:,ua],P[:,va],P[:,da]],1)
def render(meshes,out,size=400,views=('side','front','top','iso')):
    img=np.zeros((size,size*len(views),3),np.uint8); img[:]=(40,40,48)
    allP=np.concatenate([np.asarray(m['pos'],float) for m in meshes])
    L=np.array([0.4,0.3,0.85]); L/=np.linalg.norm(L)
    for k,vn in enumerate(views):
        A=_proj(allP,vn); lo,hi=A[:,:2].min(0),A[:,:2].max(0); c=(lo+hi)/2; r=(hi-lo).max()/2*1.05
        zb=np.full((size,size),-1e9); cb=img[:,k*size:(k+1)*size]
        for m in meshes:
            P=np.asarray(m['pos'],float); S=_proj(P,vn)
            sx=(S[:,0]-c[0]+r)/(2*r)*(size-1); sy=(c[1]+r-S[:,1])/(2*r)*(size-1); sz=S[:,2] if vn!='iso' else S[:,2]
            depth=sz if vn in ('iso',) else sz
            tex=m.get('tex'); uvs=m.get('uvs')
            for ti,t in enumerate(m['tris']):
                i0,i1,i2=t
                x=np.array([sx[i0],sx[i1],sx[i2]]); y=np.array([sy[i0],sy[i1],sy[i2]]); z=np.array([depth[i0],depth[i1],depth[i2]])
                if vn=='side' or vn=='front': z=-z if False else z
                x0,x1=int(max(0,np.floor(x.min()))),int(min(size-1,np.ceil(x.max()))); y0,y1=int(max(0,np.floor(y.min()))),int(min(size-1,np.ceil(y.max())))
                if x1<x0 or y1<y0: continue
                den=(y[1]-y[2])*(x[0]-x[2])+(x[2]-x[1])*(y[0]-y[2])
                if abs(den)<1e-9: continue
                if CULL and (den>0)==(CULL>0): continue
                gx,gy=np.meshgrid(np.arange(x0,x1+1)+0.5,np.arange(y0,y1+1)+0.5)
                w0=((y[1]-y[2])*(gx-x[2])+(x[2]-x[1])*(gy-y[2]))/den; w1=((y[2]-y[0])*(gx-x[2])+(x[0]-x[2])*(gy-y[2]))/den; w2=1-w0-w1
                msk=(w0>=-1e-6)&(w1>=-1e-6)&(w2>=-1e-6)
                if not msk.any(): continue
                zz=w0*z[0]+w1*z[1]+w2*z[2]
                sub=zb[y0:y1+1,x0:x1+1]; msk&=zz>sub
                if not msk.any(): continue
                p=P[[i0,i1,i2]]; nrm=np.cross(p[1]-p[0],p[2]-p[0]); ln=np.linalg.norm(nrm)
                sh=0.45+0.55*abs(np.dot(nrm/ln,L)) if ln>0 else 0.7
                if tex is not None and uvs is not None:
                    uv=np.asarray(uvs[ti],float)
                    U=w0*uv[0,0]+w1*uv[1,0]+w2*uv[2,0]; V=w0*uv[0,1]+w1*uv[1,1]+w2*uv[2,1]
                    th,tw=tex.shape[:2]
                    tx=(np.floor(U*tw).astype(int))%tw; ty=(np.floor(V*th).astype(int))%th
                    colr=tex[ty,tx,:3].astype(float)*sh
                    if ALPHA: msk&=tex[ty,tx,3]>=48
                    if os.environ.get('TR_AVIS'): a_=tex[ty,tx,3]; colr[(a_<0x78)]=(255,0,255); colr[(a_<0x30)]=(0,255,255)
                else:
                    colr=np.ones(msk.shape+(3,))*np.array(m.get('col',(0.8,0.8,0.8)))*255*sh
                sub[msk]=zz[msk]
                blk=cb[y0:y1+1,x0:x1+1]; blk[msk]=np.clip(colr[msk],0,255).astype(np.uint8)
    Image.fromarray(img).save(out)
