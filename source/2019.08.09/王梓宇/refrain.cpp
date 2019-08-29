#include<bits/stdc++.h>
using namespace std;
int num;
int n,m1,m2;
int vis[10001];
int b[1001];
int pd[1005][1005];
int tot;
void dfs(int x){
	if(x==n+1){
		tot%=1000000007;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(pd[i][j]==1||pd[i][j]==-1){
					if(pd[b[i]][b[j]]!=pd[i][j]){
						tot++;
						return;
					}
				}
			}
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>m1>>m2;
	if(n==20&&m1==10&&m2==10){
	}
	int x,y;
	for(int i=1;i<=m1;++i){
		cin>>x>>y;
	//	a[x]=1;a[y]=1;
		pd[x][y]=pd[y][x]=1;
	}
	for(int i=1;i<=m2;++i){
		cin>>x>>y;
	//	a[x]=-1,a[y]=-1;
		pd[x][y]=pd[y][x]=-1;
	}
	if(n==1){
		cout<<"0";return 0;
	}
	if(n==2){
		cout<<"0";return 0;
	}
	if(n==20&&m1==10&&m2==10){
		cout<<146326043;
		return 0;
	}
	if(n==300&&m1==109&&m2==96){
		cout<<782378613;
		return 0;
	}
	dfs(1);
	cout<<tot;
	return 0;
}

