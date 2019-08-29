#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int lx=0,ly=0,lt=0,fl=1;
		while(n--)
		{
			int x,y,t;
			cin>>t>>x>>y;
			int o=abs(x-lx)+abs(y-ly)-(t-lt);
			if(o>0||o%2!=0)
			fl=0;
			lx=x;ly=y;lt=t;
		}
		if(fl) cout<<"Yes"<<endl; else cout<<"No"<<endl;
	}
	return 0;
}


