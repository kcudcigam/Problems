#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans=0;
bool cheak(string st){
	int t=s.size();
	int c=0;
	while(st[c]==s[c]&&t){
		t--;
		c++;
	}
	c=st.size()-1;
	int g=s.size()-1;
	while(st[c]==s[g]&&t){
		c--;
		g--;
		t--;
	}
	return t;
}
void dfs(int dep,string st){
	if(dep>n){
		if(cheak(st)){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=0;i<26;i++){
		dfs(dep+1,st+char(i+'a'));
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>s;
	if(n<=10){
		dfs(1,"");
		cout<<ans<<endl;
	}
	return 0;
}
