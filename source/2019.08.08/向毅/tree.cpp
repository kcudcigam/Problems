#include<bits/stdc++.h>
#define N 200010
using namespace std;
int T,n,k,fa[N];
vector<int>mp[N],can;
string target,st,tt;
queue<string>q;
void build(int p,int tmp,int dep){
	if(dep>=k){
		can.push_back(p);
	}
	for(int i=0;i<mp[p].size();i++){
		if(mp[p][i]!=tmp){
			fa[mp[p][i]]=p;
			build(mp[p][i],p,dep+1);
		}
	}
}
void caozuo(int p,int dep){
	if(dep>k){
		return;
	}
	if(tt[p-1]=='1'){
		tt[p-1]='0';
	}else{
		tt[p-1]='1';
	}
	caozuo(fa[p],dep+1);
}
void bfs(){
	map<string,bool>mp;
	q.push(st);
	mp[st]=1;
	while(!q.empty()){
		string p=q.front();
		q.pop();
		for(int i=0;i<can.size();i++){
			tt=p;
			caozuo(can[i],1);
			if(tt==target){
				cout<<"Yes"<<endl;
				return;
			}
			if(mp[tt]==0){
				mp[tt]=1;
				q.push(tt);
			}
		}
	}
	cout<<"No"<<endl;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			mp[i].clear();
		}
		can.clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			mp[x].push_back(y);
			mp[y].push_back(x);
		}
		build(1,0,1);
		st="";
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			st+='0'+x;
		}
		target="";
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			target+='0'+x;
		}
		while(!q.empty()){
			q.pop();
		}
		bfs();
	}
	return 0;
}

