#include<bits/stdc++.h>
using namespace std;
long long num,n,m,x,y,ma[1000][1000],c,dist[10000],p,mx,pppp;
int main(){
    ios::sync_with_stdio(false);
    //freopen("rebirth.in","r",stdin);
	//freopen("rebirth.out","w",stdout);
	cin>>num;
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	  {
	  	cin>>x>>y>>pppp;
	  	if (x==y) continue;
		ma[x][y]=pppp;
		ma[y][x]=pppp; 
	  }	     
	cout<<0<<" ";
	for (int i=2;i<=n;i++)
	  {
	  	c=0;
	  	for (int j=1;j<=n;i++)
	  	  {
			if (ma[i][j]==1) c++;
		  }	 
		if (c<=1)
		{
			cout<<-1<<" ";
			continue;
		}
		
		cout<<mx<<" ";
	  }		
	cout<<endl;
	return 0;
}


