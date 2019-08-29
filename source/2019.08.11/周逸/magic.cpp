#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,len,num=1;
string s,t;
bool judge(){
	int i,j,k;
	bool flag=0;
	for(i=0;i<n;i++){
		j=n+i+2-len;
		for(k=0;k<=i;k++)
			if(t[k]!=s[k])
				flag=1;
		if(!flag)
			return 1;
		flag=0;
		for(k=n;k>=j;k--)
			if(t[k]!=s[k+len-n])
				flag=1;
		if(!flag)
			return 1;
		flag=0;
		for(i=1;i<=len;i++)
			if(s[i]!=t[i])
				flag=1;
		if(!flag)
			return 1;
		flag=0;
		for(i=n;i>n-len;i--)
			if(s[i+len-n]!=t[i])
				flag=1;
		if(!flag)
			return 1;
		flag=0;
	}
	return 0;
}
int dfs(int cur){
	int cnt=0,i;
	if(cur==n+1)
		if(judge())
			return 1;
	for(i=0;i<26;i++){
		t+='a'+i;
		cnt+=dfs(cur+1);
	}
	return cnt;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int i;
	cin>>n>>s;
	len=s.size();
	for(i=1;i<=n;i++)
		num=num*26%mod;
	if(len==n){
		printf("%d",((num-1)%mod+mod)%mod);
		return 0;
	}
	num-=dfs(1);
	num=(num%mod+mod)%mod;
	printf("%d",num);
	return 0;
}


