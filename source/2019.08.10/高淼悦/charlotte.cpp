#include<bits/stdc++.h>
using namespace std;

struct data{
	int x,y,t;
}a[200000];

bool cmp(data f1,data f2)
{
	return f1.t<f2.t;
}

int read()
{
	char ch=getchar();
	int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+(ch-'0');ch=getchar();}
	return n*f;
}

int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T,n;
	T=read();
	while (T>=1)
	{
		T--;
		int f=1;
		n=read();
		for (int i=1;i<=n;i++)
		{	
			a[i].t=read();
			a[i].x=read();
			a[i].y=read();
		}
		sort(a+1,a+n+1,cmp);
		int lx=0,ly=0,lt=0;
		for (int i=1;i<=n;i++)
		{
			int h=a[i].t-lt-abs(a[i].x-lx)-abs(a[i].y-ly);
			//cout<<i<<" "<<h<<endl;
			if (h<0||h%2==1)
			{
				//cout<<i<<" "<<a[i].t-lt<<" "<<abs(a[i].x-lx)+abs(a[i].y-ly)<<endl;
				f=-1;
				break;
			} 
			lt=a[i].t;
			lx=a[i].x;
			ly=a[i].y;
		}
		if (f==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


