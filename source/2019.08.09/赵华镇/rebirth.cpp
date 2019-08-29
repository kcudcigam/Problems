#include<bits/stdc++.h>
using namespace std;
int maxx,n,book[100005];
int dis[100005],Map[1005][1005],Map1[1005][1005];
queue<int >que;
void spfa(int l)
{
	int x,i;
	que.push(l);
	book[l]=1;
	while(!que.empty()){
		x=que.front();
		que.pop();
		book[x]=0;
		for(i=1;i<=n;i++){
			if(dis[x]+Map[x][i]<dis[i]){
				dis[i]=dis[x]+Map[x][i];
				book[x]=1;que.push(i);
			}
		}
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num,m,i,j,x,y,len,t;
	scanf("%d",&num);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		dis[i]=0x3fffffff;
		for(j=1;j<=n;j++){
			if(i!=j)
			Map[i][j]=Map1[i][j]=0x3fffffff;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&len);
		if(len>=Map[x][y]){
			Map1[x][y]=Map1[y][x]=min(Map1[x][y],len);
		}
		else{
			Map1[x][y]=Map1[y][x]=min(Map1[x][y],Map[x][y]);
		}
		Map[x][y]=Map[y][x]=min(Map[x][y],len);
	}
	for(i=1;i<=n;i++){
		maxx=-0x3fffffff;
		for(j=1;j<=n;j++){
			if(Map[i][j]!=0x3fffffff&&i!=j){
				t=Map[i][j];
				Map[i][j]=Map[j][i]=0x3fffffff;
				if(Map1[i][j]!=0x3fffffff){
					Map[i][j]=Map[j][i]=Map1[i][j];
				}
				dis[i]=0;
				spfa(i);
				if(dis[1]!=0x3fffffff){
					maxx=max(maxx,dis[1]);
				}
				Map[i][j]=Map[j][i]=t;
			}
		}
		if(maxx==-0x3fffffff){
			printf("-1");
			if(i!=n){
				printf(" ");
			}
		}
		else{
			printf("%d",maxx);
			if(i!=n){
				printf(" ");
			}
		}
		for(j=1;j<=n;j++){
			dis[j]=0x3fffffff;
		}
	}
	return 0;
}

