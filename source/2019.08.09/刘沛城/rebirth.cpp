#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak dp[111][111],dis[111][111];
priority_queue<ak,vector<ak>,greater<ak> >hx[111][111];
int main(){
	#ifndef lpcak
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	#endif
	ak n,m;
	ios::sync_with_stdio(0);
	cin>>n>>n>>m;F(i,1,n)F(j,1,n)dis[i][j]=(i-j)?im:0;
	F(i,1,n)F(j,1,n)if(i-j)hx[i][j].push(im);
	F(i,1,m){
		ak x,y,w;cin>>x>>y>>w;
		dis[x][y]=dis[y][x]=min(dis[x][y],w);
		hx[x][y].push(w);hx[y][x].push(w);
	}
	F(i,1,n)F(j,1,n)if(hx[i][j].size())hx[i][j].pop();
	F(i,1,n){
		ak ans=-im;
		F(j,1,n){
			if((i==j)||(dis[i][j]>=im))continue;
			F(k,1,n)F(l,1,n)dp[k][l]=dis[k][l];
			dp[i][j]=dp[j][i]=hx[i][j].top();
			F(k,1,n)F(l,1,n)F(p,1,n)
				dp[l][p]=min(dp[l][p],dp[l][k]+dp[k][p]);
			ans=max(dp[1][i],ans);
		}
		cout<<((ans>=im)?(-1):ans)<<((i<n)?" ":"\n");
	}
	return 0;
}
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/
