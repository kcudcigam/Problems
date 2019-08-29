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
long long a,b,c,d,e;
inline long long calc(long long x)
{
	return a*x+b*x*x+c*x*x*x+d*x*x*x*x+e*x*x*x*x*x;
}
struct node{
	int l;
	int r;
};
node k[10051];int n,m;
inline bool cmp(node a,node b)
{
	return a.r<b.r;
}
bool hash1[20051];
int opt[1000051];
long long tot=0;
inline void dfs(int p,int num)
{
	if (p==0) {
		return ;
	}
		if (num!=-1){
			for (int i=1;i<=n;i++)
       {
	     if (num>=k[i].l&&num<=k[i].r&&hash1[i]==0) hash1[i]=1;
		  }	
		}
		 memset(opt,0,sizeof(opt));	  
	    for (int i=1;i<=n;i++)
	      {
	      if (hash1[i]==0)	{
	      	opt[k[i].l]++;
	      	opt[k[i].r+1]--;
		  }
		  }
		int maxn=INT_MIN,maxi,k=0;
		for (int i=1;i<=m;i++)
		{
			k=k+opt[i];
			if (k>maxn)
		{
			maxi=i;
	      maxn=k;
		}
		}
	tot+=calc(maxn);
	dfs(p-maxn,maxi);
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    
    read(n);read(m);
    read(a);read(b);read(c);read(d);read(e);
    for (int i=1;i<=n;i++)
    {
      read(k[i].l);
      read(k[i].r);
      if (k[i].l>k[i].r) swap(k[i].l,k[i].r);
	}
	memset(hash1,0,sizeof(hash1));
	dfs(n,-1);
	cout<<tot<<endl;
	return 0;
}

/*
7
15 
3 5 7 9 1
1 15
1 5
5 9
3 8
8 14
7 13
2 9
*/
