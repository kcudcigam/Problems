#include<bits/stdc++.h>
using namespace std;
struct io{
	template <typename T> void read1(T &x){
		int f=1;x=0;char c=getchar();
		for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
		for (; isdigit(c);c=getchar()) x=x*10+c -'0';
		x*=f;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
const int maxn=5*1e5+100;
int n,m;
long long sum[maxn],del[maxn],sum1[maxn],del1[maxn];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	yin>>n>>m;
	while(m--)
	{
		int l,r;
		long long s,e;
		yin>>l>>r>>s>>e;
		sum1[l]+=s;
		sum1[r+1]-=s;
		del1[l]+=(e-s)/(r-l);
		del1[r]-=(e-s)/(r-l);
		del1[r]-=(e-s);
		del1[r+1]+=(e-s);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+sum1[i];
		del[i]=del[i-1]+del1[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]+=del[i-1];
		del[i]+=del[i-1];
		ans^=sum[i];
	}
	cout<<ans<<endl;
	return 0;
}
