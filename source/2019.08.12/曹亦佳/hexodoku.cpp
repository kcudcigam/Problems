#include<bits/stdc++.h>
using namespace std;

const int h[32] = {0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7};
const int r[32] = {0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5};
const int l[32] = {0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6};
const int w[32][3] = {0,0,0,1,0,0,1,0,0,2,0,0,1,2,0,1,0,0,1,3,0,3,0,0,2,0,0,2,0,0,1,2,4,1,3,4,3,0,0,3,0,0,2,5,0,2,4,5,4,0,0,3,4,6,3,6,0,5,0,0,5,0,0,4,5,7,4,6,7,6,0,0,6,0,0,5,0,0,5,7,0,7,0,0,6,7,0,6,0,0,7,0,0,7,0,0};
int n, k, cnt, a[50];
bool fh[10][50], fl[10][50], fr[10][50], fw[10][50];

bool chck(int x, int y) {
	if (fh[h[x]][y] || fr[r[x]][y] || fl[l[x]][y]) return false;
	for (int i = 0; i < 3; ++i) {
		if (w[x][i] == 0) break;
		if (fw[w[x][i]][y]) return false;
	}
	return true;
}

void fz(int x, int y, bool f) {
	fh[h[x]][y] = fr[r[x]][y] = fl[l[x]][y] = f; 
	for (int i = 0; i < 3; ++i) {if (w[x][i] == 0) break; fw[w[x][i]][y] = f;}
}

void dfs(int x) {
	if (a[x]) {dfs(x + 1); return;}
	if (x == 32) {cnt++; return;}
	for (int i = 1; i <= k; ++i) {
		if (!chck(x, i)) continue;
		fz(x, i, true); a[x] = i;
		dfs(x + 1);
		if (cnt == n) return;
		fz(x, i, false);  a[x] = 0;
	}
}

int main(){
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	cin >> k >> n;
	if (k <= 7) {cout << "No way" << endl; return 0;}
	
	for (int i = 1; i <= 31; ++i) {
		cin >> a[i];
		if (a[i] == 0) {fz(i, a[i], true); continue;}
		if (a[i] > k || !chck(i, a[i])) {cout << "No way" << endl; return 0;}
		else fz(i, a[i], true); 
	}
	
	dfs(1);
	if (cnt < n) {cout << "No way" << endl; return 0;}
	
	cout << "Found" << endl;
	for (int i = 1; i < 31; ++i) cout << a[i] << " ";
	cout << a[31] << endl;

	return 0;
}
/*
8 1
1 2 1 0 0 0 0 2 0 0 7 1 0 0 0 0 0 0 2 0 0 0 0 0 8 0 7 0 0 0 8
1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8
7 100000
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/


