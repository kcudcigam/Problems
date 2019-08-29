#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("deal.in");
ofstream cout("deal.out");

long long cashier[20005];
long long me[20005];
int MOD = 1000000007;

struct xxxx {
	int a, b, c;
	const bool operator<(const xxxx other) const { return a > other.a; }
};

int main() {
	me[0] = 1; cashier[0] = 1;
	int n, X, mx = 0; cin >> n >> X;
	vector<xxxx> xes;
	for(int i=0; i<n; i++) {
		int ai, bi, ci; cin >> ai >> bi >> ci; mx = max(mx, ai);
		bi = min(bi, 20000/ai+1); ci = min(ci, 20000/ai+1);
		xxxx a; a.a = ai; a.b = bi; a.c = ci;
		xes.push_back(a);
	}
	sort(xes.begin(), xes.end());
	for(int i=0; i<n; i++) {
		int ai = xes[i].a, bi = xes[i].b, ci = xes[i].c;
		for(int j=X+ai-1; j>=ai; j--)
			for(int v=1; v<=bi && j-v*ai >= 0; v++) me[j] = (me[j]+me[j-v*ai]) % MOD;
		for(int j=X+ai-1; j>=ai; j--) 
			for(int v=1; v<=ci && j-v*ai >= 0; v++) cashier[j] = (cashier[j]+cashier[j-v*ai]) % MOD;
	}
	long long ans = 0;
	for(int t=X; t<=X+mx-1; t++) ans = (ans+me[t]*cashier[t-X])%MOD;
	cout << ans << endl;
}
	
