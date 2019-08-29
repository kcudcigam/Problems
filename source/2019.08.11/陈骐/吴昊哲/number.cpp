#include<bits/stdc++.h>
using namespace std;
int t,a,b,c;
long long n[1000000];
int ck(int a)
{
	int t;
	while(a!=0)
	{
		t=a%10;
		a=a/10;
		if(a==0)break;
		if(t!=a%10)return false;
	}
	return true;
}
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n[i];
	}
	for(int i=1;i<=t;i++)
	{
		if(ck(n[i])||n[i]<101)cout<<1<<endl;
	    else cout<<2<<endl;
	}
	return 0;
}


