#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 400010;
int n, a[MAXN], b[MAXN];
priority_queue<int>q0, q1;

int main(){
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout); 
	read(n);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; ++i) {
		int x, y; read(x); read(y);
		if (x == 10) cnt1++; if (x == 1) cnt2++;
		if (x == 11) cnt3++;
		a[i] = x; b[i] = y;
	}
	cnt1 += cnt3; cnt2 += cnt3;
	
	if (cnt1 < cnt2) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 11 || a[i] == 10) {ans += b[i]; continue;}
			if (a[i] == 0) q0.push(b[i]);
			else q1.push(b[i]);
		}
		for (int i = 1; i <= cnt1 - cnt3; ++i) {
			ans += q1.top(); q1.pop();
		}
		for (int i = 1; i <= cnt3; ++i) {
			int x = -1, y = -1;
			if (!q1.empty()) x = q1.top();
			if (!q0.empty()) y = q0.top();
			if (x == -1 && y == -1) break;
			if (x < y) {ans += y; q0.pop();}
			else {ans += x; q1.pop();}
		}
		
		cout << ans << endl;
	}
	else {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 11 || a[i] == 1) {ans += b[i]; continue;}
			if (a[i] == 0) q0.push(b[i]);
			else q1.push(b[i]);
		}
		for (int i = 1; i <= cnt2 - cnt3; ++i) {
			ans += q1.top(); q1.pop();
		}
		for (int i = 1; i <= cnt3; ++i) {
			int x = -1, y = -1;
			if (!q1.empty()) x = q1.top();
			if (!q0.empty()) y = q0.top();
			if (x == -1 && y == -1) break;
			if (x < y) {ans += y; q0.pop();}
			else {ans += x; q1.pop();}
		}
		
		cout << ans << endl;
	}

	return 0;
}


