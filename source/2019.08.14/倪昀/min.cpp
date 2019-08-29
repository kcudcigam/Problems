#include<bits/stdc++.h>
#define fir(i,a,b) for(register unsigned i=a;i<=b;i++)
#define N 1010
#define NN 200100
using namespace std;
int k[10],a[NN],f[N][N],dp[N][N];
inline long long func(int x){
	int tmp=1,sum=0;
	for(int i=4;i;i--)sum+=k[i]*tmp,tmp*=x;
	return sum;
}
inline long long dfs(int l,int r){
	if(dp[l][r])return dp[l][r];
	long long ans=f[l][r];
	fir(i,l,r-1)ans=max(ans,dfs(l,i)+dfs(i+1,r));
	return dp[l][r]=ans;
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("min.in","r",stdin);
    freopen("min.out","w",stdout);
    int n=read();
    fir(i,1,4)k[i]=read();
    fir(i,1,n)a[i]=read();
    if(k[1]==0&&k[2]==0&&k[3]<=0){
    	long long sum=0;
    	double x;
		if(k[3]==0&&k[4]>0)x=0x3f3f3f3f;
		if(k[3]==0&&k[4]<=0)x=-0x3f3f3f3f;
		else x=-k[4]/k[3];
    	int l=1,r=1;
    	while(l<=n){
    		while(r<n&&a[r]<x)sum+=func(a[r]),r++;
    		l=r;
    		while(r<n&&a[r]>=x)r++;
    		if(r<=n){
    			int minn=0x3f3f3f3f;
    			fir(i,l,r)minn=min(minn,a[i]);
    			sum+=func(minn);
			}
    		l=r;
		}
	}else if(n<=1000){
		fir(i,1,n)
		    fir(j,i,n){
		    	int minn=0x3f3f3f3f;
		    	fir(k,i,j)minn=min(minn,a[k]);
		    	f[i][j]=func(minn);
			}
		memset(dp,0,sizeof(dp));
		fir(i,1,n)dp[i][i]=f[i][i];
		cout<<dfs(1,n)<<endl;
	}
	return 0;
}
