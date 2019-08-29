#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[1001]={0};
int d[1001]={0};
bool dd[1001][1001];
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		d[i]=i;
		dd[i][i]=1;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			int g=d[c];
			int q=d[b];
			for(int j=1;j<=n;j++){
				if(dd[g][j]){
					d[j]=q;
				}
			}
			for(int j=1;j<=n;j++){
				dd[q][j]=max(dd[q][j],dd[g][j]);
			}
		}else{
			for(int j=1;j<=n;j++){
				if(dd[d[b]][j]==1){
					ans[j]+=c;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i-1)cout<<" ";
		cout<<ans[i];
	}
	return 0;
}

