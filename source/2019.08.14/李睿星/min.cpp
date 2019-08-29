#include<cstdio>
using namespace std;
void read(int &x){
	char c=getchar();x=0;int f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)-'0'+c;
	x*=f;
}
int n,A,B,C,D,a[200005],fa[200005],minm=0x7fffffff;long long f[200005],ans,sum;
long long js(int x){
	return (((long long)A*x+B)*x+C)*x+D;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(A);read(B);read(C);read(D);
	for(int i=1;i<=n;++i){
		read(a[i]);
		f[i]=js(a[i]);
		fa[i]=i;
	}
	for(int i=2;i<=n;++i)
		if(f[i]<0&&a[find(i-1)]<a[i]) f[fa[i]=find(i-1)]+=f[i],f[i]=0;
	for(int i=n-1;i;--i)
		if(f[i]<0&&a[find(i+1)]<a[i]) f[fa[i]=find(i+1)]+=f[i],f[i]=0;
	for(int i=1;i<=n;++i)
		if(find(i)==i) ans+=f[i];
	printf("%lld",ans);
	return 0;
}
