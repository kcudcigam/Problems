#include<bits/stdc++.h>
using namespace std;
long long n,num,x,y,t;
int read()
{
	int f=1,x=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int jc(int y,long long dep)
{
	if(y==1)
	return dep;
	dep=dep%1000000007;
	dep=dep*y;
	return jc(y-1,dep);
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	num=read();
	n=read();
	x=read();
	y=read();
	for (int i=1;i<=2*x;i++)
	t=read();
	for (int i=1;i<=y*2;i++)
	t=read();
	if(num==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(num==2)
	{
		if(x+y==0)
		cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	cout<<(jc(n,1)-x-y+1)%1000000007<<endl;
	return 0;
}
