#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	   while(c<='9' && c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	   return x*f;
}
long long a[10000005],ys[10000005];
int xa,xb,xc,xd,xe;
long long ans=0;
int n,m;
int g(int x){
	return xa*x+xb*x*x+xc*x*x*x+xd*x*x*x*x+xe*x*x*x*x*x;
}
long long l[300],r[300];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();m=read();xa=read();xb=read();xc=read();xd=read();xe=read();
	for(int i=1;i<=n;i++){
		l[i]=read();
		r[i]=read();
		a[l[i]]++;
		a[r[i]+1]--;
	}
	for(int i=1;i<=m;i++){
		ys[i]=a[i]+ys[i-1];
	}
	int cn=n;
	while(cn>0){
		int maxn=-0x3f,bh;
		for(int i=1;i<=m;i++){
			if(ys[i]>maxn){
				bh=i;
				maxn=ys[i];
			}
		}
		cn-=maxn;
		ans+=g(maxn);
		for(int i=1;i<=n;i++){
			if(l[i]<=bh && r[i]>=bh){
				for(int j=l[i];j<=r[i];j++){
					ys[j]--;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


