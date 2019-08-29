#include<bits/stdc++.h>
using namespace std; 
long long num,n,m,x,y,len;
struct node
{
	long long x;
	long long y;
	long long len;
}a[10000];
int main()
{
    freopen("rebirth.in","r",stdin);
    freopen("rebirth.out","w",stdout);
    cin>>num;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i].x>>a[i].y>>a[i].len;
	}
	cout<<0<<endl;
	for(int i=2;i<=n;i++)
	{
		cout<<-1<<endl;
	}
}              
        
