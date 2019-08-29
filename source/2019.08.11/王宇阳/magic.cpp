#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
string st,s;
long long n,ans;
void dfs(int dep){
	if(dep==n){
		int t=0;
		for(int i=0;i<n;i++){
			if(st[i]==s[t]){
				t++;
			}
		}
		if(t==(s.size()-1)){
			ans++;
			ans=ans%998244353;
		}
		return ;
	}
	int k=0;
	while(k!=25){
		st=st+char(k+'a');
		dfs(dep+1);
		st.erase(st.size(),1);
		k++;
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	cin>>s;
	bool f=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='a'){
			f=0;
			break;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			ans=(ans*25)%998244353;	
		}
		return 0;
	}else{
		dfs(1);
		cout<<ans<<endl;
	}
		
	return 0;
}


