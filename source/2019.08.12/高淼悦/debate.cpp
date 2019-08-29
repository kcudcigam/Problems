#include<bits/stdc++.h>
using namespace std;

int read()
{
	char ch=getchar();int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

int a[400005],b[400005],c[400005],d[400005];

bool cmp(int f1,int f2)
{
	return f1>f2;
}

int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,an=0,bn=0,cn=0,dn=0;
	long long ans=0;
	n=read();
	for (int i=1;i<=n;i++)
	{
		string s1;
		int x;
		cin>>s1;
		x=read();
		if (s1=="11") a[++an]=x;
		if (s1=="10") b[++bn]=x;
		if (s1=="01") c[++cn]=x;
		if (s1=="00") d[++dn]=x;
	}
	sort(a+1,a+an+1,cmp);
	sort(b+1,b+bn+1,cmp);
	sort(c+1,c+cn+1,cmp);
	sort(d+1,d+dn+1,cmp);
	for (int i=1;i<=an;i++)
	{
		ans=ans+a[i];
	}
	int h=min(bn,cn);
	for (int i=1;i<=h;i++)
	{
		ans+=b[i]+c[i];
	}
	for (int i=h+1;i<=bn;i++)
	{
		d[++dn]=b[i];
	}
	for (int i=h+1;i<=cn;i++)
	{
		d[++dn]=c[i];
	}
	sort(d+1,d+dn+1,cmp);
	for (int i=1;i<=an;i++)
	{
		ans+=d[i];
	}
	cout<<ans<<endl;
	return 0;
}


