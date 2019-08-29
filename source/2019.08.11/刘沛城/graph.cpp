#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
struct duck{ak s;ak e;ak w;}a[333333];
ak xx[333333],yy[333333],dad[333333],ans[333333];
bool lpc(duck i,duck j){return i.w<j.w;}
ak zz(ak x){
	if(dad[x]==x)return x;
	return dad[x]=zz(dad[x]);
}
int main(){
	#ifndef lpcak
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
	ak n,m,q;
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	F(i,1,m)cin>>a[i].s>>a[i].e>>a[i].w;
	F(i,1,q)cin>>xx[i]>>yy[i];
	sort(a+1,a+m+1,lpc);
	F(i,1,n)dad[i]=i;F(i,1,q)ans[i]=im;
	F(i,1,m){//30 pts
		if(zz(a[i].s)==zz(a[i].e))continue;
		dad[zz(a[i].e)]=zz(a[i].s);
		F(j,1,q){
			if(zz(xx[j])==zz(yy[j]))
				ans[j]=min(ans[j],a[i].w);
		}
	}
	F(i,1,q)cout<<(ans[i]!=im?ans[i]:-1)<<"\n";
	return 0;
}
