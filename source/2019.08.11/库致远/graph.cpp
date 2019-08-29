#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],bok[100000],sum,q,m,n,x,y,z;
void kzy(int x){
	if (bok[x]==1) return;
	bok[x]=1;
	for (int i=1;i<=n;i++){
		if (i!=x && a[x][i]<sum){
			sum=a[x][i];
			kzy(i);
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		if (i==j) a[i][j]=0;
			else
			a[i][j]=9999999;
    		
		}
	}
    for (int i=1;i<=m;i++){
    	cin>>x>>y>>z;
    	a[x][y]=z;
    	a[y][x]=z;
	}
	for (int i=1;i<=q;i++){
		cin>>x>>y;
		sum=a[x][y];
		for (int j=1;j<=n;j++){
			bok[j]=0;
		}
		kzy(x);
		cout<<sum<<endl;
	}
	return 0;
}


