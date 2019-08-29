#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
long long power(int x){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans=(ans*26)%MOD;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	read(n);
	string st;
	cin>>st;
	
	bool flag=true;
	for(int i=0;i<st.size();i++){
		if(st[i]!='a')flag=false;
	}
	if(flag){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*25)%MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	long long ans=power(n);
	if(n==st.size()){
		cout<<ans-1<<endl;
	}else{
		if(n>=2*st.size()){
			cout<<(ans-2*power(n-st.size())+power(n-2*st.size()))%MOD<<endl;
		}else{
			bool flg=true;
			for(int i=0;i<2*st.size()-n;i++){
				if(st[i]!=st[i+2*st.size()-n+1])flg=false;
			}
			if(flg){
				cout<<(ans-2*power(st.size())+2)%MOD<<endl;
			}else{
				cout<<(ans-2*power(st.size()))%MOD<<endl;
			}
		}
	}
	return 0;
}

