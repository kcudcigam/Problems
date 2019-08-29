#include<bits/stdc++.h>
using namespace std;
int N;
int v[300001],d[300001];
int ans,m,cnt;
vector<int> son[300001];
void dfs(int x){
	v[x]=1;
	for(int i=0;i<son[x].size();i++){
		int b=son[x][i];
		if(!v[b]) {
			
			d[b]=d[x]+1;
			if(d[b]>ans) {
				ans=d[b];m=b;
			}
			dfs(b);
		}
	}
}
int main(){
freopen("town.in","r",stdin);
freopen("town.out","w",stdout);
cin>>N;

int x,y;
bool sub1=1;
for(int i=1;i<=N-1;i++){
	scanf("%d%d",&x,&y);
	if(x>i||y!=x+1) sub1=0;
	son[x].push_back(y);
	son[y].push_back(x);
	memset(v,0,sizeof(v));
	memset(d,0,sizeof(d));
	cnt=0,ans=0;
	d[x]=0;
	dfs(x);
	memset(v,0,sizeof(v));
	memset(d,0,sizeof(d));
	cnt=0,ans=0;
	d[m]=0;
//	cout<<"m="<<m<<endl;
	dfs(m);
	
	cout<<ans<<endl;
//	cout<<d[1]<<" "<<d[2]<<" "<<d[m]<<endl;
}

	return 0;
}


