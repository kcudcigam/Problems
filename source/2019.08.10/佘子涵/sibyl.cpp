#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N=600010;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,m,q,x,y,tot,hed[N],nxt[N*2],to[N*2],tot1,f[N],s[N][2],ty[N],a[N],b[N],tot2,st[N],ed[N],nw[N*20];
bool us[N],yep[N];
struct eve{
	int bl,nw;
} d[N*20];
struct eve1{
	int r,l,k,la;
} t[N*80];
queue<int> w;
void build(int x,int y){
	to[++tot]=y;
	nxt[tot]=hed[x];
	hed[x]=tot;
}
void bfs(int now){
	d[now].nw=++tot1;
	nw[now]=tot1;
	d[now].bl=now;
	us[now]=1;w.push(now);
	while(w.size()){
		int x=w.front();w.pop();
		for(int i=hed[x];i;i=nxt[i]){
			int y=to[i];
			if(y==f[x]) continue;
			if(us[y]){
				if(!yep[x]) continue;
				d[++tot2].nw=++tot1;
				d[tot2].bl=y;
				if(!s[x][0]) s[x][0]=tot1;
				s[x][1]=tot1;
				continue;
			}
			us[y]=1;f[y]=x;
			d[y].nw=++tot1;
			nw[y]=tot1;
			d[y].bl=y;
			if(!s[x][0]) s[x][0]=tot1;
			s[x][1]=tot1;
			w.push(y);
		}
	}
}
void buildt(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	buildt(x*2,l,mid);
	buildt(x*2+1,mid+1,r);
}
void pushdown(int x){
	if(t[x].la){
		t[x*2].k+=t[x].la*(t[x*2].r-t[x*2].l+1);
		t[x*2+1].k+=t[x].la*(t[x*2+1].r-t[x*2+1].l+1);
		t[x*2].la+=t[x].la;
		t[x*2+1].la+=t[x].la;
		t[x].la=0;
	}
}
void ch(int x,int l,int r,int z){
	if(t[x].l==t[x].r){
		t[x].k+=z;
		return;
	}
	if(t[x].l>=l&&t[x].r<=r){
		t[x].la+=z;
		t[x].k+=z*(t[x].r-t[x].l+1);
		return;
	}
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid) ch(x*2,l,r,z);
	if(mid<r) ch(x*2+1,l,r,z);
	t[x].k=t[x*2].k+t[x*2+1].k;
}
int as(int x,int l){
	if(t[x].l==t[x].r) return t[x].k;
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid) return as(x*2,l);
	else return as(x*2+1,l);
}
bool cmp(eve a,eve b){
	return a.bl<b.bl;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);read(m);read(q);
	tot2=n;
	for(int i=1;i<=m;i++){
		read(x);read(y);
		build(x,y);
		build(y,x);
	}
	for(int i=1;i<=q;i++){
		read(ty[i]);read(a[i]);
		if(ty[i]){
			read(b[i]);yep[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!us[i]) bfs(i);
	}
	sort(d+1,d+1+tot2,cmp);
	st[1]=1;ed[n]=tot2;
	for(int i=2;i<=tot2;i++){
		if(d[i].bl>d[i-1].bl){
			ed[d[i-1].bl]=i-1;
			st[d[i].bl]=i;
		}
	}
	buildt(1,1,tot2);
	for(int i=1;i<=q;i++){
		if(ty[i]){
			x=a[i];y=b[i];
			if(f[x]) ch(1,nw[f[x]],nw[f[x]],y);
			ch(1,nw[x],nw[x],y);
			if(s[x][0]) ch(1,s[x][0],s[x][1],y);
		}
		else{
			long long ans=0;
			x=a[i];
			for(int j=st[x];j<=ed[x];j++){
				ans+=as(1,d[j].nw);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

