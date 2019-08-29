#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
const int maxn=4001001;
int n,w3[maxn],w2[maxn],w1[maxn];
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
	int j00,j10,j20,j30;
	long long ans=0;
	yin>>n;
	j00=j10=j20=j30=0;
	for(int i=1;i<=n;i++)
	{
		int a,w;
		yin>>a>>w;
		if(a==11)ans+=w,++j00;
		if(a==10)w1[++j10]=w;
		if(a==1)w2[++j20]=w;
		if(a==0)w3[++j30]=w;
	}
	sort(w1+1,w1+j10+1,greater<int>());
	sort(w2+1,w2+j20+1,greater<int>());
	for(int i=1;i<=min(j10,j20);i++)
		ans+=w2[i]+w1[i];
	for(int i=min(j10,j20)+1;i<=j10;i++)w3[++j30]=w1[i];
	for(int i=min(j10,j20)+1;i<=j20;i++)w3[++j30]=w2[i];
	sort(w3+1,w3+j30+1,greater<int>());
	for(int i=1;i<=j00;i++)ans+=w3[i];
	cout<<ans<<endl;	      	
	return 0;
}

