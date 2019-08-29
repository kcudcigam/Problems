#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}
int f[4051][4501],hash1[4051];
int n,m,x,y;
int maxn;
inline void build(int num,int dep)
{
	hash1[num]=1;

	maxn=max(maxn,dep);
	for (int i=1;i<=n;i++)
	  {
	  	if (f[num][i]==1&&hash1[i]==0) build(i,dep+1); 
	  }
}
inline void build2(int num)
{
	hash1[num]=1;
	for (int i=1;i<=n;i++)
	  {
	  	if (f[num][i]==1&&hash1[i]==0) {
	  		f[x][i]=1;
	  		build2(i);
		  } 
	  }
}
int main(){
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
    read(n);
    memset(f,0,sizeof(f));
    for (int i=1;i<n;i++)
    {
    	maxn=INT_MIN;
    	read(x);read(y);
	    f[x][y]=1;
	    f[y][x]=1;
	    build2(x);
	    for (int j=1;j<=n;j++)
	    {
	    	if (f[x][j]==1)
			{
				memset(hash1,0,sizeof(hash1));
	    	build(j,0);
			}
		   }   
	    cout<<maxn<<endl;
	}
	
	return 0;
}


