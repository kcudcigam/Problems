#include<bits/stdc++.h>
using namespace std;
int d[3000][3000];
int fa[300009];
int fir[300009][4];
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
 int n;scanf("%d",&n);
 memset(d,0x3f,sizeof(d));
 for(int i=1;i<=n;i++)fa[i]=i;
 for(int g=1;g<n;g++){
 	int u,v,id;
 	scanf("%d%d",&u,&v);
 	fa[find(v)]=find(u);
 	id=find(u);
 	d[u][v]=1;d[v][u]=1;
 	for(int k=1;k<=n;k++){
 		if(find(k)!=id)continue;
 		for(int i=1;i<=n;i++){
 			if(find(i)!=id)continue;
 			for(int j=1;j<=n;j++){
 				if(find(j)!=id)continue;
 				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			 }
		 }
	
	 }int sum=0;
		 for(int i=1;i<=n;i++){
		 	if(find(i)!=id)continue;
		 	for(int j=1;j<=n;j++){
		 		if(find(j)!=id)continue;
		 		//cout<<"!";
		 		//if(d[i][j]==2)cout<<"!"<<i<<j<<"!";
		 		if(i!=j)sum=max(sum,d[i][j]);
			 }
		 }	
		 printf("%d\n",sum);
		//+  cout<<sum<<endl;
 }
 //cout<<endl<<fa[3]<<" "<<fa[5];
	return 0;
}


