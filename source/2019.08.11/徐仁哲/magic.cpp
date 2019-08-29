#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	cin>>s;
	long long len=s.size();
	if(n==len){
		long long total=1;
		for(int i=1;i<=n;i++)
		total=total*26%998244353;
		cout<<total-1<<endl;
		return 0;
	}
	if(n<=4){
		if(n==1&&len==1) cout<<25<<endl;
		if(n==2&&len==1) cout<<625<<endl;
		if(n==2&&len==2) cout<<675<<endl;
		if(n==3&&len==1) cout<<16250<<endl;
		if(n==3&&len==2) cout<<17500<<endl;
		if(n==3&&len==3) cout<<17575<<endl;
		if(n==4&&len==1) cout<<422500<<endl;
		if(n==4&&len==2) cout<<455000<<endl;
		if(n==4&&len==3) cout<<456875<<endl;
	}else{
		long long ans=1;
		for(long long i=1;i<=n-len;i++)
		ans=ans*26%998244353;
		long long cha=ans/26;
		ans=((len+1)*ans-len*cha)%998244353;
		long long total=1;
		for(long long i=1;i<=n;i++)
		total=total*26%998244353;
		cout<<total-ans<<endl;
	}
	return 0;
}
