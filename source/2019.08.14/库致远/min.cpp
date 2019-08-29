#include<bits/stdc++.h>
using namespace std;
int md=1e9+7;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f  = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int n, A, B, C, D, a[500005],b[5000005],sum;
double Cal(double x) {return ((A * x + B) * x + C) * x + D;}
void dfs(int x,int y,int z,int fa,int fb){
	if (x==n+1){
		if (z>sum) sum=z;
		return ;
	}
	if (y==0){
		if (x+1<=n && b[x]<0 && b[x+1]>b[x])
		dfs(x+1,1,z+b[x],x,b[x]);
		else
		dfs(x+1,0,z+b[x],0,0);
		
	}
	if (y==1){
		if (a[x]<a[fa]){
		if (x+1<=n && b[fa]<0 && b[x+1]>b[fa])
		dfs(x+1,1,z+b[x]-b[fa],x,b[x]);
		else
		dfs(x+1,0,z+b[x]-b[fa],0,0);
	}
	else {
		if (x+1<=n && b[fa]<0 && b[x+1]>b[fa])
		dfs(x+1,1,z,fa,fb);
		else
		dfs(x+1,0,z,fa,fb);
	}
	}
	return ;
} 
int main() {
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    n = ri();//目标位置 
	 A = ri(); B = ri(); C = ri(); D = ri();
    for(int i = 1;i <= n; ++i) a[i] = ri();
    for(int i = 1;i <= n; ++i) 
	b[i]=fabs(Cal(a[i]));
   sum=-(md-1);//sum尽量大 
   dfs(2,0,b[1],a[1],b[1]);//当前位置 是否将下一个数收入 当前值 本集合中最小的数和他的值 
   dfs(2,1,b[1],a[1],b[1]);
   cout<<sum<<endl;
	return 0;
}

