#include<bits/stdc++.h>
using namespace std;

long long d = 6, f3 = 6, f2 = 10, f1 = 20;
long long n, q, p, now;
long long dnum[10000010];

int main()
{
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	dnum[1] = 0; dnum[2] = 2; dnum[3] = 6; dnum[4] = 10;
	for (int i = 5; i <= 10000000; i++)
	{
		dnum[i] = f1;
		if (d < 0) d = -d + 4; else d = -d - 4;
		f3 += d;
		f2 += f3;
		f1 += f2;
	}
	
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> n >> p;
		now = 0;
		for (int j = 1; j <= n; j++)
			now = (now * j + dnum[j]) % p;
		cout << now << endl;
	}

	return 0;
}

