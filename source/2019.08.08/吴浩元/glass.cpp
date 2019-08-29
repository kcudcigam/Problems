#include<bits/stdc++.h>
using namespace std;

int n, k, j;
int a[1010];

int main()
{
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	a[0] = 1;
	for (int i = 1; i <= 30; i++)
		a[i] = a[i - 1] * 2;
	j = 30;
	for (int i = 1; i <= k - 1; i++)
	{
		for (; j >= 0; j--)
			if (n > a[j])
			{
				n -= a[j];
				break;
			}
	}
	for (int i = 0; i <= 30; i++)
		if (a[i] >= n)
		{
			cout << a[i] - n << endl;
			break;
		}

	return 0;
}

