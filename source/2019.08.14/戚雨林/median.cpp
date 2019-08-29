#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100+(int)(5e5);
const int INF=(int)(1e9);

int n,m,a[N],b[N],opt,x,y,z,u,v,mid,l,r,ans,t;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int Min(int x,int y){
	return ((x<y)?x:y);
}

int Calc(int *a,int l,int r,int x){
	if (a[l]>x) return 0;
	int nw=l,mid,tl=l;
	while (l<=r){
		mid=(l+r)/2;
		if (x>=a[mid]){
			l=mid+1;nw=mid;
		}else r=mid-1;
	}
	return (nw-tl+1);
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=rd();m=rd();
	for (int i=1;i<=n;++i) a[i]=rd();
	for (int i=1;i<=n;++i) b[i]=rd();
	for (int i=1;i<=m;++i){
		opt=rd();
		if (opt==1){
			x=rd();y=rd();z=rd();
			if (x==0) a[y]=z;else b[y]=z;
		}else{
			x=rd();y=rd();
			u=rd();v=rd();
			t=(y-x+1+v-u+1+1)/2;
			ans=INF;
			l=x;r=y;
			while (l<=r){
				mid=(l+r)/2;
				if ((mid-x+1+Calc(b,u,v,a[mid]))>=t){
					r=mid-1;ans=a[mid];
				}else l=mid+1;
			}
			l=u;r=v;
			while (l<=r){
				mid=(l+r)/2;
				if ((mid-u+1+Calc(a,x,y,b[mid]))>=t){
					r=mid-1;ans=Min(ans,b[mid]);
				}else l=mid+1;				
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
