#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long a[]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int T;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(T);
	int op;long long mod;
	while(T--){
		read(op),read(mod);
		printf("%lld\n",a[op]%mod); 
	}
return 0;
}

