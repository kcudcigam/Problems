#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int c[300010];
int inv[300010];
struct sb{
	int to;
	int next;
	int dis;
}s[6000010];
bool flag;
int n,m,q,head[300010],tot,cnt,maxx,minn=0x7fffffff;
inline void add(int x,int y,int z){
	s[++tot].dis=z;
	s[tot].next=head[x];
	s[tot].to=y;
	head[x]=tot;
}
inline void bfs(int st){
	inv[st]=1;
	c[st]=cnt;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(register int i=head[x];i;i=s[i].next){
			int y=s[i].to;
			if(!inv[y]){
				c[y]=cnt;
				q.push(y);inv[y]=1;
			}	
		}
	}
}
inline void dfs(int x,int ed,int sum){
	if(sum>=minn) return;
	if(x==ed){
		minn=min(minn,sum);
		return;
	}
	for(register int i=head[x];i;i=s[i].next){
		int y=s[i].to,z=s[i].dis;
		if(inv[y]!=2){
			inv[y]++;
			int now=sum;
			sum=max(sum,z);
			dfs(y,ed,sum);
			sum=now;
			inv[y]--;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	if(n<=1000&&m<=1000){
		flag=true;
	}
	for(register int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for(register int i=1;i<=n;i++){
		if(!c[i]){
			++cnt;
			bfs(i);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		minn=0x7fffffff;
		memset(inv,0,sizeof inv);
		if(c[x]!=c[y]){
			printf("-1\n");
			continue;
		}
		if(flag){
			dfs(x,y,0);
			printf("%d\n",minn);
		}
	}
}
