#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;
long long y, n, m;
long long a, cnt;
set<pair<long long, long long> >s;
void dfs(int pos, int last) {
	if(pos > a) {
		s.insert(make_pair(last, n));
		++cnt;
		if(cnt == y) {
			printf("%lld %d\n", n, s.size());
			for(set<pair<long long, long long> >::iterator i = s.begin(); i != s.end(); ++i) {
				printf("%lld %lld\n", (*i).first, (*i).second);
			}
			exit(0);
		}
		return;
	}
	for(long long i = last + 1; i <= n - 1 - a + pos; ++i) {
		s.insert(make_pair(last, i));
		dfs(pos + 1, i);
	}
}

/*
long long nowy, nowi;
long long f(long long a) {
	long long res = 1;
	for(int i = n - a - 1; i <= n - 2; ++i) {
		res *= i;
	}
	printf(">>%lld\n", res);
	for(int i = 2; i <= a; ++i) {
		res /= i;
	}
	return res;
}
*/
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	scanf("%lld", &y);
	n = (int)ceil(log(y) / log(2)) + 2;
	/*
	for(long long i = 0; i <= n - 2; ++i) {
		long long fi = f(i);
		if(nowy + fi > y) {
			nowi = i - 1;
			break;
		}
		nowy += fi;
	}
	*/
	for(long long i = 0; i <= n - 2; ++i) {
		a = i;
		dfs(1, 1);
	}
	return 0;
}
