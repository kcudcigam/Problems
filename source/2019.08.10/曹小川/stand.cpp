#include<bits/stdc++.h>
#define N 261
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (!f) c = -c;
}
long long  n, m, ans;
long long c1, c2, c3, c4, c5;
inline long long g(long long x){
	return c1 * x + c2 * x * x + c3 * x * x * x + c4 * x * x * x * x + c5 * x * x * x * x * x;
}
int a[N << 1], hsh[10000010];
struct bjzx{
	long long l, r;
}yzp[N], jojo[N];
long long cf[N];
long long qz[N];
vector <int> bj[N];
long long stands;
bool cmp(const bjzx &a, const bjzx &b){
	if (a.l != b.l) return a.l < b.l;
	else return a.r > b.r;
}
int main(){
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	read(n), read(m);
	read(c1), read(c2), read(c3), read(c4), read(c5);
	for (int i = 1; i <= n; ++i){
		read(yzp[i].l), read(yzp[i].r);
		a[i * 2 - 1] = yzp[i].l;
		a[i << 1] = yzp[i].r;
	}
	sort(a + 1, a + (n << 1) + 1);
	int j = 0;
	for (int i = 1; i <= n << 1; i++)
		if (a[i] != a[i - 1]){
			++j;
			hsh[a[i]] = j;
		}
	for (int i = 1; i <= n; ++i){
		jojo[i].l = hsh[yzp[i].l], jojo[i].r = hsh[yzp[i].r];
		++cf[jojo[i].l], --cf[jojo[i].r + 1];
		bj[jojo[i].l].push_back(i); 
	}
	sort(jojo + 1, jojo + 1 + n, cmp);
	stands = n;
	while (1){
		long long maxn = LONG_LONG_MIN, wz = 0;
		memset(qz, 0, sizeof qz);
		for (int i = 1; i <= j; ++i){
			qz[i] = qz[i - 1] + cf[i];
			if (qz[i] > maxn){
				maxn = qz[i];
				wz = i;
			}
		}
		ans += g(maxn);
		stands -= maxn;
		if (stands == 0) break;
		for (int i = 1; i <= wz; ++i){
			while (bj[i].size() && jojo[bj[i][0]].r >= wz){
				cf[jojo[bj[i][0]].r + 1]++;
				cf[i]--;
				bj[i].erase(bj[i].begin());
			}
		}
	}
	cout << ans << endl;
	return 0;
}
