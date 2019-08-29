#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0; char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
void write(int x){
	if(x<0){putchar('-');write(-x);}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct info{
	int y,num;
};
int n,m,Q,tot,INF;
queue<int> q;
vector<info> v[300010];
int ver[300010],nxt[300010],head[300010],edge[300010],dis[300010];
int ans[300010];
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
}
void work(int x){
	memset(dis,0x3f,sizeof(dis));INF=dis[0];
	while(!q.empty())q.pop();
	q.push(x);dis[x]=0;
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i=head[p];i;i=nxt[i]){
			int y=ver[i];
			if(max(dis[p],edge[i])<dis[y]){
				q.push(y);
				dis[y]=max(dis[p],edge[i]);
			}
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x),read(y),read(z);
		add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=Q;i++){
		int x,y;cin>>x>>y;
		v[x].push_back((info){y,i});
	}
	for(int i=1;i<=n;i++){
		if(!v[i].size())continue;
		work(i);
		for(int j=0;j<v[i].size();j++){
			int y=v[i][j].y;
			int res=dis[y];
			if(res==INF)res=-1;
			ans[v[i][j].num]=res;
		}
	}
	for(int i=1;i<=Q;i++){
		if(ans[i]>=0){
			write(ans[i]);
			putchar('\n');
		}else putchar('-'),putchar('1'),putchar('\n');
	}
	return 0;
}
/*
5 5 4
1 2 3
1 3 2
3 2 1
1 4 5
2 4 4
1 2
1 4
3 5
2 4
*/

