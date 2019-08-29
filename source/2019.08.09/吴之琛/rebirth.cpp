#include<bits/stdc++.h>
#define N 500010
#define ll long long
#define INF 200000000000001
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int Num;
int n,m;
struct side{
	int v,last;
	ll w;
	bool tag;
};
int len;
side c[N<<1];
ll dis[N],skip[N];
ll ans[N];
int head[N];
int two[N];
void put(int x,int y,ll z){
	c[++len].v=y;
	c[len].w=z;
	c[len].tag=true;
	c[len].last=head[x];
	head[x]=len;
	return;
}
struct Heap{
	int len;
	int w[N],pos[N];
	void clear(){
		len=0;
		for (int i=1;i<=n;i++) w[i]=pos[i]=0;
	}
	void upwork(int p){
		if (p==1) return;
		if (dis[w[p]]<dis[w[p>>1]]){
			swap(w[p],w[p>>1]);
			swap(pos[w[p]],pos[w[p>>1]]);
			upwork(p>>1);
		}
		return;
	}
	void downwork(int p){
		if ((p<<1)>len) return;
		int k=p<<1;
		if (k+1<=len&&dis[w[k+1]]<dis[w[k]]) k++;
		if (dis[w[k]]<dis[w[p]]){
			swap(w[k],w[p]);
			swap(pos[w[k]],pos[w[p]]);
			downwork(k);
		}
		return;
	}
	void insert(int x){
		w[++len]=x;
		pos[x]=len;
		upwork(len);
		return;
	}
	void pop(){
		pos[w[len]]=1;
		w[1]=w[len--];
		downwork(1);
		return;
	}
	int top(){
		return w[1];
	}
};
Heap h;
void dij(){
	for (int i=2;i<=n;i++) dis[i]=INF;
	h.clear();
	for (int i=1;i<=n;i++) h.insert(i);
	for (int i=1;i<n;i++){
		int k=h.top();
		h.pop();
		for (int j=head[k];j;j=c[j].last){
			if (c[j].tag&&dis[c[j].v]>dis[k]+c[j].w){
				dis[c[j].v]=dis[k]+c[j].w;
				h.upwork(h.pos[c[j].v]);
			}
		}
	}
	return;
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(Num);
	read(n);read(m);
	for (int i=1;i<=m;i++){
		int x,y;ll z;
		read(x);read(y);read(z);
		put(x,y,z);put(y,x,z);
	}
	if (Num<=7){
		for (int i=2;i<=n;i++) ans[i]=-1;
		for (int i=1;i<=m;i++){
			c[i*2-1].tag=false;
			c[i*2].tag=false;
			dij();
			ans[c[i*2-1].v]=max(ans[c[i*2-1].v],dis[c[i*2-1].v]);
			ans[c[i*2].v]=max(ans[c[i*2].v],dis[c[i*2].v]);
			c[i*2-1].tag=true;
			c[i*2].tag=true;
		}
		for (int i=1;i<=n;i++) if (ans[i]==INF) ans[i]=-1;
		for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
		putchar('\n');
		return 0;
	}
	if (12<=Num&&Num<=16){
		dij();
		for (int i=2;i<=n;i++) two[i]=0;
		two[1]=2;
		for (int i=1;i<=m;i++)
			if (abs(c[i*2-1].v-c[i*2].v)==1)
				two[max(c[i*2-1].v,c[i*2].v)]++;
		for (int i=2;i<=n;i++){
			ans[i]=INF;
			skip[i]=INF;
		}
		for (int i=1;i<=n;i++){
			if (two[i]>1) ans[i]=dis[i];
			else{
				for (int j=head[i];j;j=c[j].last){
					if (c[j].v==i-1) continue;
					if (c[j].v<i) ans[i]=min(ans[i],c[j].w+dis[c[j].v]);
					else ans[i]=min(ans[i],skip[c[j].v]+c[j].w);
				}
			}
			for (int j=head[i];j;j=c[j].last)
				if (c[j].v>i) skip[c[j].v]=min(skip[c[j].v],dis[i]+c[j].w);
		}
		for (int i=1;i<=n;i++) if (ans[i]==INF) ans[i]=-1;
		for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
		putchar('\n');
		return 0;
	}
	return 0;
}

