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
int mp[1051][1051],f[1051][1051];
int n,m,q;
int x,y,l;
inline void floyd()
{
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    for (int k=1;k<=n;k++)
	    {
	    	f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
		}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    memset(mp,0x3f,sizeof(mp));
	memset(f,0x3f,sizeof(f));
	read(n);read(m);read(q);
	for (int i=1;i<=n;i++)
	  f[i][i]=0;
    for (int i=1;i<=m;i++)
    {
    	read(x);read(y);read(l);
    	if (l<mp[x][y])
		{
			mp[x][y]=l;
        mp[y][x]=l;
        f[x][y]=l;
        f[y][x]=l;
		}
	}	
    floyd();
    for (int i=1;i<=q;i++)
      {
      	read(x);read(y);
      	if (f[x][y]<1e9)cout<<min(f[y][x],f[x][y])<<endl;
	  else cout<<-1<<endl;
	  }
	return 0;
}
/*
5 9 8
1 2 6
1 4 7
1 5 11
2 5 6
2 5 7
3 5 8
3 4 2
4 2 5
4 5 12

*/

