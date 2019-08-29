#include<bits/stdc++.h>
#define N 200010
using namespace std;
typedef long long ll;
queue<int>q;
int a[N],fa[N];
int A,B,C,D;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int f(int x){
	return (ll)A*x*x*x+B*x*x+C*x+D;
}
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(x);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n=read();
	A=read(),B=read(),C=read(),D=read();
	ll ans=0;
//	if(A==0&&B==0&&C<=0){
//		for(int i=1;i<=n;i++){
//			int t=read();
//			fa[i]=i;
//			a[i]=f(t);
//		}
//		
//		for(int i=1;i<=n;i++){
//			int x=Find(i),y=Find(i+1);
//			int t=min(a[x],a[y]);
//			if(a[x]==t)
//				if(a[x]+a[y]+2*d<t+d)fa[x]=y;
//			if(a[y]==t)
//		}
//	}
	if(A>=0&&B>=0&&C>=0){
		for(int i=1;i<=n;i++)a[i]=read(),fa[i]=i,ans+=f(a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}


