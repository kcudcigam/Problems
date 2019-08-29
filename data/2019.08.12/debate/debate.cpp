# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int N = 1000010;
int n, val[4][N], num[4], ans;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	read(n);
	ans = 0;
	for (int i = 1; i <= n; i++){
		int x, v, c;
		read(x); read(v);
		if (x == 11) c = 0;
		if (x == 10) c = 1;
		if (x == 01) c = 2;
		if (x == 00) c = 3;
		val[c][++num[c]] = v;
	}
	sort(val[1] + 1, val[1] + num[1] + 1, cmp);
	sort(val[2] + 1, val[2] + num[2] + 1, cmp);
	int mn = min(num[1], num[2]);
	for (int i = 1; i <= mn; i++)
		ans = ans + val[1][i] + val[2][i];
	for (int i = mn + 1; i <= num[1]; i++) val[3][++num[3]] = val[1][i];
	for (int i = mn + 1; i <= num[2]; i++) val[3][++num[3]] = val[2][i];
	sort(val[3] + 1, val[3] + num[3] + 1, cmp);
	for (int i = 1; i <= num[0]; i++) 
		ans = ans + val[0][i] + val[3][i];
	printf("%d\n", ans);
	return 0;
}


