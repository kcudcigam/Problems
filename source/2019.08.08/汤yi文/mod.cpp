#include<bits/stdc++.h>
using namespace std;
#define RG register
#define int long long
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int f[1000010];
int n,p,x;
signed main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	f[1]=0;f[2]=2;f[3]=12;
	f[4]=58;f[5]=310;
	f[6]=1886;f[7]=13244;
	f[8]=106002;
	f[9]=954090;
	f[10]=9540982;
	int k=10;
	n=read();
	for(RG int i=1;i<=n;i++)
	{
		x=read();p=read();
		if(f[x])
		{
			int ans=f[x]%p;
			cout<<ans<<endl;
		}
		else
		{
			for(RG int j=k+1;k<=x;k++)
			f[j]=f[j-1]*j+j*(j-1);
			int ans=f[x]%p;
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
