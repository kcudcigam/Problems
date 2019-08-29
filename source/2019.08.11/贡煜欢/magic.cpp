#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long zzc(long long a,long long p)
{
	long long ans=1,r=a;
	while (p)
	{
		if (p%2) ans=ans*r%mo;
		r=r*r%mo;
		p=p/2; 
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
    long long  n,ans=0,i;
	string st;
	cin>>n>>st;
	if (n==st.size())
	{
		cout<<zzc(26,n)-1<<endl;
		return 0; 
	}
    ans=zzc(26,n); 
	for (i=1;i<st.size();i++)
	{
		ans-=zzc(26,n-st.size());
		if (n>=st.size()+i)ans+=zzc(26,n-st.size()-i);
		if (n+i>=2*st.size())ans+=zzc(26,n-st.size()-st.size()+i);
		if (n>=2*st.size())ans-=zzc(26,n-2*st.size());
		ans=ans%mo;
	}
	ans-=zzc(26,n-st.size());
	if (n>st.size()) ans-=zzc(26,n-st.size());
	if (n>=2*st.size()) ans+=zzc(26,n-2*st.size());
	ans=ans%mo;
	cout<<ans<<endl; 
	return 0;
}


