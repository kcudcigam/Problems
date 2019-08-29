#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[100010],ans[100010];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			merge(x,y);
		}else if(opt==2){
			int xx=get(x);
			for(int j=1;j<=n;j++){
				if(get(j)==xx)ans[j]+=y;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
/*
4 5
1 1 2
1 2 3
1 2 4
2 3 3 
2 2 2
*/

