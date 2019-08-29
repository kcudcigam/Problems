#include<bits/stdc++.h>
#define N 1001
using namespace std;
struct S{
	int b,w;
	S(int B,int W){
		b=B;w=W;
	}
};
vector<S> son[N];
int mas(int x,int y,int z){
	int ans_1=max(x,y);
	ans_1=max(ans_1,z);
	return ans_1;
}
int s[N][N][101];
int ma[N][N];
bool g[N][N];
int Q,ans;
int n,m,x,y,z;
int main(){
freopen("graph.in","r",stdin);
freopen("graph.out","w",stdout);
scanf("%d%d%d",&n,&m,&Q);
for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
    ma[x][y]=ma[y][z]=z;
	g[x][y]=g[y][z]=1;
	//son[x].push_back(S(y,z));
//	son[y].push_back(S(x,z));
}

for(int i=1;i<=Q;i++){
	int t=1;
	scanf("%d%d",&x,&y);
	if(y>x) swap(x,y);
	for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
			if(i==x&&j==y) {
			t++;
		}
		if(g[i][k]&&g[k][j]) s[i][j][t]=mas(ma[i][k],s[i][j][t],ma[k][j]);
	
	}
}
for(int i=2;i<=t;i++){
	ans=1e9;
	ans=min(ans,s[x][y][i]);
}
	if(ans==0) {cout<<"-1"<<endl;continue;}
	cout<<ans<<endl;
}
	return 0;
}


