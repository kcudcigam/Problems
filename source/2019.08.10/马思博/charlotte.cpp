#include<bits/stdc++.h>
using namespace std;

struct node
{
	int t,x,y;
};node tra[100005];

bool cmp(const node &a,const node &b)
{
	return a.t<b.t;
}

int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for(int i=1;i<=n;++i) cin>>tra[i].t>>tra[i].x>>tra[i].y;
    	sort(tra+1,tra+n+1,cmp);
    	int nx=0,ny=0,nt=0,flag=0;
    	for(int i=1;i<=n;i++)
    	{
    		int ca=tra[i].t-nt-abs(tra[i].x-nx)-abs(tra[i].y-ny);
    		if(ca<0||ca%2==1) {flag=1;break;} 
    		nx=tra[i].x;ny=tra[i].y;nt=tra[i].t;
		}
		if(flag==0) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}


