#include<bits/stdc++.h>
using namespace std;
unsigned long long f[11111111];
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
	int q;
	read(q);
	f[1]=0;
	int rct=1;
	for (int l=0;l<q;l++){
		int n,p;
		read(n);
		read(p);
		for (int k=rct+1;k<=n;k++){
			int mi=k-2;
			if (k&1){
				mi=0;
			}
			f[k]=k*(f[k-1]+k-1)-mi;
		}
		cout<<f[n]%p<<endl;
		if (n>rct){
			rct=n;
		}
	}
	return 0;
}


