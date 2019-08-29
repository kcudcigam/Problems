#include<bits/stdc++.h>
using namespace std;
int x[16];
int head[200001], ver[10000001], nxt[10000001], size;
void addedge(int a, int b, int c, int d) {
	if (a == 0 && b == 0 && c == 0 && d == 0) return;
	int a0 = a, b0 = b, c0 = c, d0 = d;
	bool stop = 1;
	if (a0) {
		--a0;
		if (a0) {
			if (!a0) a0 = x[a0];
			else if (!b0) b0 = x[a0];
			else if (!c0) c0 = x[a0];
			else if (!d0) d0 = x[a0];
		}
		else stop = 0;
	}
	if (b0) {
		--b0;
		if (b0) {
			if (!a0) a0 = x[b0];
			else if (!b0) b0 = x[b0];
			else if (!c0) c0 = x[b0];
			else if (!d0) d0 = x[b0];
		}
		else stop = 0;
	}
	if (c0) {
		--c0;
		if (c0) {
			if (!a0) a0 = x[c0];
			else if (!b0) b0 = x[c0];
			else if (!c0) c0 = x[c0];
			else if (!d0) d0 = x[c0];
		}
		else stop = 0;
	}
	if (d0) {
		--d0;
		if (d0) {
			if (!a0) a0 = x[d0];
			else if (!b0) b0 = x[d0];
			else if (!c0) c0 = x[d0];
			else if (!d0) d0 = x[d0];
		}
		else stop = 0;
	}
	int u = 20*(20*(20*a0+b0)+c0)+d0, v = 20*(20*(20*a+b)+c)+d;
	if (!stop) ver[++size] = v, nxt[size] = head[u], head[u] = size;
}
int degree[200001];
int sz;
void topology() {
	for (int i = 1; i <= size; i++) ++degree[ver[i]];
	queue<int> zero;
	for (int i = 0; i <= 200000; i++)
		if (!degree[i]) zero.push(i);
	while (zero.size()) {
		int u = zero.front();
		zero.pop();
		++sz;
		for (int i = head[u]; i; i = nxt[i]) {
			--degree[ver[i]];
			if (!degree[ver[i]]) zero.push(ver[i]);
		}
	}
}
int main(){
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	int k;
	cin >> k;
	for (int i = 1; i < k; i++) cin >> x[i];
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			for (int m = 0; m <= k; m++)
				for (int n = 0; n <= k; n++)
					addedge(i, j, m, n);
	topology();
	cout << 200001-sz << endl;
	return 0;
}

