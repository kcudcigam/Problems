#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10005;
ll Y;
int n, m;
int x[N], y[N];
int main(){
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	cin >> Y;
	n = (int) log2(Y)+3;
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++){
			m++;
			x[m] = i;
			y[m] = j;
		}
	for (int i = 2; i < n; i++, Y /= 2)
		if (Y%2){
			m++;
			x[m] = i;
			y[m] = n;
		}
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= m; i++)
		cout << x[i] << ' ' << y[i] << endl;
	return 0;
}


