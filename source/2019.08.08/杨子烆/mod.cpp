#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;read(q);
	long long ans;
	long long n,p;
	for(int i=1;i<=q;i++){
		read(n);read(p);ans=0;
		for(int j=2;j<=n;j++){
			ans=(j%2==0)?((ans+j-2)*j+2)%p:((ans+j-1)*j)%p;
		}
		printf("%lld\n",ans);
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
