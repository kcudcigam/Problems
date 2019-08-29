#include<cstdio>
#include<algorithm>
using namespace std;
int maxx_val,maxx_data,n;
struct sb{
	int to;
	int next;
}s[600010];
int deep[300010],head[300010],tot;
inline void add(int x,int y){
	s[++tot].next=head[x];
	s[tot].to=y;
	head[x]=tot;
}
inline void dfs(int x,int fa,int now){
	if(now>maxx_val){
		maxx_val=now;
		maxx_data=x;
	}
	for(register int i=head[x];i;i=s[i].next){
		int y=s[i].to;
		if(y!=fa){
			dfs(y,x,now+1);
		}
	}
}
inline int get_val(int x){
	maxx_val=0;
	dfs(x,0,0);
	maxx_val=0;
	dfs(maxx_data,0,0);
	return maxx_val;
}
inline int merge(int x,int y){
	add(x,y);add(y,x);
	printf("%d\n",get_val(x));
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
}
