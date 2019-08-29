#include<bits/stdc++.h>
using namespace std;

int num[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long t,n,sum=0,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n>0)
	    {
		   a=n%10;n/=10;num[a]++;
	    }
	    for(int i=0;i<=9;i++) 
		   if(num[i]!=0) sum++,num[i]=0; 
		if(sum<=2) cout<<1<<endl;
		else if(sum<=4) cout<<2<<endl;
		else cout<<3<<endl;
		sum=0;
	}
	return 0;
}
