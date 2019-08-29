#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,dfn,cha,cj,f,dx,dy;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++)
	{
		cin>>n;
		dfn=0;
		f=1;
		dx=1;
		dy=1;
		for (int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			cha=a-dfn;
			dfn=a;
			cj=b+c;
			if(a%2==cj%2&&cha>=(abs(b-dx)+abs(c-dy)))
			a=a;
			else f=0;
			dx=b;
			dy=c;
		}
		if(f==1)
		cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
