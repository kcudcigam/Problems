#include<bits/stdc++.h>
#define N 1010
#define ll long long
using namespace std;
int n,m,price[N],dp[199][1999],ans=0;
template<typename T>inline void read(T &x)
{ 
 int f=1;
 char c=getchar();
 x=0;
 while (!isdigit(c))
 {  if (c=='-') f=-1;
   c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;
}
ll write(ll x)
{   if (x<0)
	 {putchar('-');write(-x);}
	if (x/10)  write(x/10);
	putchar(x%10+48);
}
void dfs(int dep,int sum,int w)
{   if (w>m) return;
   if (dep>n) {ans=max(ans,w);return;}
   dfs(dep+1,sum,w);
   dfs(dep+2,sum+price[dep],w+1);
}
int main(){
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);
   read(n);read(m);
   for (int i=1;i<=n;i++)
    read(price[i]);
   if (n<=100)
   {for (int i=price[1];i<=m;i++)
    dp[1][i]=1;
   for (int i=2;i<=n;i++)
    for (int j=1;j<=m;j++)
        { dp[i][j]=dp[i-1][j];
		 if (j>=price[i]&&i>2) dp[i][j]=max(dp[i][j],dp[i-2][j-price[i]]+1);}
    for (int i=1;i<=n;i++)
		{ ans=max(ans,dp[i][m]);}
		write(ans);puts("");}
	else { dfs(1,0,0);
	 write(ans);puts("");
	}
	return 0;
}

