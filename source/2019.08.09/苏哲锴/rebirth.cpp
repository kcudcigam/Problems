#include<bits/stdc++.h>
#define N 100001
using namespace std;
int x,y,z,a,w,cnt;
int d[N],ans[N];
bool ma[1000][1000]; 
struct S{
	int b,w;
	S(int B,int W){
		b=B;w=W;
	}
};
int n,m;
	int num;
vector<S> son[N];
priority_queue<S> q;
bool operator <(S x,S y){
	return x.w>y.w;
}
void dij(int k){q.push(S(1,d[1]=0));
for(int i=1;i<=n;i++) d[i]=1e9;
while(!q.empty()){
	a=q.top().b;
	int D=q.top().w;
	q.pop();
	d[a]=D;
	while(d[a]==D){
		
		for(int i=0;i<son[a].size();i++){
			int b=son[a][i].b;
			 if(!ma[a][b]){
			cnt++;
			w=d[a]+son[a][i].w;
			if(w<d[b]) {
	             ans[k]=max(ans[k],w);
	            //  cout<<w<<" "<<ans[k]<<endl;
				d[b]=w;q.push(S(b,d[b]));
			}}
		}
	}
}
}
int main(){
	freopen("rebirth.in","r",stdin);
    freopen("rebirth.out","w",stdout);
	
	
	cin>>num;
	cin>>n>>m;
for(int i=1;i<=m;i++){
	cin>>x>>y>>w;
	son[x].push_back(S(y,w)); ma[x][y]=0;
	son[y].push_back(S(x,w)); ma[y][x]=0;
	
}

for(int k=1;k<=n;k++){
		{
		 	for(int j=0;j<son[k].size();j++){
	                ma[k][j]=1;ma[j][k]=1;
	                dij(k);
	                ma[k][j]=0;ma[j][k]=0;
			}			
		}
	}
		for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
		
	
	return 0;
}

