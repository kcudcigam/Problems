#include<bits/stdc++.h>
#define N 110
using namespace std;
int k,p[N],a[N],t[N],ans;
bool flag;
bool check(){
	for(int i=1;i<=4;i++){
		t[i]=a[i];
	}
	map<string,bool>mp;
	flag=1;
	string st="";
	for(int i=1;i<=4;i++){
		st+='0'+t[i];
	}
	mp[st]=1;
	while(flag){
		flag=0;
		for(int i=1;i<=4;i++){
			if(t[i]!=0){
				t[i]-=1;
				if(t[i]){
					for(int j=1;j<=4;j++){
						if(t[j]==0){
							t[j]=p[t[i]];
							break;
						}
					}
				}else{
					flag=1;
				}
			}
		}
		if(flag==0){
			return 0;
		}
		string s="";
		for(int i=1;i<=4;i++){
			s+='0'+t[i];
		}
		if(s=="0000")return 0;
		if(mp[s]==0){
			mp[s]=1;
		}else{
			return 1;
		}
	}
	return 0;
}
void dfs(int dep){
	if(dep>4){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=0;i<=k;i++){
		a[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	cin>>k;
	for(int i=1;i<k;i++){
		cin>>p[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

