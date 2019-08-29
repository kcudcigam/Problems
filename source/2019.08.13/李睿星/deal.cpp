#include<cstdio>
#include<queue>
using namespace std;
const long long mod=1e9+7;
int n,x,a[1005],b[1005],c[1005],cnt=1;long long ans,bns,sum;
struct my{
	int kd,sum;
}u;
queue<my>q;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=0;i<a[n];++i){
		if(i>=a[cnt]) ++cnt;
		q.push((my){0,0});
		while(!q.empty()){
			u=q.front();q.pop();
			if(u.kd>n+1||u.sum>i) continue;
			if(u.sum==i){++bns;continue;}
			for(int j=0;j<=c[u.kd];++j)
				q.push((my){u.kd+1,u.sum+j*a[u.kd]});
		}
		if(bns){
			q.push((my){cnt,0});
			while(!q.empty()){
				u=q.front();q.pop();
				if(u.kd>n+1||u.sum>x+i) continue;
				if(u.sum==x+i){++ans;continue;}
				for(int j=0;j<=b[u.kd];++j)
					q.push((my){u.kd+1,u.sum+j*a[u.kd]});
			}	
			sum+=ans*bns;sum%=mod;
			ans=bns=0;
		}
	}
	printf("%lld",sum);
	return 0;
}
