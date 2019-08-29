#include <fstream>
using namespace std;

ifstream cin("cake.in");
ofstream cout("cake.out");

long long DP[305][305];
int MOD = 1000000007;

int main() {
	int N, M; cin >> N >> M;
	DP[1][1] = 1;
	for(int n=1; n<=N; n++)
		for(int m=1; m<=M; m++) {
			for(int i=1; i<n; i++) DP[n][m] = (DP[n][m] + DP[i][m]*DP[n-i][m]) % MOD;
			for(int i=1; i<m; i++) DP[n][m] = (DP[n][m] + DP[n][i]*DP[n][m-i]) % MOD;
		}
	cout << DP[N][M] << endl;
}
