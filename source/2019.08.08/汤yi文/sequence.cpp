#include<bits/stdc++.h>
using namespace std;
#define RG register
#define int long long
#define M 500100
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int n,m;
int a[M],f[M],p[M],q[M];
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read();
	for(RG int i=1;i<=m;i++)
	{
		int l=read(),r=read(),s=read(),e=read();
		int k;
		if((r-l)<=0) k=s-e;
		else k=(e-s)/(r-l);
		f[l]+=s,f[r+1]-=s;
		a[l+1]+=k,a[r+1]=k;
	}
	for(RG int i=1;i<=n;i++)
	p[i]=p[i-1]+f[i];
	for(RG int i=1;i<=n;i++)
	q[i]=q[i-1]+a[i];
	int ans=q[1]+p[1];
	for(RG int i=2;i<=n;i++)
	ans=ans^(q[i]+p[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
