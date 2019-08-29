#include<bits/stdc++.h>
#define rg register
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=5e5+10;
int n,m,a[MAXN],b[MAXN],k;
inline bool chk(int l,int ll,int rr,int x){
	if(ll+(k-(x-l+1))-1>rr)return 0;
	if(a[x]>=b[ll+(k-(x-l+1))-1])return 1;return 0;
}
inline bool chk2(int l,int ll,int rr,int x){
	if(ll+(k-(x-l+1))-1>rr)return 0;
	if(b[x]>=a[ll+(k-(x-l+1))-1])return 1;return 0;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read(),m=read();
	for(rg int i=1;i<=n;i++)a[i]=read();
	for(rg int i=1;i<=n;i++)b[i]=read();
	while(m--){
		rg int opt,x,l,ll,r,rr,y,z;
		opt=read();
		if(opt==1){
			x=read(),y=read(),z=read();
			if(x==0)a[y]=z;
			else b[y]=z;
		}else{
			l=read(),r=read(),ll=read(),rr=read();
			k=r-l+rr-ll+3;k>>=1;
			if(a[l]>=b[rr]){
				if(rr-ll+1>=k)printf("%d\n",b[ll+k-1]);
				else printf("%d\n",a[l+(k-(rr-ll+1))-1]);
			}
			else if(a[rr]<=b[ll]){
				if(r-l+1>=k)printf("%d\n",a[l+k-1]);
				else printf("%d\n",b[ll+(k-(r-l+1))-1]);
			}
			else{
				rg int L=l,R=r,tmp;
				while(L<=R){
					int mid=(L+R)>>1;
					if(chk(l,ll,rr,mid))tmp=mid,R=mid-1;
					else L=mid+1;
				}
				if(ll+(k-(tmp-l+1))>rr||a[tmp]<=b[ll+(k-(tmp-l+1))])printf("%d\n",a[tmp]);
				else{
					L=ll,R=rr;
					while(L<=R){
						int mid=(L+R)>>1;
						if(chk2(ll,l,r,mid))tmp=mid,R=mid-1;
						else L=mid+1;
					}
					if(l+(k-(tmp-ll+1))>r||b[tmp]<=a[l+(k-(tmp-ll+1))])printf("%d\n",b[tmp]);
				}
			}
		}
	}
	return 0;
}
