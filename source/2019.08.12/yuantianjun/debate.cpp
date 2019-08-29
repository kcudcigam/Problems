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
int n,res;
vector<int>v[4];
//
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=getint();
	rep(i,n){
		char s[5];scanf("%s",s);
		int x=(s[0]-'0')*2+s[1]-'0';
		v[x].push_back(getint());
	}
	rep(i,4){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	int sz=v[3].size();
	rep(i,v[3].size())res+=v[3][i];
	int mn=min(v[1].size(),v[2].size());
	rep(i,mn)res+=v[1][i]+v[2][i];
	for(int i=mn;i<n;i++){
		if(i<v[1].size())v[0].push_back(v[1][i]);
		if(i<v[2].size())v[0].push_back(v[2][i]);
	}
	sort(v[0].begin(),v[0].end());
	reverse(v[0].begin(),v[0].end());
	rep(i,v[0].size()){
		if(!sz)break;
		res+=v[0][i];
		--sz;
	}
	cout<<res<<endl;
	return 0;
}
