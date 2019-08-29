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
struct node{
	int xx;
	int yy;
};
int f[300051],dp[300051];
vector<int> lp[300051]; 
int n,m,q,x,y,z;
pair<int,int> a[300051];
int main(){
    freopen("sibyl.in","r",stdin);
    freopen("sibyl.out","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    memset(f,0,sizeof(f));
  	read(n);read(m);read(q);
	for (int i=1;i<=m;i++)
	{
		read(a[i].first);read(a[i].second);
		if (a[i].first>a[i].second) swap(a[i].first,a[i].second);
	}
	sort(a+1,a+m+1);
	lp[a[1].first].push_back(a[1].second);
	lp[a[1].second].push_back(a[1].first);
	for (int i=2;i<=m;i++)
	{
		if (a[i].first!=a[i-1].first||a[i].second!=a[i-1].second){
			lp[a[i].first].push_back(a[i].second);
			lp[a[i].second].push_back(a[i].first);
		}
	}
    for (int i=1;i<=q;i++)
    {
    	read(x);read(y);
    	if (x==1) {
    		memset(dp,0x3f,sizeof(dp));
    		read(z);
    		f[y]+=z;
		}
		if (x==0) {
			int sum=f[y];
			if (dp[y]<1e9) sum=dp[y];
			else for (int j=0;j<lp[y].size();j++) sum=sum+f[lp[y][j]];
			cout<<sum<<endl;
		}
	}
	return 0;
}


