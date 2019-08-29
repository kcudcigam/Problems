#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<pair<int,int> > v;
}a[300010];
int y,mi;
bool hi[300010];
void dfs(int h,int ma)
{
	if(h==y){
		mi=min(mi,ma);
		return;
	}
	for(int i=0;i<a[h].v.size();i++){
		if(hi[a[h].v[i].first]==0){
			hi[a[h].v[i].first]=1;
			dfs(a[h].v[i].first,max(ma,a[h].v[i].second));
			hi[a[h].v[i].first]=0;
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,q,x,z;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x].v.push_back(make_pair(y,z));
		a[y].v.push_back(make_pair(x,z));
	}
	for(int i=1;i<=q;i++){
		mi=1000010;
		scanf("%d%d",&x,&y);
		hi[x]=1;
		dfs(x,0);
		hi[x]=0;
		if(mi!=1000010)printf("%d\n",mi);
		else printf("-1\n");
	}
	return 0;
} 
