#include<bits/stdc++.h>
using namespace std;
int n,maxx,f[10000][10000],a,b,k;
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	
    cin>>n;
    for (int i=1;i<=n;i++)
       for (int j=1;j<=n;j++)
          f[i][j]=10000000;
    k=0;
    for (int i=1;i<=n-1;i++){
    	cin>>a>>b;
    	f[a][b]=1;
    	f[b][a]=1;
    	if (i==1) cout<<1<<endl;
    	else{
    		maxx=0;
    		for (int k=1;k<=n;k++)
    		   for (int i=1;i<=n;i++)
    		      for (int j=1;j<=n;j++)
    		         if (f[i][k]!=10000000&&f[k][j]!=10000000
					     &&f[i][k]+f[k][j]<f[i][j])
    		            f[i][j]=f[i][k]+f[k][j];
    		for (int i=1;i<=n;i++) 
    		   for (int j=1;j<=n;j++)  
    		     if (f[i][j]!=1000000) 
				   maxx=max(f[i][j],maxx);
    		cout<<maxx<<endl;
		}
	}

	return 0;
}

