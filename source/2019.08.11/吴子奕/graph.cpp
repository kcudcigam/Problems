#include<bits/stdc++.h>
using namespace std;
struct nmsl{
	int id;int x;int y;int w;
}a[300009];
vector<int>G[300009];

bool cmp(nmsl q1,nmsl q2){
	return q1.w>q2.w;
}
int fa[300009];
int Find(int a){
	if(a==fa[a])return a;
	fa[a]=Find(fa[a]);
	return fa[a];
}
int n,m,q;
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
    	int u,v,w1;
    	scanf("%d%d%d",&u,&v,&w1);
    	nmsl o;
    	o.id=i;
    	o.x=v;o.y=u;
    	o.w=w1;
    	o.x=u;o.y=v;
    	a[i]=o;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u,v;
		u=a[i].x;v=a[i].y;
    	G[u].push_back(i);
    	
    	G[v].push_back(i);
    
	}
	for(int i=1;i<=m;i++)fa[i]=i;
	    for(int i=1;i<m;i++){
	    	int u1,v1;u1=a[i].x;v1=a[i].y;
	    	for(int j=i+1;j<=m;j++){
	    		int u2,v2;u2=a[j].x;v2=a[j].y;
	    		if(u2==u1||u2==v1||v2==u1||v2==v1){
	    		fa[j]=Find(i);	
	    		
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<fa[i]<<" ";
		}
		for(int i=1;i<=q;i++){
			int p,b;
			scanf("%d%d",&p,&b);int num;num=-1;
			for(int j=0;j<(int)G[p].size();j++){
				int l=G[p][j];
				for(int k=0;k<(int)G[b].size();k++){
					int r=G[b][k];
					if(Find(l)==Find(2)){
						if(num<fa[l])num=fa[l];
					}
				}
			}
			if(num==-1)cout<<num<<endl;
			else cout<<a[num].w<<endl;
			
		}
	return 0;
}


