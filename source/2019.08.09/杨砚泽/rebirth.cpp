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
	int num;
	int len;
};
vector<node> p[200051];
int f[200051],hash1[200051],hash2[200051],bx=-1,by=-1;
inline void djk(int g)
{
	memset(hash1,0,sizeof(hash1));
	memset(f,0x3f,sizeof(f));
	int k=g;
	f[k]=0;
	while (1)
	{
	    hash1[k]=1;
		int minn=INT_MAX,mini=-1;
		for (int i=0;i<p[k].size();i++)
		{
			if (p[k][i].num==bx&&k==by) continue ;
			if (p[k][i].num==by&&k==bx) continue ;
			if (p[k][i].len<minn&&hash1[p[k][i].num]==0) {
			   		mini=i;
		   	minn=p[k][i].len;
		   }
		}
		if (mini==-1) break ;   
		for (int i=0;i<p[k].size();i++)
		  {
		  	if (p[k][i].num==bx&&k==by) continue ;
			if (p[k][i].num==by&&k==bx) continue ;
		  	 if (f[k]+p[k][i].len<f[p[k][i].num]&&hash1[p[k][i].num]==0) f[p[k][i].num]=f[k]+p[k][i].len;				   
		  }
		k=p[k][mini].num;
	}
}
int x[200051],y[200051],l[200051],ans[200051];
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
    int NUM,n,m;
    read(NUM);
    read(n);read(m);
    memset(hash2,0,sizeof(hash2));
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=m;i++)
    {   
    	read(x[i]);read(y[i]);read(l[i]);
        node p1,p2;
        p1.len=l[i];
        p1.num=y[i];
        p2.len=l[i];
        p2.num=x[i];
    	p[x[i]].push_back(p1);
    	p[y[i]].push_back(p2);    	
	}
	for (int i=1;i<=n;i++)
	  ans[i]=-2;
	ans[1]=0;
	for (int i=1;i<=m;i++)
      {
        bx=x[i];
        by=y[i];
        djk(1);
	    cout<<x[i]<<" "<<y[i]<<" "<<f[x[i]]<<" "<<f[y[i]]<<endl;
       // cout<<x[i]<<" "<<y[i]<<" "<<f[x[i]]<<" "<<f[y[i]]<<endl;
       if (f[x[i]]>5*1e5) {
       	djk(x[i]);
       	f[x[i]]=f[1];
	   }
	   if (f[y[i]]>5*1e5) {
       	djk(y[i]);
       	f[y[i]]=f[1];
	   }cout<<x[i]<<" "<<y[i]<<" "<<f[x[i]]<<" "<<f[y[i]]<<endl;
        if (f[x[i]]<=5*1e5&&ans[x[i]]!=-1) ans[x[i]]=max(ans[x[i]],f[x[i]]);
        else ans[x[i]]=-1;
        if (f[y[i]]<=5*1e5&&ans[y[i]]!=-1) ans[y[i]]=max(ans[y[i]],f[y[i]]);
        else ans[y[i]]=-1;
	  }
	cout<<0<<" ";
	for (int i=2;i<=n;i++)
	  if (ans[i]>=0)cout<<ans[i]<<" ";
	  else cout<<-1<<" ";
	  cout<<endl;
	return 0;
}
/*
1
4 5
1 2 5
2 3 7
1 4 8
2 4 2
1 3 9

1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/
