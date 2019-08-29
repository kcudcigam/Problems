#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int n;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[maxn],b[maxn];
int MAX1,MAX2;
int main(){
	freopen("sun.in","r",stdin);
	freopen("sun.out","w",stdout);
	int i;
	read(n);
	for(i=1;i<=n;++i){
		read(a[i]);
		b[i]=a[i]+b[i-1];
		if(b[i]<0)b[i]=0;
	}
	MAX1=b[1];
	for(i=2;i<=n;++i){
		if(b[i]>=MAX1){MAX2=MAX1;MAX1=b[i];}
	}
	printf("%d\n",MAX1+MAX2);
	return 0;
}
