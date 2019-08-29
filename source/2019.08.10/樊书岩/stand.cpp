#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define LD long double
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {
		if(c == '-') f = -f;
	}
	for(; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {write(x); putchar(sp);}
int n, m, a, b, c, d, e, l[260], r[260], con[55], mx[55];
LL poly_eval(int x) {
	return 1ll * a * x + 1ll * b * x * x + 1ll * c * x * x * x + 1ll * d * x * x * x * x + 1ll * e * x * x * x * x * x;
}
vector<int> le, ri;
map<int, int> cons;
int cont(int x, LL has, LL &newhas) {
	newhas = has;
	int ans = 0;
	_rep(i, 1, n) {
		if(l[i] <= x && x <= r[i]) {
		//	cout << ((has >> (i - 1)) & 1) << endl;
			if(((has >> (i - 1)) & 1) == 0) {
				ans++;
				newhas |= (1 << (i - 1));
		//		cout << ans << " " << newhas << endl;
			}
		}
	}
	return ans;
}
LL final = 0;
void brute_force(int n, LL ans, LL has, LL use) {
	cout << n << " " << ans << " " << has << " " << use << endl;
	if(has == (1 << n) - 1) {
		final = max(final, ans);
		return;
	}
	_rep(i, 1, m) {
		if(use & (1 << (i - 1)) == (1 << (i - 1))) {
			LL newhas;
			int s = cont(i, has, newhas);
		//	cout << n << " " << ans << " " << newhas << " " << use << " " << s << " " << i << endl;
			brute_force(n, ans + s, newhas, use & (~ 1 << (i - 1))); 
		}
	}
}
int sub1 = 1;
int main() {
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	read(n); read(m);
	read(a); read(b); read(c); read(d); read(e);
	_rep(i, 1, n) {
		read(l[i]); read(r[i]);
		sub1 = (sub1 & (l[i] == 1) & (r[i] == m));
		le.push_back(l[i]); ri.push_back(r[i]);
	}
	sort(le.begin(), le.end()); sort(ri.begin(), ri.end());
	int ans = 0, mxx = 0;
	int lptr = 0, rptr = 0;
	while(lptr < n) {
		int lv = le[lptr], rv = ri[rptr];
		if(lv <= rv) {
			con[lv] = ans + 1;
			mx[lv] = max(mxx, ans + 1);
			ans++;
			mxx = mx[lv];
			lptr++;
		} else if(lv > rv + 1) {
			con[rv + 1] = ans - 1;
			mx[rv + 1] = mxx;
			ans--;
			rptr++;
		} else {
			con[lv] = ans;
			mx[lv] = max(mxx, ans);
			lptr++; rptr++;
		}
	}
	while(rptr < n) {
		con[ri[rptr] + 1] = ans - 1;
		ans--;
		mx[ri[rptr] + 1] = mxx;
		rptr++;
	}
	_rep(i, 1, m) {
		if(!con[i]) {
			con[i] = con[i - 1];
			mx[i] = max(mx[i], mx[i - 1]);
		}
		cout << con[i] << endl;
	}
	
//	while(!le.empty()) {
//		int lv = le.front(), rv = ri.front();
//		cout << lv << " " << rv << " " << ans << endl;
//		if(lv < rv) {
//			con.insert(make_pair(lv, ans + 1));
//			ans++;
//			le.erase(le.begin());
//		} else if(lv > rv) {
//			con.insert(make_pair(rv, ans - 1));
//			ans--;
//			ri.erase(ri.begin());
//		} else {
//			con.insert(make_pair(lv, ans));
//			le.erase(le.begin()); ri.erase(ri.begin());
//		}
//	}
//	while(!ri.empty()) {
//		con.insert(make_pair(ri.front(), ans - 1)); ans--;
//		ri.erase(ri.begin());
//	}
//	_rep(i, 1, m) {
//		map<int, int> :: iterator it = con.upper_bound(4);
//		pair<int, int> p = *it;
//		cout << p.second << endl;	
//	}
	
	if(sub1) {
		writesp(poly_eval(n));
		return 0;
	} else if(n <= 50 && m <= 50) {
	//	bf();
	///	brute_force(n, 0, 0, (1 << (m + 1)) - 1);
	//	writesp(final);
		int remain[55] = {0}, remains = n;
		LL ans = 0;
		while(remain) {
			int maxi = 0, maxc = 0;
			_rep(i, 1, m) {
				if(maxc < con[i]) {
					maxi = i;
					maxc = con[i];
				}
			} 
			ans += poly_eval(maxc);
			_rep(i, 1, n) {
				if(l[i] <= maxi && maxi <= r[i] && !remain[i]) {
					remain[i] = 1;
					remains--;
					_rep(j, 1, m) {
						con[j]--;
					}
				}
			}
		}
		writesp(ans);
	} else {
		
	}
	return 0;
}
