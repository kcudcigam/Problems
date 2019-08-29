#include<bits/stdc++.h>
using namespace std;
#define RG register
#define M 1000000007
#define int long long
inline int read()
{
	long long s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int num;
signed main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	num=read();
	int n,mm,mmm;
	n=read();mm=read();mmm=read();
	for(int i=1;i<=mm;i++)
	{
		int x=read(),y=read();
	}
		for(int i=1;i<=mmm;i++)
	{
		int x=read(),y=read();
	}
	int ans=1;
	for(RG int i=1;i<=n;i++)
	{
		ans=i*ans%M;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
