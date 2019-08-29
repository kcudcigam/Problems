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
const int maxn=1e7+100;
unsigned long long f[maxn];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	register unsigned int ttt;
	yin>>ttt;
	while(ttt--)
	{
		register unsigned int n,p;
		yin>>n>>p;
		for(register unsigned int i=0;i^n;++i)
		{
			f[i]=(f[i-1]+i)*(i+1);
			if(i&1)
			{
				f[i]-=(i^1);
			}
			f[i]%=p;
		}
		cout<<f[n-1]<<endl;
	}
	return 0;
}
/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938

*/
