#include<bits/stdc++.h>
using namespace std;
int n,m,q,tot,k,ver[300010],edge[300010],Next[300010],head[300010];
void add(int x,int y){
	ver[++tot]=y;//Ä¿µÄµØ 
	//edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
int main(){
  freopen("sibyl.in","r",stdin);
  freopen("sibyl.out","w",stdout);
  cin>>n>>m>>q;	
  for (int i=1;i<=m;i++){
  	int x,y,z;
  	cin>>x>>y;
  	add(x,y);
  	add(y,x);
  }
   for (int i=1;i<=q;i++){
  	cin>>k;
  	if (k==1)  {
  		int x,yy;
  		cin>>x>>yy;
  		edge[x]+=yy;
  		for (int j=head[x];j;j=Next[j])
		  {
  	       int y=ver[j];
  	       edge[y]+=yy;
	       //int  z=edge[i];
          }  
        //  cout<<"sf"<<edge[2]<<endl;
  	/*	for (int j=1;j<=n;j++){
  			if (a[i][j]==1){
  				dis[j]+=y;
			  }
		  }*/
	  }
	if (k==0) {
		int x;
		cin>>x;
		cout<<edge[x]<<endl;
	}
  }
  
 // cout<<"sf"<<edge[1]<<endl;
	return 0;
}


