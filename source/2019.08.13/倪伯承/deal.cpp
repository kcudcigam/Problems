#include<bits/stdc++.h>
using namespace std;

int n,X;
long long a[10010],b[10010],c[10010];
long long f1[20010],f2[10010],out;
int v[20010];

int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>X;
	for(int i = 1;i <= n;i++)
		cin>>a[i]>>b[i]>>c[i];
	
	f1[0] = 1;
	for(int i = n;i >= 1;i--)
		for(int j = X - a[i] + 1;j >= 0;j--)
			if(f1[j] != 0)
				for(int z = 1;z <= b[i] && j + z * a[i] < X + a[i];z++)
					f1[j + z * a[i]] += f1[j];
	
	f2[0] = 1;
	for(int i = n;i >= 1;i--)
		for(int j = a[n] - a[i];j >= 0;j--)
			if(f2[j] != 0)
				for(int z = 1;z <= c[i] && j + z * a[i] < a[n];z++)
					f2[j + z * a[i]] += f2[j];
					
	for(int i = X;i <= X + a[n];i++)
		out = (out + (f1[i] * f2[i - X]) % 1000000007) % 1000000007;
	
	cout<<out;
	
	return 0;
}


