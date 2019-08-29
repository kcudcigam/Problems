#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 64 + 5,M = N * N;
int cnte,x[M],y[M]; LL Y,f[N];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	int i,j;
	f[1] = 1,f[2] = 1;
	for (i = 3; i <= 63; ++i) f[i] = f[i-1] << 1;
	for (i = 2; i <= 63; ++i)
	for (j = 1; j < i; ++j) {++cnte; x[cnte] = j,y[cnte] = i;}
	cin >> Y;
	for (i = 63; i >= 1; --i) if (Y >= f[i]){ Y -= f[i]; ++cnte; x[cnte] = i,y[cnte] = 64; }
	cout << 64 << ' ' << cnte << endl;
	for (i = 1; i <= cnte; ++i) cout << x[i] << ' ' << y[i] << endl;
	return 0;
}
