#include<cstdio>
#include<algorithm>
using namespace std;
struct hxr{
	int a;
	bool b1,b2;
}p[400005];
bool cmp(hxr a,hxr b){
	return a.a>b.a;
}
int n,ans1,ans2,maxnum,maxa,sum,maxans;
void dfs(int now,int choose,int n1,int n2,int active){
	if(active+sum<=maxans) return;
	sum-=p[now].a;
	if(now>n){
		maxans=max(maxans,active);
		return;
	}
	if(max(max(n1+!p[now].b1,n2+!p[now].b2)*2,choose+1)<=maxnum)
		dfs(now+1,choose+1,n1+!p[now].b1,n2+!p[now].b2,active+p[now].a);
	dfs(now+1,choose,n1,n2,active);
	sum+=p[now].a;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	bool flag=0;
	for(int i=1,x;i<=n;++i){
		scanf("%d%d",&x,&p[i].a);
		switch(x){
			case 11:p[i].b2=1;++ans2;
			case 10:p[i].b1=1;++ans1;flag=1;break;
			case 1:p[i].b2=1;++ans2;flag=1;
		}
		sum+=p[i].a;
		maxa=max(maxa,p[i].a);
	}
	maxnum=min(n,2*min(ans1,ans2));
	if(maxnum==n){
		printf("%d",sum);
		return 0;
	}
	if(maxa*n==sum){
		printf("%d",maxa*maxnum);
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	if(!flag){
		int ans=0;
		for(int i=1,cnt=0;i<=n;++i)
			if(cnt*2<maxnum||p[i].b1){
				ans+=p[i].a;
				if(!p[i].b1) ++cnt;
			}
		printf("%d",ans);
		return 0;
	}
	dfs(1,0,0,0,0);
	printf("%d",maxans);
	return 0;
}
