#include <bits/stdc++.h>
#define ll long long
#define rui register unsigned int
#define R register 
using namespace std;
const int N = 505;
struct node{
	int pos, val, rp;
}e[N]; 
bool cmp(node a, node b){
	return (a.pos < b.pos) || (a.pos == b.pos && a.val > b.val); 
}
int g[10];
ll ans, u;
int o;
inline ll func(short int x){
	ans = 0;
	for (u = x, o = 1; o <= 5; o++, u *= x) ans += u*g[o];
	return ans;
}
int n, m, p, las, lasi;
int l[N], r[N];
short int b[N][N][N];
ll f[N][N];
int main(){
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	R int i, j, k, x, y;
	cin >> n >> m;
	for (i = 1; i <= 5; i++) cin >> g[i];
	for (i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		e[i*2-1].pos = l[i];
		e[i*2-1].val = i;
		e[i*2].pos = r[i];
		e[i*2].val = -i;
	}
	sort(e+1, e+2*n+1, cmp);
	for (i = 1; i <= 2*n; i++)
		if (e[i].pos == las) e[i].rp = lasi;
		else{
			e[i].rp = i;
			las = e[i].pos;
			lasi = i;
		}
	for (i = 1; i <= 2*n; i++)
		if (e[i].val > 0){
			for (j = i+1; j <= 2*n; j++)
				if (e[j].val+e[i].val == 0){
					p = j;
					break;
				}
			for (x = 1; x <= e[i].rp; x++)
				for (y = e[p].rp; y <= 2*n; y++){
					b[x][y][e[i].rp]++;
					b[x][y][e[p].rp+1]--;
				}
		}
	for (i = 1; i <= 2*n; i++)
		for (j = i; j <= 2*n; j++)
			for (k = i; k <= j; k++)
				b[i][j][k] = b[i][j][k-1]+b[i][j][k];
	for (i = 1; i <= 2*n; i++) f[i][1] = b[i][i][i];
	for (k = 2; k <= 2*n; k++)
		for (i = 1; k+i-1 <= 2*n; i++)
			for (j = i; j <= i+k-1; j++)
				f[i][i+k-1] = max(f[i][i+k-1], func(b[i][i+k-1][j])+f[i][j-i]+f[j+1][i+k-1-j]);
	cout << f[1][2*n] << endl;
	return 0;
}


