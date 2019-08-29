#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
vector<int> v[50];
int ma[50][50];
int vis[50][50];
int ans[50];
int n;
int k;

void dfs(int i) {
	if (i == 32) {
		n--;
		if (n == 0) {
			cout << "Found\n";
			for (int i = 1;i <= 31; i++) cout << ans[i] << ' ';
			exit(0);
		}
		return;
	}
	if (ans[i] == 0)
	for (int j = 1;j <= k; j++) {
		if (vis[i][j]) continue;
		ans[i] = j;
		for (int p = 0;p < (int)v[i].size(); p++)
			vis[v[i][p]][j]++;
		//cout << i << ' ' << ans[i] << endl;
		dfs(i+1);
		for (int p = 0;p < (int)v[i].size(); p++)
			vis[v[i][p]][j]--;
		ans[i] = 0;
	}
	else {
		if (vis[i][ans[i]]) return;
		for (int p = 0;p < (int)v[i].size(); p++)
			vis[v[i][p]][ans[i]]++;
		dfs(i+1);
		}
}

void prit(int x) {
	for (int j = 0;j < (int)v[x].size(); j++) 
	cout << v[x][j] << ' ';
	cout << endl;
}

int main() {
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	ma[1][3] = 1, ma[1][4] = 2;
	int num = 2;
	for (int i = 2;i <= 6; i++) {
		int j = 1;
		if (i % 2 == 0) j = 2;
		for (; j <= 6; j++) ma[i][j] = ++num;
	}
	ma[7][3] = 30, ma[7][4] = 31;
	for (int i = 1;i <= 7; i++) {
		for (int j = 1;j <= 6; j++) {
			if (ma[i][j] == 0) continue;
			for (int k = j + 1;k <= 6; k++) {
				if (ma[i][k] == 0) break;
				v[ma[i][j]].push_back(ma[i][k]);
			}
			int p = 0;
			for (int k = i + 1;k <= 7; k++) {
				if (k & 1) p++;
				if (j - p <= 0 || ma[k][j-p] == 0) break;
				v[ma[i][j]].push_back(ma[k][j-p]);
			}
			p = 0;
			for (int k = i + 1;k <= 7; k++) {
				if (k % 2 == 0) p++;
				if (j + p > 6 || ma[k][j+p] == 0) break;
				v[ma[i][j]].push_back(ma[k][j+p]);
			}
		}
	}
	int a[] = {5,9,12,16,20,23,27};
	for (int i = 0;i < 7; i++) {
		int y = a[i];
		int tmp[] = {y-6, y-5, y-1,y,y+1,y+5,y+6};
		if (y == 5) tmp[0] = 1, tmp[1] = 2;
		else if (y == 27) tmp[5] = 30, tmp[6] = 31;
		for (int k = 0;k < 7; k++) {
			for (int p = k + 1;p < 7; p++) {
				v[tmp[k]].push_back(tmp[p]);
			}
		}
	}
	for (int i = 1;i <= 31; i++) {
		sort(v[i].begin(), v[i].end());
		unique(v[i].begin(), v[i].end());
//		prit(i);
	}
	cin >> k >> n;
	for (int i = 1;i <= 31; i++) cin >> ans[i];
	dfs(1);
	cout << "No way\n";
	return 0;
}
