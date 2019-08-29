#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
int n,A,B,C,D,a[1005],s[1005],mi[1005][1005],opt[1005];
signed main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read();
	A=read();
	B=read();
	C=read();
	D=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		s[i]=a[i]*a[i]*a[i]*A+a[i]*a[i]*B+a[i]*C+D;
	}
	if (n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			mi[i][i]=i;
			for(int j=i+1;j<=n;j++)
				if (a[mi[i][j-1]]>a[j]) mi[i][j]=j;
				else mi[i][j]=mi[i][j-1];
		}
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=0;j--)
				opt[i]=max(opt[j]+s[mi[j+1][i]],opt[i]);
		cout<<opt[n]<<endl;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			if (s[i]>0) ans+=s[i];
		if (ans!=0) cout<<ans<<endl;
		else
		{
			int mi=-LONG_LONG_MAX;
			for(int i=1;i<=n;i++)
				mi=max(s[i],mi);
			cout<<mi<<endl;
		}
	}
	return 0;
}

