#include<bits/stdc++.h>
#define mo 998244353
#define ll long long
using namespace std;
ll n,l,ansn;
string s;
void dfs(int dep,string x){
	if (dep>n){
		int la=0,ho=0;
		while (la<l&&x[la]==s[la])la++;
		while (ho<l&&x[x.length()-ho-1]==s[l-ho-1])ho++;
		if (la+ho<l) ansn++;
	}else{
		for (int i=0;i<26;i++)dfs(dep+1,x+(char)('a'+i));
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>s;
	l=s.length();
	dfs(1,"");
	cout<<ansn<<endl;
	return 0;
}
