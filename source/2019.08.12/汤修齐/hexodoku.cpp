#include <bits/stdc++.h>

using namespace std;

const int I[] = { 1, 3, 8, 14, 19, 25, 30 },
		L[7][6] = {{ 3, 8, 0, 0, 0, 0 },
			{ 1, 4, 9, 14, 19, 0 },
			{ 2, 5, 10, 15, 20, 15 },
			{ 6, 11, 16, 21, 26, 0 },
			{ 7, 12, 17, 22, 27, 30 },
			{ 13, 18, 23, 28, 31, 0 },
			{ 24, 29, 0, 0, 0, 0 }},
		R[7][6] = {{ 19, 25, 0, 0, 0, 0 },
			{ 8, 14, 20, 26, 30, 0 },
			{ 3, 9, 15, 21, 27, 31 },
			{ 4, 10, 16, 22, 28, 0 },
			{ 1, 5, 11, 17, 23, 29 },
			{ 2, 6, 12, 18, 24, 0 },
			{ 7, 13, 0, 0, 0, 0 }},
		C[7][7] = {{ 1, 2, 4, 5, 6, 10, 11 },
			{ 3, 4, 8, 9, 10, 14, 15 },
			{ 6, 7, 11, 12, 13, 17, 18 },
			{ 10, 11, 15, 16, 17, 21, 22 },
			{ 14, 15, 19, 20, 21, 25, 26 },
			{ 17, 18, 22, 23, 24, 28, 29 },
			{ 21, 22, 26, 27, 28, 30, 31 }};
const int poi[] = { 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6 },
		pol[] = {0, 1, 2, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 4, 5 },
		por[] = {0, 4, 5, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 1, 2 },
		poc[32][3] = { { -1, -1, -1 }, { 0, -1, -1 }, { 0, -1, -1 }, { 1, -1, -1 }, { 0, 1, -1 }, { 0, -1, -1 }, { 0, 2, -1 }, { 2, -1, -1 }, { 1, -1, -1 }, { 1, -1, -1 }, { 0, 1, 3 }, { 0, 2, 3 }, { 2, -1, -1 }, { 2, -1, -1 }, { 1, 4, -1 }, { 1, 3, 4 }, { 3, -1, -1 }, { 2, 3, 5 }, { 2, 5, -1 }, { 4, -1, -1 }, { 4, -1, -1 }, { 3, 4, 6 }, { 3, 5, 6 }, { 5, -1, -1 }, { 5, -1, -1 }, { 4, -1, -1 }, { 4, 6, -1 }, { 6, -1, -1 }, { 5, 6, -1 }, { 5, -1, -1 }, { 6, -1, -1 }, { 6, -1, -1 } };

bool used_i[7][40], used_l[7][40], used_r[7][40], used_c[7][40];
int n, k, a[40];
int cnt, ans[40];
bool END;

inline bool check(int x, int c){
	bool re = used_i[poi[x]][c] || used_l[pol[x]][c] || used_r[por[x]][c];
	if (re) return 0;
	for (int i = 0; i < 3 && poc[x][i] != -1; i++)
		if (used_c[poc[x][i]][c]) return 0;
	return 1;
}

inline void Change(int x, int c, int k){
	used_i[poi[x]][c] = used_l[pol[x]][c] = used_r[por[x]][c] = k;
	for (int i = 0; i < 3 && poc[x][i] != -1; i++)
		used_c[poc[x][i]][c] = k;
}

void dfs(int x){
	if (x > 31){
		cnt++;
		if (cnt == n){
			for (int i = 1; i <= 31; i++) ans[i] = a[i];
			END = 1;
		}
		return;
	}
	if (a[x]){
		dfs(x + 1);
		return;
	}
	
	for (int i = 1; i <= k && !END; i++)
		if (check(x, i)){
			Change(x, i, 1);
			a[x] = i;
			dfs(x + 1);
			a[x] = 0;
			Change(x, i, 0);
		}
}

int main(){
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= 31; i++) scanf("%d", a + i);
	for (int i = 0; i < 6; i++)
		for (int j = I[i]; j < I[i + 1]; j++)
			used_i[i][a[j]] = 1;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6 && L[i][j]; j++)
			used_l[i][a[L[i][j]]] = 1;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6 && L[i][j]; j++)
			used_l[i][a[L[i][j]]] = 1;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6 && R[i][j]; j++)
			used_r[i][a[R[i][j]]] = 1;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			used_c[i][a[C[i][j]]] = 1;
	dfs(1);
	if (cnt >= n){
		printf("Found\n");
		for (int i = 1; i <= 31; i++) printf("%d ", ans[i]);
		printf("\n");
	} else printf("No way\n");
	
	return 0;
}
