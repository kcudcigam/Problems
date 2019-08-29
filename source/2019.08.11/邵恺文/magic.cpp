#include<bits/stdc++.h>
using namespace std;
string s,ts;
long long n;
long long ans=0;
const int p=998244353;
template <typename _Tp> inline _Tp read(_Tp&x){
    char c11=getchar(),minu=0;x=0;
    while(c11^'-'&&!isdigit(c11))c11=getchar();
	if(c11=='-')c11=getchar(),minu=1;
    while(isdigit(c11)){
    	x=x*10+c11-'0';
		c11=getchar();
	}
	if(minu)x=-x;
	return x;
}
int sum(int n){
	long long t=1;
	for(int i=1;i<=n;i++)
	   t=(t*26)%p;
	return t%p;
}
void dfs(int t,string st){
	if(t>n){
		int z=0,w=n-1,l=s.size()-1;
		while(st[z]==s[z])z++;
		while(st[w]==s[l])w--,l--,z++;
		if(z<s.size())ans++;
		return;
	}
	for(int i=0;i<26;i++)dfs(t+1,st+char(i+'a'));
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	cin>>s;
	if(s.size()==n)cout<<sum(n)-1<<endl;
	else{
	    if(n<=4){
	        dfs(1,"");
			cout<<ans<<endl;
		}
		else{
			int l=s.size();
			long long an=(l+1)*sum(n-l)%p;
			an=(sum(n)-an+l)%p;
			cout<<an<<endl;
		}		
	}
	return 0;
}


