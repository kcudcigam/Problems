#include<bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F3F3F3F3F

long long ans, cases, n, num, sav;

long long check(vector<long long> v)
{
	long long cnt = 0, maxi, mini;
	bool canbreak = false;
	while (true)
	{
		cnt++;
		maxi = 0; mini = INF;
		for (long long i = 0; i < v.size(); i++)
		{
			maxi = max(maxi, v[i]);
			mini = min(mini, v[i]);
		}
		if (maxi > 9) maxi = 9;
		if (mini > 9) mini = 9;
		for (long long i = 0; i < v.size(); i++)
		{
			if (v[i] >= maxi)
				v[i] -= maxi;
			else
				v[i] -= mini;
		}
		canbreak = true;
		for (long long i = 0; i < v.size(); i++)
			if (v[i] != 0)
			{
				canbreak = false;
				break;
			}
		if (canbreak) break;
	}
	return cnt;
}

void dfs(long long n, vector<long long> v)
{
	//cout << n << endl;
	//system("pause");
	if (n == 0)
	{
		while (v.size() < num) v.push_back(0);
		ans = min(ans, check(v));
		//for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
		//cout << endl;
		//cout << "Check Result: " << check(v) << endl;
		return;
	}
	for (long long i = 0; i <= 2; i++)
	{
		long long now = n % 10, nxt = n / 10;
		if (nxt >= i && now + i * 10 <= 27)
		{
			nxt -= i;
			now += i * 10;
			v.push_back(now);
			dfs(nxt, v);
			nxt += i;
			now -= i * 10;
			v.pop_back();
		}
	}
}

int main()
{
	// use long long
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> cases;
	for (long long times = 1; times <= cases; times++)
	{
		cin >> n;
		ans = INF;
		num = 0;
		vector<long long> v;
		sav = n;
		while (sav > 0)
		{
			sav /= 10;
			num++;
		}
		dfs(n, v);
		cout << ans << endl;
	}

	return 0;
}


