#include<bits/stdc++.h>
using namespace std;
int n,m,a[3][500005],t,x,y,z,l,r,l1,r1;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int work(int zuo,int you,int zuo1,int you1)
{
	priority_queue<int> q;
	while(!q.empty())
	q.pop();
	for (int i=zuo;i<=you;i++)
	q.push(a[1][i]);
	for (int i=zuo1;i<=you1;i++)
	q.push(a[2][i]);
	for (int i=1;i<=(you-zuo+you1-zuo1+2)/2;i++)
	{
		q.pop();
	}
	return q.top();
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();
	m=ri();
	for (int i=1;i<=n;i++)
	{
		a[1][i]=ri();
	}
	for (int i=1;i<=n;i++)
	{
		a[2][i]=ri();
	}
	for (int i=1;i<=m;i++)
	{
		t=ri();
		x=ri();
		y=ri();
		z=ri();
		if(t==1)
		{
			a[x+1][y]=z;
		}
		else {
			r1=ri();
			l=x;
			r=y;
			l1=z;
			cout<<work(l,r,l1,r1)<<endl;
		}
	}
	return 0;
}
