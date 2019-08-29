#include<iostream>
#include<cstdio>
using namespace std;
int n,q,f[500005],a[1001][1001],b[500005],h[500005];
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++ i){
		f[i] = i;
		a[i][1] = i;
		b[i] = 1;
	}
	for (int i = 1; i <= q; ++ i){
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if (k == 1){
			int s = b[f[y]];
			for (int j = 1; j <= s; ++ j){
				a[f[x]][j+b[f[x]]] = a[f[y]][j];
				f[a[f[y]][j]] = f[x];
			}
			b[f[x]] += s;
		}
		else{
			for (int j = 1; j <= b[f[x]]; ++ j){
				h[a[f[x]][j]] += y;
			}
		}
	}
	for (int i = 1; i <= n; ++ i)
		printf("%d ",h[i]);
	return 0;
}
