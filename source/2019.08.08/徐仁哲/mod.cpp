#pragma GCC optimise("O2") 
#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long a[10000001];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	long long p;
	read(q);
	a[1]=0;
	a[2]=2;
	a[3]=12;
	a[4]=58;
	a[5]=310;
	a[6]=1886;
	a[7]=13244;
	a[8]=106002;
	a[9]=954090;
	a[10]=9540982;
	for(int i=1;i<=q;i++){
		long long n,p;
		read(n);
		read(p);
		if(n<=10) cout<<a[n]%p<<endl;
		else{
			for(int j=11;j<=n;j++){
				if(j&1==0) a[j]=(a[j-1]*j+j*(j-1))%p;
				else a[j]=(a[j-1]*j+j*(j-2)+2)%p;
			}
			cout<<a[n]<<endl;
		}
	}
	return 0;
}

