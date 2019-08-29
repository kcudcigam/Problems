#include<bits/stdc++.h>
using namespace std;
int q, n, p, f[10000010];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	
	scanf("%d", &q);
	f[1] = 0;
	f[2] = 2;
	while(q--){
		scanf("%d%d", &n, &p);
		for(int i = 3; i <= n; ++i){
			if(i & 1) {
				f[i] = (long long)(f[i - 1] * i + i * (i - 1)) % p;
			} else {
				f[i] = (long long)(f[i - 1] * i + i * (i - 1) - i + 2) % p;
			}
		}
		printf("%d\n", f[n]);
	}
	return 0;
}
