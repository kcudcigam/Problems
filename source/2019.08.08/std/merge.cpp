//ios::sync_with_stdio(false);
#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for(int x=y;x<=z;++x)
#define D(x,y,z) for(int x=y;x>=z;--x)
using namespace std;
const int N=1000010;
LL Min(LL x,LL y){return x<y?x:y;}
LL Max(LL x,LL y){return x>y?x:y;}
LL R(){
    LL ans=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if (c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) ans=ans*10+c-'0';
    return ans*f;
}
int n,Q,cnt;
int f[N],son[N][2],a[N];
int Find(int x){return (f[x]==x)?x:(f[x]=Find(f[x]));}
int q[N],ql,qr;
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=R();Q=R();
	F(i,1,n+Q)f[i]=i;
	cnt=n;
	while(Q--){
		int op=R(),x=R(),y=R();
		if(op==1){
			int fx=Find(x),fy=Find(y);
			if(fx==fy)continue;
			++cnt;
			f[fx]=f[fy]=cnt;
			son[cnt][0]=fx;
			son[cnt][1]=fy;
		}
		if(op==2){
			int fx=Find(x);
			a[fx]+=y;
		}
	}
	ql=1;
	F(i,1,cnt)
		if(f[i]==i)q[++qr]=i;
	while(ql<=qr){
		int u=q[ql++];
		if(u>n){
			a[son[u][0]]+=a[u];
			a[son[u][1]]+=a[u];
			q[++qr]=son[u][0];
			q[++qr]=son[u][1];
		}
	}
	F(i,1,n-1)cout<<a[i]<<' ';
	cout<<a[n]<<'\n';
    return 0;
}
