#include<bits/stdc++.h>
using namespace std;
int a[10];
int gs()
{
	int s=0;
	for(int i=0;i<10;i++) if(a[i]) s++;
	return s;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		memset(a,9,sizeof(a));
		while(n)
		{
			a[n%10]++;
			n/=10;
		}
		if(gs()<=2) cout<<1<<endl;
		else if(gs()==3) cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}

