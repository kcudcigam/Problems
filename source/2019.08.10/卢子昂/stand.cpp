#include<bits/stdc++.h>
using namespace std;
const int Maxn=300;
vector<int>st[Maxn];
long long g[Maxn];
int n,m,a,b,c,d,e;
int k[Maxn],ll[Maxn],rr[Maxn];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int d){
	for(;x<=n;x+=lowbit(x))k[x]+=d;
}
int ask(int x){
	int cnt=0;
	for(;x;x-=lowbit(x))cnt+=k[x];
	return cnt;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int i,j;
	long long ans=0;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(i=1;i<=n;i++)
		g[i]=a*i+b*i*i+c*i*i*i+d*i*i*i*i+e*i*i*i*i*i;
	for(i=1;i<=n;i++){
		scanf("%d%d",&ll[i],&rr[i]);
		add(ll[i],1);add(rr[i]+1,-1);
		for(j=ll[i];j<=rr[i];j++)st[j].push_back(i);
	}
	int id=0,cnt=0;
	while(cnt<n){
		int tmp=0,ai,now;
		for(i=1;i<=m;i++){
			ai=ask(i);
			if(ai>tmp){
				id=i;
				tmp=ai;
			}
		}
		ans+=g[ask(id)];
		cnt+=ask(id);
		for(i=0;i<st[id].size();i++){
			now=st[id][i];
			add(ll[now],-1);add(rr[now],1);
		}
		st[id].clear();
	}
	printf("%lld",ans);
	return 0;
}


