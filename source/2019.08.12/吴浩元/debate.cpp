#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, c, d;
int cnt, n, x, y, ans;

int main()
{
	// need check
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		if (x == 11) a.push_back(y);
		if (x == 10) b.push_back(y);
		if (x == 01) c.push_back(y);
		if (x == 00) d.push_back(y);
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	while (b.size() > 0 && c.size() > 0)
	{
		ans += b.back() + c.back();
		b.pop_back(); c.pop_back();
	}
	//cout << "Part 1: " << ans << endl;
	for (int i = 0; i < a.size(); i++)
	{
		ans += a[i];
		cnt++;
	}
	//cout << "Part 2: " << ans << endl;
	while (b.size() > 0)
	{
		d.push_back(b.back());
		b.pop_back();
	}
	while (c.size() > 0)
	{
		d.push_back(c.back());
		c.pop_back();
	}
	sort(d.begin(), d.end());
	while (cnt > 0 && d.size() > 0)
	{
		cnt--;
		ans += d.back();
		d.pop_back();
	}
	cout << ans << endl;

	return 0;
}


