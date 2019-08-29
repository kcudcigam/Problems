#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
int n,m,Q,type;
int x,y,size[MAXN];
int num[MAXN]={0};
//vector< int >X;
bool vis[10005][10005];

void deal(int t_place){
	int si=size[t_place];
	int nu=0;
	for(int i=1;i<=n;i++){
		if(vis[t_place][i]){
		num[i]+=y;
		++nu;
		}
		if(nu==si)
		return;
	}
	
}


int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d %d %d",&n,&m,&Q);
	int t1,t2;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		vis[i][j]=false;
	}
	*/
	for(int i=1;i<=m;i++){
		scanf("%d %d",&t1,&t2);
		//X[t1].push_back(t2);
		vis[t1][t2]=true;
		++size[t1];
		//X[t2].push_back(t1);
		vis[t2][t1]=true;
		++size[t2];
	}
	while(Q--){
	scanf("%d",&type);
	if(type==0){
		scanf("%d",&x);
		printf("%d\n",num[x]);
	}
	else if(type==1){
		scanf("%d %d",&x,&y);
		num[x]+=y;
		deal(x);
		}	
	}
	return 0;
}


