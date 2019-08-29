#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im 666666666666666666
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak p5,p4,p3,p2,p1;struct duck{ak l;ak r;}a[333];
ak maxl[333][333],dp[333][333],dq[333];int tp[11111111][2];
#define g(x) (p5*x*x*x*x*x+p4*x*x*x*x+p3*x*x*x+p2*x*x+p1*x)
bool lpc(duck i,duck j){return i.r<j.r;}
int main(){
	#ifndef lpcak
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	#endif
	ak n,m,sub1=1,ans=-im,cnt=0;
	ios::sync_with_stdio(0);
	cin>>n>>m>>p1>>p2>>p3>>p4>>p5;
	F(i,1,n)
		{cin>>a[i].l>>a[i].r;if((a[i].l^1)||(a[i].r^m))sub1=0;}
	if(sub1){cout<<g(n)<<"\n";return 0;}
	if(m>250){
		F(i,1,n)tp[a[i].l][0]=i,tp[a[i].r][1]=i;
		F(i,1,m){
			if(tp[i][0]+tp[i][1])cnt++;
			if(tp[i][0])a[tp[i][0]].l=cnt;
			if(tp[i][1])a[tp[i][1]].r=cnt;
		}
	}
	sort(a+1,a+n+1,lpc);
	F(i,0,n-1){
		maxl[i][i]=a[i].l;
		F(j,i+1,n)maxl[i][j]=max(maxl[i][j-1],a[j].l);
	}
	maxl[n][n]=a[n].l;F(i,a[1].l,a[1].r)dp[1][i]=g(1);
	F(i,1,n)F(j,0,m)dp[i][j]=-im;F(i,1,n)dq[i]=-im;
	F(i,1,n)G(j,i,1){
		if(a[j].r<maxl[j][i])break;ak rs=i-j+1;
		F(k,maxl[j][i],a[j].r){
			//F(l,0,k-1)dp[i][k]=max(dp[i][k],dp[j-1][l]+g(rs));
			dp[i][k]=max(dp[i][k],dq[j-1]+g(rs));
			dq[i]=max(dq[i],dp[i][k]);
		}
	}
	F(i,0,m)ans=max(ans,dp[n][i]);cout<<ans<<"\n";
	return 0;
}
/*
8 12
0 1 0 0 0
1 3
3 5
2 7
6 10
3 8
8 9
10 12
9 10

4 6
0 1 0 0 0
1 2
1 3
1 4
5 6
*/
