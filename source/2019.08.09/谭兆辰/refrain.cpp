#include<bits/stdc++.h>
using namespace std;
int num;
int n,m1,m2;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
int p[20];
int mp[20][20];
bool vis[20];
inline bool print(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[i][j]==1){
				if(mp[p[i]][p[j]]!=1) return 1;
			}
			if(mp[i][j]==2){
				if(mp[p[i]][p[j]]!=2) return 1;
			}
		}
	}
	return 0;
}
int ans=0;
inline void dfs(int x){
	if(x==n+1){
		if(print()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);
	if(num<=6){//30pts
		read(n),read(m1),read(m2);
		for(int i=1;i<=m1;i++){
			int x,y;
			read(x),read(y);
			mp[x][y]=1,mp[y][x]=1;
		}
		for(int i=1;i<=m2;i++){
			int x,y;
			read(x),read(y);
			mp[x][y]=2,mp[y][x]=2;
		}
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}


