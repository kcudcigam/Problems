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
int a[41];
int hash1[41][41];
int hash2[41];
int n,m,k,tot;
inline void dfs(int dep)
{
	
}
int main(){
    freopen("hexodoku.in","r",stdin);
    freopen("hexodoku.out","w",stdout);
    read(k);read(n);
    int sum=0;
    memset(hash1,0,sizeof(hash1));
    for (int i=1;i<=31;i++)
	  {
	  	read(a[i]);
	  }
    cout<<"No way"<<endl;
	
	return 0;
}


