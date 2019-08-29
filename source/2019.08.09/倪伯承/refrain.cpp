#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	long long n,out = 1;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		out *= i;
		out = out % 1000000007;
	}
	cout<<out - 1;
	return 0;
}

