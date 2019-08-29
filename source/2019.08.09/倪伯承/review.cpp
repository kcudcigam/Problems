#include<bits/stdc++.h>
using namespace std;

long long y,en = 2,out;
bool he[100];

int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	long long ha = y;
	while(ha%2 == 0)
	{
		ha /= 2;
		en++;
	}
	if(y == 1)
	cout<<2<<' '<<1<<endl<<1<<' '<<2;
	else if(ha == 1)
	{
		cout<<en<<' '<<en*(en - 1)/2<<endl;
		for(int i = 1;i < en;i++)
		{
			for(int j = i + 1;j <= en;j++)
			{
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	else
	{
		ha = y;en = 2,out = 1;
		while(ha > 0)
		{
			he[en] = ha % 2;
			ha /= 2;
			out += 1 ^ he[en++];
		}
		cout<<en<<' '<<en*(en - 1)/2 - out<<endl;
		for(int i = 1;i < en;i++)
		{
			for(int j = i + 1;j <= en;j++)
			{
				if(j != en || he[i] == 1)
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	
	return 0;
}

