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
long long n,a[100101],ans[100101];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	yin>>n;
	for(int i=1;i<=n;i++)
	{
		yin>>a[i];
	}
	ans[1]=a[1];
	long long b=a[1];
	for(int i=2;i<=n;i++)
	{
		if(b>0)b+=a[i];
		else b=a[i];
		ans[i]=max(ans[i-1],b);
	}
	b=a[n];
	long long sum=b+ans[n-1];
	for(int i=n-1;i>=1;i--)
	{
		if(b>0)b+=a[i];
		else b=a[i];
		sum=max(sum,b+ans[i-1]);
	}
	cout<<sum<<endl;
	return 0;
}

