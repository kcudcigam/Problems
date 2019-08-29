#include<bits/stdc++.h>
using namespace std;

long long n,A,B,C,D,out;
long long num[200010],f[2][2000][2];

long long g(int in)
{
	return D + C * in + B * in * in + A * in * in * in;
}

int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	cin>>n>>A>>B>>C>>D;
	for(int i = 1;i <= n;i++)
	{
		cin>>num[i];
	}
	
	if(A >= 0 && B >= 0 && C >= 0 && D >= 0)
	{
		for(int i = 1;i <= n;i++)
		out += g(num[i]);
		cout<<out;
		return 0;
	}
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= min(i,1500);j++)
		{
			if(i == j)
			{
				f[i % 2][j][0] = f[(i - 1) % 2][j - 1][0] + g(num[i]);
				f[i % 2][j][1] = num[i];
			}
			else
			{
				int n_num,n_min;
				n_num = f[(i - 1) % 2][j][0];
				n_min = f[(i - 1) % 2][j][1];
				if(f[(i - 1) % 2][j][1] > num[i])
				{
					n_num = f[(i - 1) % 2][j][0] - g(f[(i - 1) % 2][j][1]) + g(num[i]);
					n_min = num[i];
				}
				if(f[(i - 1) % 2][j - 1][0] + g(num[i]) > n_num)
				{
					n_num = f[(i - 1) % 2][j - 1][0] + g(num[i]);
					n_min = num[i];
				}
				f[i % 2][j][0] = n_num;
				f[i % 2][j][1] = n_min;
			}
			
			if(i == n)
			{
				out = max(f[i % 2][j][0],out);
			}
		}
	}
	
	cout<<out;
	
	return 0;
}

