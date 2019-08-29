#include<cstdio>
using namespace std;
int n,m,q;
int Ans;
int x,y,z;
int f[300005],fir[300005],p[300005];
int a[300005];
int tot;
void Add(int u,int v){
	f[++tot] = fir[u];
	fir[u] = tot;
	p[tot] = v;
}
void Revise(int x,int y){
	for (int i = fir[x]; i; i = f[i]){
		int s = p[i];
		a[p[i]] += y;
	}
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= m; ++ i){
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	for (int i = 1; i <= q; ++ i){
		scanf("%d",&x);
		if (x == 1){
			scanf("%d%d",&y,&z);
			a[y] += z;
			Revise(y,z);
		}
		else{
			scanf("%d",&y);
			printf("%d\n",a[y]);
		}
	}
	return 0;
}


