#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int a[1008][1008],u[1008],maxi,mini,n,m,q;
void dfs(int x,int y,int sum)
{
	int i;
	if (x==y){ 
	       if (sum!=-INT_MAX) mini=min(sum,mini);
	       return;
	}
	else {
		for (i=1;i<=n;i++)
		{
			if (a[x][i]!=0&&u[i]==0)
			{
				u[i]=1;
                sum=max(sum,a[x][i]);
				dfs(i,y,sum);
			 } 
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int i,j;
	read(n);
	read(m);
	read(q);
    for (i=1;i<=m;i++)
    {
    	int x,y,z;
    	read(x);
    	read(y);
    	read(z);
    	a[x][y]=z;
    	a[y][x]=z;
	}
	for (i=1;i<=q;i++)
	{
		memset(u,0,sizeof(u));
		int x,y;
		mini=INT_MAX;
		read(x);
		read(y);
		dfs(x,y,-INT_MAX); 
		if (mini==INT_MAX) cout<<-1<<endl;
		          else cout<<mini<<endl;
	}
	return 0;
}


