#include <bits/stdc++.h>
using namespace std;

int y, n, m;

int main()
{
	// need check / further thinking
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> y;
	if ((y & (y - 1)) == 0 && y > 1)
	{
		n = (int)(log(y) / log(2)) + 2;
		m = n * (n - 1) / 2;
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
				cout << i << " " << j << endl;
		}
		return 0;
	}
	n = y + 1; m = 2 * n - 3;
	cout << n << " " << m << endl;
	for (int i = 1; i <= n - 2; i++)
		cout << i << " " << i + 1 << endl;
	for (int i = 1; i <= n - 1; i++)
		cout << i << " " << n << endl;

	return 0;
}


