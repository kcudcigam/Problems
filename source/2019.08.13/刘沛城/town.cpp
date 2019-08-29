#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
#define im 999999999999999
vector<ak>way[333333];ak anc[333333][33],dp[333333];
ak a[333333],b[333333],dad[333333],d[333333],zjz[333333],zjy[333333];
void dfs(ak cur,ak up){
	anc[cur][0]=up;d[cur]=d[up]+1;
	F(i,1,25)anc[cur][i]=anc[anc[cur][i-1]][i-1];
	F(i,0,way[cur].size()-1){
		if(way[cur].empty())break;
		int v=way[cur][i];if((v==1)||(anc[v][0]))continue;dfs(v,cur);
	}
}
ak zz(ak n){if(dad[n]==n)return n;return dad[n]=zz(dad[n]);}
ak lca(ak x,ak y){
	if(d[x]>d[y])G(i,25,0)if(d[anc[x][i]]>=d[y])x=anc[x][i];
	if(d[y]>d[x])G(i,25,0)if(d[anc[y][i]]>=d[x])y=anc[y][i];
	if(x==y)return x;
	G(i,25,0)if(anc[x][i]^anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
ak dis(ak x,ak y){return d[x]-d[lca(x,y)]*2+d[y];}
int main(){
	#ifndef lpcak
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	#endif
	ak n;
	ios::sync_with_stdio(0);
	cin>>n;
	F(i,1,n-1){
		cin>>a[i]>>b[i];
		way[a[i]].push_back(b[i]);way[b[i]].push_back(a[i]);
	}
	F(i,0,25)anc[1][i]=0;d[1]=1;dfs(1,0);
	F(i,1,n)zjz[i]=zjy[i]=i;F(i,1,n)dad[i]=i;
	F(i,1,n-1){
		ak ans=-im,ld=zz(a[i]),le=zz(b[i]);ans=max(ans,dp[ld]);
		ak dd0=dp[le],dd1=dis(zjz[ld],a[i])+1+dis(zjz[le],b[i]);
		ak dd2=dis(zjy[ld],a[i])+1+dis(zjz[le],b[i]);
		ak dd3=dis(zjz[ld],a[i])+1+dis(zjy[le],b[i]);
		ak dd4=dis(zjy[ld],a[i])+1+dis(zjy[le],b[i]);
		ak m0=max(max(dd1,dd2),max(dd3,dd4));
		ak m1=max(max(dd0,dd2),max(dd3,dd4));
		ak m2=max(max(dd0,dd1),max(dd3,dd4));
		ak m3=max(max(dd0,dd1),max(dd2,dd4));
		ak m4=max(max(dd0,dd1),max(dd2,dd3));
		if(dd0>=m0){
			ans=dp[ld]=dp[le],zjz[ld]=zjz[le],zjy[ld]=zjy[le];
			cout<<ans<<"\n";continue;
		}
		if(dd1>=m1){
			ans=dp[ld]=dd1,zjy[ld]=zjz[le];
			dad[le]=ld;cout<<ans<<"\n";continue;
		}
		if(dd2>=m2){
			ans=dp[ld]=dd2,zjz[ld]=zjz[le];
			dad[le]=ld;cout<<ans<<"\n";continue;
		}
		if(dd3>=m3){
			ans=dp[ld]=dd3,zjy[ld]=zjy[le];
			dad[le]=ld;cout<<ans<<"\n";continue;
		}
		if(dd4>=m4){
			ans=dp[ld]=dd4,zjz[ld]=zjy[le];
			dad[le]=ld;cout<<ans<<"\n";continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
7
3 5
3 4
1 2
1 3
6 2
5 7
*/
