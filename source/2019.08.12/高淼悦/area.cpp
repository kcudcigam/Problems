#include<bits/stdc++.h>
using namespace std;

int read()
{
	char ch=getchar();int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int n,m;
	cin>>n>>m;
	n++;m++;
	if ((m-n==2||n-m==2)&&n%2==0) 
	{
		cout<<5<<endl;
		return 0;
	}
	if ((m-n==1&&m%2==0)||(n-m==1&&n%2==0))
	{
		cout<<5<<endl;
		return 0;
	}
	if (n==m&&n%2==1&&n!=1)
	{
		cout<<5<<endl;
		return 0;
	}
	if (n%2==0&&m%2==0&&n!=m)
	{
		cout<<1<<endl;
		return 0;
	}
	cout<<"infinity"<<endl;
	return 0;
}


