#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct sb{
	int l,r;
}s[310];
inline bool comp(sb x,sb y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int n,m,k1,k2,k3,k4,k5;
int cnt;
int a[610],b[610],ans,sum[310];
inline long long g(int x){
	return (long long)k5*x*x*x*x*x+k4*x*x*x*x+k3*x*x*x+k2*x*x+k1*x;
}
int v[310],len[10010];
long long maxx;
inline void lisan(){
	sort(a+1,a+2*n+1);
	for(register int i=1;i<=2*n;i++){
		if(i==1||a[i]!=a[i-1]){
			b[++ans]=a[i];
		}
	}
}
inline int query(int x){
	return lower_bound(b+1,b+ans+1,x)-b;
}
inline void dfs(int now){
	if(now==n+1){
		memset(len,0,sizeof len);
		for(register int i=1;i<=n;i++){
			len[v[i]]++;
		}
	 	long long sum1=0;
		for(register int i=1;i<=m;i++){
			sum1+=g(len[i]);
		}
		maxx=max(maxx,sum1);
		return;
	}
	for(register int i=s[now].l;i<=s[now].r;i++){
		v[now]=i;
		dfs(now+1);
		v[now]=0;
	}
}
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x,int val){
	for(register int i=x;i<=n;i+=lowbit(i)){
		sum[i]+=val;
	}
}
inline int ask(int x){
	int ans=0;
	for(register int i=x;i;i-=lowbit(i)){
		ans+=sum[i];
	}
	return ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&k1,&k2,&k3,&k4,&k5);
	for(register int i=1;i<=n;i++){
		scanf("%d%d",&s[i].l,&s[i].r);
		a[i]=s[i].l;a[i+n]=s[i].r;
		if(s[i].l==1&&s[i].r==m){
			cnt++;
		}
	}
	if(cnt==n){
		printf("%lld\n",g(n));
	}
	lisan();
	for(register int i=1;i<=n;i++){
		s[i].l=query(s[i].l);
		s[i].r=query(s[i].r);
	}
	m=ans;
	if(n<=40&&m<=10){
		dfs(1);
		printf("%lld\n",maxx);
		return 0;
	}
	sort(s+1,s+n+1,comp);
	for(register int i=1;i<=n;i++){
		add(s[i].l,1);
		add(s[i].r+1,-1);
	}
	for(register int i=1;i<=n;i++){
		int maxx1=0,pos;
		for(register int j=s[i].l;j<=s[i].r;j++){
			int now=query(j);
			if(now>maxx1){
				maxx1=now;
				pos=j;
			}
		}
		len[pos]++;
		add(s[i].l,-1);
		add(s[i].r+1,1);
	}
	long long ans1=0;
	for(register int i=1;i<=m;i++){
		ans1+=g(len[i]);
	}
	printf("%lld\n",ans1);
}
