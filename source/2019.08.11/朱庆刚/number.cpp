#include<cstdio>
#include<string>
using namespace std;

bool get_bit(int x, int i) {
	return (x >> i) & 1;
}

bool judge(long long n) {
	bool t[10] = {0};
	int tot = 0;
	for(;n;) {
		int now = n % 10;
		tot += !t[now];
		t[now] = true;
		n /= 10;
	}
	return tot <= 2;
}

int f(long long n) {
	if(judge(n)) return 1;
	long long t = n;
	int cnt = 0;
	for(;t;) {
		++cnt;
		t /= 10;
	}
	for(int i = 1; i <= cnt; ++i) { // 喜欢数长度 
		for(int j = 1; j < 10; ++j) {
			long long tmp = 0;
			for(int k = 0; k < i; ++k) {
				tmp = tmp * 10 + j;
			}
			if(tmp > n) break;
			//printf("%lld \n", tmp);
			if(judge(n - tmp)) {
				return 2;
			}
		}
		for(int j = 1; j < (1 << i) - 1; ++j) { // 喜欢数构成 2
			for(int k = 0; k < 10; ++k) {
				for(int l = k; l < 10; ++l) {
					long long tmp = 0;
					if(get_bit(j, 0) && k == 0) break;
					if(!get_bit(j, 0) && l == 0) continue;
					if(k == l) continue;
					for(int m = 0; m < i; ++m) {
						tmp *= 10;
						tmp += get_bit(j, m) ? k : l;
					}
					if(tmp > n) continue;
					//printf("%lld \n", tmp);
					if(judge(n - tmp)) {
						return 2;
					}
				}
			}
		}
	}
	return 3;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(;t--;) {
		long long n;
		scanf("%lld", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
