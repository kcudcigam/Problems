#include<bits/stdc++.h>
using namespace std;

#define TIMES 1000

int p[110], b[110], a[110];
int t, n, ans;

bool genper()
{
	p[4]++;
	if (p[4] > n)
	{
		p[4] = 0;
		p[3]++;
	}
	if (p[3] > n)
	{
		p[3] = 0;
		p[2]++;
	}
	if (p[2] > n)
	{
		p[2] = 0;
		p[1]++;
	}
	if (p[1] > n)
		return false;
	return true;
}

int main()
{
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
		cin >> a[i];
	while (genper())
	{
		if (p[1] != 1 && p[2] != 1 && p[3] != 1 && p[4] != 1) continue;
		if (p[1] <= 1 && p[2] <= 1 && p[3] <= 1 && p[4] <= 1) continue;
		for (int i = 1; i <= 4; i++) b[i] = p[i];
		t = 0; 
		while ((b[1] > 0 || b[2] > 0 || b[3] > 0 || b[4] > 0) && (t <= TIMES))
		{
			t++;
			for (int i = 1; i <= 4; i++)
			{
				b[i]--;
				if (b[i] > 0)
					for (int j = 1; j <= 4; j++)
						if (b[j] <= 0)
						{
							b[j] = a[b[i]];
							break;
						}
			}
		}
		if (t > TIMES)
		{
			ans++;
			//cout << p[1] << " " << p[2] << " " << p[3] << " " << p[4] << endl;
		}
	}
	cout << ans << endl;

	return 0;
}

