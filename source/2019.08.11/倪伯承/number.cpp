#include<bits/stdc++.h>
using namespace std;

int T,in,total;
bool hehe[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>in;
		if(in == 0) cout<<0<<endl;
		else if(in > 300000)
		{
			while(in > 0)
			{
				if(hehe[in % 10] == 0)
				total++;
				hehe[in % 10]++;
				in /= 10;
			}
			if(total <= 2)
			cout<<1<<endl;
			else if(total <= 5)
			cout<<2<<endl;
			else cout<<3<<endl;
		}
		else
		{
			while(in > 0)
			{
				if(hehe[in % 10] == 0)
				total++;
				hehe[in % 10]++;
				in /= 10;
			}
			if(total <= 2)
			cout<<1<<endl;
			else cout<<2<<endl;
		}
		for(int i = 0;i <= 9;i++)
		hehe[i] = 0;
		total = 0;
	}
	return 0;
}


