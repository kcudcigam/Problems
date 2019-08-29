#include<bits/stdc++.h>
using namespace std;
int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return f*n;
}

vector <int> v;
int a[500005],b[500005];

int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=m;i++)
	{
		int p,f1,f2,f3,l1,l2,r1,r2;
		p=read();
		if (p==1)
		{
			f1=read();
			f2=read();
			f3=read();
			if (f1==0) a[f2]=f3;
			else b[f2]=f3;
		}
		else
		{
			v.clear();
			l1=read();r1=read();l2=read();r2=read();
			for (int j=l1;j<=r1;j++) v.push_back(a[j]);
			for (int j=l2;j<=r2;j++) v.push_back(b[j]);
			sort(v.begin(),v.end());
		//	for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
		//	cout<<endl;
			int h=v.size()/2+1;
			cout<<v[h-1]<<endl;
		}
	}
	return 0;
}

