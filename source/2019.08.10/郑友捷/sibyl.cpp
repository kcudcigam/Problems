#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,m,q;
struct sb{
	int to;
	int next;
}s[600010];
int l[300010],r[300010];
vector<int>e[300010];
int head[300010],tot,data[300010],len,pos;
inline void add_edge(int x,int y){
	s[++tot].next=head[x];
	s[tot].to=y;
	head[x]=tot;
}
int add[300010],sum[300010],sum1[300010],c[300010],cnt;
bool inv[300010];
inline int calc(int x){
	int now=add[x];
	for(register int i=head[x];i;i=s[i].next){
		int y=s[i].to;
		now+=add[y];
	}
	return now;
}
inline void dfs(int x){
	c[x]=cnt;
	e[cnt].push_back(x);
	for(register int i=head[x];i;i=s[i].next){
		int y=s[i].to;
		if(!c[y]){
			dfs(y);
		}
	}
}
bool flag;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(register int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);add_edge(y,x);
		l[i]=x;r[i]=y;
		data[x]++;data[y]++; 
	}
	for(register int i=1;i<=n;i++){
		if(data[i]<10) len++;
		else pos=i;
	}
	for(register int i=1;i<=m;i++){
		if(l[i]==pos) inv[r[i]]=true;
		else if(r[i]==pos) inv[l[i]]=true;
	}
	inv[pos]=true;
	if(len==n-1){
		for(register int i=1;i<=q;i++){
			int opt;
			scanf("%d",opt);
			if(opt==0){
				int x;
				scanf("%d",&x);
				if(inv[x]){
					printf("%d\n",sum[x]+sum1[pos]);
				}
				else printf("%d\n",sum[x]);
			}
			else if(opt==1){
				int x,y;
				scanf("%d%d",&x,&y);
				if(x==pos){
					sum1[pos]+=y;
				}
				else {
					sum[x]+=y;
					for(register int i=head[x];i;i=s[i].next){
						int tt=s[i].to;
						sum[tt]+=y;
					}
				}
			}
		}
		return 0;
	}
	for(register int i=1;i<=n;i++){
		if(!c[i]){
			++cnt;
			dfs(i);
		}
	}
	memset(inv,false,sizeof inv);
	for(register int i=1;i<=cnt;i++){
		len=0;pos=0;
		for(register int j=0;j<e[i].size();j++){
			if(data[e[i][j]]==1){
				len++;
			}
			else pos=i;
		}
		if(len==e[i].size()-1){
			inv[pos]=true;
		}
		else {
			flag=true;
		}
	}
	if(!flag){
		for(register int i=1;i<=q;i++){
			int opt;
			scanf("%d",&opt);
			if(opt==0){
				int x;
				scanf("%d",&x);
				printf("%d\n",sum[x]+sum1[c[x]]);
			} 
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				if(inv[x]){
					sum1[c[x]]+=y;
				}
				else{
					sum[x]+=y;
					for(register int j=head[x];j;j=s[j].next){
						int tt=s[j].to;
						sum[tt]+=y;
					}
				}
			}
		}		
		return 0;
	}
	for(register int i=1;i<=q;i++){
		int opt;
		scanf("%d",&opt);
		if(opt==0){
			int x;
			scanf("%d",&x);
			printf("%d\n",calc(x));
		}
		else {
			int x,y;
			scanf("%d%d",&x,&y);
			add[x]+=y;
		}
	}
}
