#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL	
	#define eprintf(...) fprintf(stderr , __VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<ll , ll> pll;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
const int N = 1e6 + 10;

int n , timer , k , ans;
int ins[N] , dfn[N] , low[N] , w[N] , lab[N] , nx[N];
stack< int > s;

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
} 
inline int get_state(int a , int b , int c , int d) {
	return a + (k + 1) * b + (k + 1) * (k + 1) * c + (k + 1) * (k + 1) * (k + 1) * d;	
}
inline bool operate(int &a , int &b , int &c , int &d) {
	int cnt = 0;
	if (a > 0) {
		--a;
		if (a > 0) {
			if (!b) b = w[a];
			else if (!c) c = w[a];
			else if (!d) d = w[a]; 
		} else ++cnt;
	}
	if (b > 0) {
		--b;
		if (b > 0) {
			if (!a) a = w[b];
			else if (!c) c = w[b];
			else if (!d) d = w[b];
		} else ++cnt;
	} 
	if (c > 0) {
		--c;
		if (c > 0) {
			if (!a) a = w[c];
			else if (!b) b = w[c];
			else if (!d) d = w[c];
		} else ++cnt;
	}
	if (d > 0) {
		--d;
		if (d > 0) {
			if (!a) a = w[d];
			else if (!b) b = w[d];
			else if (!c) c = w[d];
		} else ++cnt;
	}
	return cnt >= 1;
}
inline void tarjan(int u) {
	dfn[u] = low[u] = ++timer;
	ins[u] = true;
	s.push(u);
	if (!dfn[nx[u]] && nx[u]) {
		tarjan(nx[u]);
		chkmin(low[u] , low[nx[u]]);
	} else if (ins[nx[u]]) chkmin(low[u] , dfn[nx[u]]);
	if (dfn[u] == low[u]) {
		int v = 0 , sz = 0;
		do {
			v = s.top();
			s.pop();
			ins[v] = false;
			lab[v] = true;
			++sz;
		} while (v != u);
		if (sz == 1) lab[u] = false;
	}
}
inline int get(int u) {
	if (!u) return 0;
	if (lab[u]) return 1;
	if (get(nx[u])) return lab[u] = 1;
	else return 0;	
}

int main() {
	
	#ifndef evenbao
	freopen("bob.in" , "r" , stdin);
	freopen("bob.out" , "w" , stdout);
	#endif
	
	read(k);
	for (int i = 1; i < k; ++i) read(w[i]);
	for (int a1 = 0; a1 <= k; ++a1) {
		for (int a2 = 0; a2 <= k; ++a2) {
			for (int a3 = 0; a3 <= k; ++a3) {
				for (int a4 = 0; a4 <= k; ++a4) {
					int A1 = a1 , A2 = a2 , A3 = a3 , A4 = a4;
					if (!A1 && !A2 && !A3 && !A4) continue;
					int now = get_state(A1 , A2 , A3 , A4);
					if (operate(A1 , A2 , A3 , A4)) {
						int to = get_state(A1 , A2 , A3 , A4);
						nx[now] = to;
					}
				}
			}
		}
	}
	int M = get_state(k , k , k , k);
	for (int i = 1; i <= M; ++i)
		if (!dfn[i]) tarjan( i );
	for (int i = 1; i <= M; ++i) {
		if (get( i )) 
			++ans;
	}
	printf("%d\n" , ans);
	
	return 0;
}

