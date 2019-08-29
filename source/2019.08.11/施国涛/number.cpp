#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		int js[11]={0,0,0,0,0,0,0,0,0,0,0},tpt=0;
		while(q)
		{
			js[q%10]=1;
			q/=10;
		}
		for(int i=0;i<=10;i++)
		{
			tpt+=js[i];	
		}
		if(tpt>2)
		{
			puts("2");
		}
		else
		{
			puts("1");
		}
	}
}

