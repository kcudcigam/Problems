#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
int n,k,limit;
bool ok[40];
int to[3][40],t[40][40],a[40];
vector<int>v[40];
unsigned int vis[4][40],v2[40];
//
int calc(int x){
	if(x==31)return 1;
	//assert(a[x]==-1);
	if(a[x]!=-1)return calc(x+1);
	int ans=0;
	rep(i,n){
		if(vis[0][to[0][x]]>>i&1)continue;
		if(vis[1][to[1][x]]>>i&1)continue;
		if(vis[2][to[2][x]]>>i&1)continue;
		bool flag=true;
		rep(j,v[x].size())if(v2[v[x][j]]>>i&1){
			flag=false;
			break;
		}
		if(!flag)continue;
		vis[0][to[0][x]]|=(1<<i);
		vis[1][to[1][x]]|=(1<<i);
		vis[2][to[2][x]]|=(1<<i);
	//	rep(j,v[x].size())assert(!(v2[v[x][j]]>>i&1));
		rep(j,v[x].size())v2[v[x][j]]|=(1<<i);
		a[x]=i;
		int tmp=calc(x+1);
		vis[0][to[0][x]]^=(1<<i);
		vis[1][to[1][x]]^=(1<<i);
		vis[2][to[2][x]]^=(1<<i);
		//rep(j,v[x].size())cout<<(v2[v[x][j]]>>i&1)<<endl;
		rep(j,v[x].size())v2[v[x][j]]^=(1<<i);
		ans+=tmp;
		a[x]=-1;
		if(ans>=limit)return limit;
	}
	return ans;
}
void dfs(int x,int cnt){
	if(x==31)return;
	//assert(a[x]==-1);
	if(a[x]!=-1){
		dfs(x+1,cnt);
		return;		
	}
	int ans=0;
	rep(i,n){
		if(vis[0][to[0][x]]>>i&1)continue;
		if(vis[1][to[1][x]]>>i&1)continue;
		if(vis[2][to[2][x]]>>i&1)continue;
		bool flag=true;
		rep(j,v[x].size())if(v2[v[x][j]]>>i&1){
			flag=false;
			break;
		}
		if(!flag)continue;
		vis[0][to[0][x]]|=(1<<i);
		vis[1][to[1][x]]|=(1<<i);
		vis[2][to[2][x]]|=(1<<i);
		rep(j,v[x].size())v2[v[x][j]]|=(1<<i);
		rep(j,v[x].size())assert(v2[v[x][j]]>>i&1);
		a[x]=i;
		int tmp=calc(x+1);		
		if(ans+tmp>=cnt){	
			dfs(x+1,cnt-ans);
			return;		
		}
		vis[0][to[0][x]]^=(1<<i);
		vis[1][to[1][x]]^=(1<<i);
		vis[2][to[2][x]]^=(1<<i);
		rep(j,v[x].size())v2[v[x][j]]^=(1<<i);
		ans+=tmp;
		a[x]=-1;
	}
	assert(false);
}
bool init(){
	ok[4]=ok[8]=ok[11]=ok[15]=ok[19]=ok[22]=ok[26]=true;
	int fk=0;
	rep(i,31)if(ok[i]){
		t[i][0]=i-6;t[i][1]=i-5;
		t[i][2]=i-1;t[i][3]=i+1;
		t[i][4]=i+5;t[i][5]=i+6;
		if(i==4)t[i][0]=0,t[i][1]=1;
		if(i==26)t[i][4]=29,t[i][5]=30;
		rep(j,6)v[t[i][j]].push_back(fk);
		v[i].push_back(fk);
		fk++;
	}
	memset(to[0],-1,sizeof(to[0]));
	to[0][1]=0;to[0][6]=1;to[0][12]=2;to[0][17]=3;to[0][23]=4;to[0][28]=5;to[0][30]=6;	
	for(int i=1;i<31;i++)if(to[0][i]>=0){
		for(int j=i-1;j>=0;j--){
			if(to[0][j]>=0)break;
			to[0][j]=to[0][i];			
		}		
	}
	for(int i=2;i<=28;i++)to[1][i]=i%6;
	to[1][18]=to[1][24]=6;
	to[1][0]=4;to[1][1]=5;
	to[1][29]=1;to[1][30]=2;
	for(int i=2;i<=28;i++)to[2][i]=i%5;
	to[2][2]=to[2][7]=5;
	to[2][3]=to[2][8]=to[2][13]=to[2][18]=to[2][0]=6;
	to[2][1]=4;
	to[2][29]=1;
	to[2][30]=2;
	//cout<<1<<endl;
	rep(i,31)if(a[i]>=0){
		int x=a[i];
		if(vis[0][to[0][i]]>>x&1)return false;
		if(vis[1][to[1][i]]>>x&1)return false;
		if(vis[2][to[2][i]]>>x&1)return false;
		vis[0][to[0][i]]|=(1<<x);
		vis[1][to[1][i]]|=(1<<x);
		vis[2][to[2][i]]|=(1<<x);
		rep(j,v[i].size())if(v2[v[i][j]]>>x&1)return false;
		rep(j,v[i].size())v2[v[i][j]]|=(1<<x);
	}
	return true;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	n=getint();k=getint();
	rep(i,31)a[i]=getint()-1;
	if(!init()){
		cout<<"No way\n";
		return 0;
	}
	limit=k;
	if(calc(0)<k){
		//cout<<calc(0)<<" "<<calc(0)<<endl;
		cout<<"No way\n";
		return 0;
	}
	dfs(0,k);
	cout<<"Found"<<endl;
	rep(i,31)printf("%d ",a[i]+1);
	return 0;
}
