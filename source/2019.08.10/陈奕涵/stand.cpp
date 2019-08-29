#include<bits/stdc++.h>
using namespace std;
const int maxn=260,maxm=1e7+10;
int n,m;
//g(x)函数( 由题意知,g(x)单调递增 )
long long xishu[10],g[maxn];
long long calc(int x){
	long long val=0;
	for(int i=5;i>=1;--i)
		val=(val+xishu[i])*x;
	return val;
}
//存储每个天使的所在区间 
struct angel{
	int l,r;
}a[maxn];
int tree[maxn],have[maxn];
//骗分
int main()
{
	freopen("stand.in ","r",stdin );
	freopen("stand.out","w",stdout);
	//读入,复杂度O(n)
	scanf("%d%d",&n,&m);
	for(int i=1;i<=5;++i)
		scanf("%lld",&xishu[i]);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].l,&a[i].r);	
	//子任务判断 
	bool subtask=true;
	for(int i=1;i<=n && subtask;++i)
		if(a[i].l!=1 || a[i].r!=m)subtask=false;
	if(subtask){
		printf("%lld\n",calc(n));
		return 0;
	}
	//先预处理一遍g(x)函数,复杂度O(n)
	for(int i=1;i<=n;++i)g[i]=calc(i); 
	//处理
	int cnt=n;
	long long ans=0;
	while(cnt){
		int maxv=0,maxp;
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;++i){
			if(have[i])continue;
			int l=a[i].l,r=a[i].r;
			for(int k=l;k<=r;++k)tree[k]++;
		}
		for(int i=1;i<=n;++i)
			if(tree[i]>maxv){
				maxv=tree[i];maxp=i;
			}
		cnt-=maxv;
		for(int i=1;i<=n;++i){
			if(have[i])continue;
			int l=a[i].l,r=a[i].r;
			if(l<=maxp && maxp<=r)have[i]=true;
		}
		ans+=g[maxv];
		if(maxv==0)break;
	}
	printf("%lld\n",ans);
	return 0;
} 
