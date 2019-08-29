#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
queue<int>Q;
int X,Y,Z;
int Num,n,m;
int p[500005],f[500005],a[500005],c[500005];
int tot,cnt;
int x,y,z,book[500005],pd[500005],h[500005];
int dis[500005],das[500005];
struct xym{
	int Y,Z;
}b[500005];
void Add(int u,int v,int w){
	p[++tot] = f[u];
	f[u] = tot;
	a[tot] = v;
	c[tot] = w;
}

void spfa(int x){
	Q.push(x);
	while (!Q.empty()){
		X = Q.front() ;
		Q.pop() ;
		for (int i = f[X]; i ; i = p[i])
			if (book[a[i]]<=n && a[i] != h[X]){
				Y = a[i];
				Z = c[i];
				if (dis[X]+Z < dis[Y]){
					das[Y] = dis[Y];
					dis[Y] = dis[X]+Z;
				}
				else
					if (dis[X]+Z < das[Y])
						das[Y] = dis[X]+Z;
				book[Y] ++;
				h[Y] = X;
				Q.push(Y);
			}
	}
	return;
}
/*
int cmp(xym a,xym b){
	return a.Z < b.Z;
}
void Search(int x){
	Q.push(x);
	while (!Q.empty()){
		X=Q.front() ;
		Q.pop() ;
		cnt = 0;
		for (int i = f[X]; i; i = p[i]){
				b[++cnt].Y=a[i];
				b[cnt].Z=c[i];
			}
		sort(b+1,b+1+cnt,cmp);
		for (int i = 1; i <= cnt; ++ i){
			if (book[b[i].Y]){
				Y=b[i].Y;
				Z=b[i].Z;
				book[Y] ++;
				if (dis[X]+Z <= dis[Y]){
					das[Y] = dis[Y];
					dis[Y] = dis[X]+Z;
				}
				else
					if (dis[X]+Z < das[Y])
						das[Y] = dis[X]+Z;
				Q.push(Y);
			}
		}
	}
}*/
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&Num);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++ i){
		scanf("%d%d%d",&x,&y,&z);
		if (x != y){
			pd[x]++;
			pd[y]++;
			Add(x,y,z);
			Add(y,x,z);
		}
	}
	memset(dis,127,sizeof(dis));
	memset(das,127,sizeof(dis));
	dis[1] = 0;
	das[1] = 0;
	h[1] = 0;
	book[1] = n+1;
	spfa(1);
	for (int i = 1; i <= n; ++ i){
		if (das[i]!=2139062143&&pd[i]!=1)
			printf("%d ",das[i]);
		else
			printf("-1 ");
	}
	return 0;
}
