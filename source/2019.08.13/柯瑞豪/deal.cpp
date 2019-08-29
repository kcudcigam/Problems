#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct node{
	int w;
	int a,b;
}D[1010];
long long f[2][20010],ans;
int n,X;
long long Q[1010];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
    	x=(x<<1)+(x<<3)+(c&15);
    	c=getchar();
	}
	return x*w;
}
void dfs1(int num,int sum,int Mi){
	if(sum-Mi>=X)return;
	if((long long)sum+Q[num]<(long long)X)return;
	if(num==0){
		if(sum>=X){
	    	f[0][sum]++;
	    	f[0][sum]%=mod;		
		}
		return;
	}
	for(int i=0;i<=D[num].a;i++){
		if(i)dfs1(num-1,sum+i*D[num].w,D[num].w);
		else dfs1(num-1,sum+i*D[num].w,Mi);
	}
}
void dfs2(int num,int sum){
	if(sum>D[n].w)return;
	if(num>n){
		f[1][sum]++;
		f[1][sum]%=mod;
		return;
	}
	for(int i=0;i<=D[num].b;i++){
		dfs2(num+1,sum+i*D[num].w);
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
    n=read();X=read();
    for(int i=1;i<=n;i++){
    	D[i].w=read();D[i].a=read();D[i].b=read();
	}
	Q[1]=D[1].w*D[1].a;
	for(int i=2;i<=n;i++)Q[i]=Q[i-1]+(long long)D[i].w*D[i].a;
	dfs1(n,0,1100);
	dfs2(1,0);
	for(int i=0;i<D[n].w;i++){
		ans+=(f[0][X+i]*f[1][i])%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
