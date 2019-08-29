#include<bits/stdc++.h>
using namespace std;
struct node{
	long long zuo,you;
}t[300],a[10000005];
long long n,m,ans[6],x,y,da;
void work(long long wz,long long data,long long jl)
{
	da+=data*ans[1]+data*data*ans[2]+data*data*data*ans[3]+data*data*data*data*ans[4]+data*data*data*data*data*ans[5];
	return ; 
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (long long i=1;i<=5;i++)
	scanf("%d",&ans[i]);
	for (long long i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		t[i].zuo=x;
		t[i].you=y;
		a[x].zuo++;
		a[x].you=y;
	}
	for (long long i=1;i<=m;i++)
	{
		if(a[i].zuo==0)
		continue;
		if(i<a[i].you)
		{
			a[i+1].zuo+=a[i].zuo;
			a[i].zuo=0;
			a[i+1].you=min(a[i+1].you,a[i].you);
			continue;
		}
		work(i,a[i].zuo,a[i].you);
	}
	cout<<da<<endl;
	return 0;
}
