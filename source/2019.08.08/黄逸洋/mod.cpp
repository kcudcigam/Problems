#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);

	long long T;
	read(T);
	while(T--){
		long long n,q;
		read(n);read(q);
		
		long long ans=0;
		for(long long i=2;i<=n;i++){
			if(i%2==0){
				long long tmp=1;
				for(long long j=i+1;j<=n;j++){
					tmp=tmp*j%q;
				}
				ans=(ans+tmp*i%q)%q;
			}else{
				long long tmp=i-1;
				for(long long j=i+1;j<=n;j++){
					if(j==i+1)tmp=tmp*(j+1)%q;
					else tmp=tmp*j%q;
				}
				ans=(ans+tmp*i%q)%q;
			}
		}
		writeln(ans);
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

