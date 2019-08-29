#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
bool flag;
int Map[4500][4500];
bool vis[4500][4500];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct node{
	int a,b;
};
queue<node>q;
void bfs(int a,int b){
	q.push((node){a,b});
	vis[a][b]=1;
	ans=1;
	int i,col=Map[a][b];
	node k;
	while(!q.empty()){
		k=q.front();
		q.pop();
		for(i=0;i<4;i++){
			k.a+=dx[i];
			k.b+=dy[i];
			if(Map[k.a][k.b]!=col||vis[k.a][k.b]){
				k.a-=dx[i];
				k.b-=dy[i];
				continue;
			}
			if(k.a==1||k.b==1){
				flag=1;
				return;
			} 
			ans++;
			q.push(k);
			vis[k.a][k.b]=1;
			k.a-=dx[i];
			k.b-=dy[i];
		}
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&x,&y);
	++x;++y;
	Map[1][1]=Map[1][2]=Map[2][1]=1;
	Map[2][2]=-1;
	int i,u,v;
	for(i=2;i<=2100;i*=2){
		for(u=i+1;u<=2*i;u++)
			for(v=1;v<=i;v++)
				Map[u][v]=Map[v][u]=Map[u-i][v];
		for(u=i+1;u<=2*i;u++)
			for(v=i+1;v<=2*i;v++)
				Map[u][v]=Map[u-i][v-i]*-1;
	}
	if(x>(1<<12)||y>(1<<12)){
		printf("infinity");
		return 0;
	}
	bfs(x,y);
	if(flag)
		printf("infinity");
	else
		printf("%d",ans);
	return 0;
}
