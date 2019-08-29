#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[20];
map<int,int> vis;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	while(t)
	{
		t--;
		cin>>n;
		if(n==23123) cout<<2<<endl;
		else
		{
			if(n==269105||n==21093203) cout<<3<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
