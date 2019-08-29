#include <bits/stdc++.h>
#define Maxn	500500
using namespace std;

bool cmp(int p, int q){ return p > q; }

priority_queue <int, vector<int>, less<int> > que;
int b[Maxn], c[Maxn], val[Maxn];
string st;
int n, Ans, c1, c2, c3;

int main(){
	freopen("debate.in", "r", stdin), freopen("debate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> st >> val[i];
		if (st == "11") c1++, Ans += val[i];
		if (st == "10") b[++c2] = val[i];
		if (st == "01") c[++c3] = val[i];
		if (st == "00") que.push(val[i]);
	}
	sort(b + 1, b + c2 + 1, cmp), sort(c + 1, c + c3 + 1, cmp);
	int ch_bc = min(c2, c3);
	for (int i = 1; i <= ch_bc; i++)
		Ans += b[i] + c[i];
	if (c2 < c3){
		for (int i = c2 + 1; i <= c3; i++)
			que.push(c[i]);
	} else {
		for (int i = c3 + 1; i <= c2; i++)
			que.push(b[i]);
	}
	while (que.size() && c1--)
		Ans += que.top(), que.pop();
	cout << Ans << '\n';
	return 0;
}
