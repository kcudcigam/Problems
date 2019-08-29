#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

template <class T_> void read(T_ &x) {
	char ch;bool flag=false;x=0;
	while(!isdigit(ch=getchar()))
		(ch=='-')&&(flag=true);
	do{(x*=10)+=ch-'0';
	}while(isdigit(ch=getchar()));
	(flag)&&(x=-x);
}
template <class T_> void print(T_ x) {
	(x<0)&&(putchar('-'),x=-x);
	if(x>9)print(x/10);
	putchar(x%10+'0');
}

int tot=1;
int go[1000005],fir[200005],net[1000005];
ll w[1000005];

void add(int u,int v,ll va) {
	go[++tot]=v;w[tot]=va;
	net[tot]=fir[u];fir[u]=tot;
}

bool vis[200005],bo[1000005];
ll dis[200005];

int main(void) {
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	
	int Num;
	read(Num);
	
	int n,m;
	read(n);read(m);
	int x,y;
	ll len;
	for(int i=1;i<=m;++i) {
		read(x);read(y);read(len);
		add(x,y,len);add(y,x,len);
	}
	putchar('0');putchar(' ');
	for(int i=2;i<=n;++i) {
		ll ans=-1ll;
		bool flag=false;
		for(int k=fir[i];k;k=net[k]) {
			bo[k]=bo[k^1]=true;
			queue <int> q;
			q.push(i);
			memset(vis,false,sizeof vis);
			vis[i]=true;
			for(int j=1;j<=n;++j)dis[j]=LLONG_MAX/3; 
			dis[i]=0;
			while(!q.empty()) {
				x=q.front();q.pop();
				for(int e=fir[x];e;e=net[e]) {
					if(bo[e])continue;
					int y=go[e];
					if(dis[y]>dis[x]+w[e]) {
						dis[y]=dis[x]+w[e];
						if(!vis[y]) {
							vis[y]=true;
							q.push(y);
						}
					}
				}
				vis[x]=false;
			}
			bo[k]=bo[k^1]=false;
			if(dis[1]<LLONG_MAX/3)ans=ans>dis[1]?ans:dis[1];
			else flag=true;
		}
		if(flag)ans=-1;
		print(ans);putchar(' ');
	}
	
	fclose(stdin);
	fclose(stdout);
} 
