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
ll Y;
const int N=10005;
int mo=10000,s=mo;
vector<int>G[N];
vector<pii >res;
//
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	if(Y==1ll){
		printf("%d %d\n",1,0);
		return 0;
	}
	int mx=0;
	rep(i,62)if(Y>>i&1ll)mx=i;
	G[mo-1].push_back(mo);
	s=mo-1;
	for(int i=mx-1;i>=0;i--){
		int pre=s;--s;
		if(Y>>i&1ll){
			--s;
			G[s].push_back(s+1);
			G[s+1].push_back(mo);
		}
		for(int j=pre;j<=mo;j++)G[s].push_back(j);
	}	
	printf("%d ",mo-s+1);
	for(int i=s;i<mo;i++)rep(j,G[i].size())res.push_back(mp(i-s+1,G[i][j]-s+1));
	printf("%d\n",(int)res.size());
	rep(i,res.size()){
		printf("%d %d\n",res[i].first,res[i].second);
	}
	return 0;
}
