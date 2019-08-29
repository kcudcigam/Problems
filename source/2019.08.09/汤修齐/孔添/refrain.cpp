#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,num,mod=1e9+7,ans=1;
struct node{
	int x,y;	
}a[200010];
int MAP[2000][2000];
int b[200010];
bool h[200010];
bool check(){
	for(int i=1;i<=m1;++i){
		int x=a[i].x,y=a[i].y;
		if(MAP[b[x]][b[y]]!=-1) return false;
	}
	for(int i=1;i<=m2;++i){
		int x=a[i+m1].x,y=a[i+m1].y;
		if(MAP[b[x]][b[y]]!=1) return false;
	}
	return true;
}
void deal(int dep){
	if(dep==n+1){
		if(check()) ans--;
		return;
	}
	for(int i=1;i<=n;++i){
		if(h[i]==false){
			h[i]=true;
			b[i]=dep;
			deal(dep+1);
			h[i]=false;
		}
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);	
	
	cin>>num;
	cin>>n>>m1>>m2;
	int x,y;
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&x,&y);
		a[i].x=x;
		a[i].y=y;
		MAP[x][y]=-1;
		MAP[y][x]=-1;
	}
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&x,&y);
		a[i+m1].x=x;
		a[i+m1].y=y;
		MAP[x][y]=1;
		MAP[y][x]=1;
	}
	
	for(int i=1;i<=n;++i){
		ans=ans*i%mod;
	}
	
	deal(1);
	
	cout<<ans<<endl;
	
	return 0;
}

