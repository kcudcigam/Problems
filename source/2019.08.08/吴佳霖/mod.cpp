#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[maxn];
void work(long long n,long long p){
	if(a[n])printf("%d",a[n]%p);
	for(int i=2;i<=n;++i){
		int k=a[i-1]+i;
		for(int j=2;j<=i;++j){
			a[i]=k*j%p;
		}
		a[i]-=i;
		if(i!=2&&i%2==0)a[i]-=2*(i-2)/2;
	}                                                         
	while(a[n]<0){a[n]=a[n]+p;}
	printf("%d",a[n]);
}
int q;
int main(){	
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	int i;
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
	for(i=1;i<=q;++i){
		long long n;
		long long p;
		read(n);
		read(p);
		work(n,p);
	}
	return 0;
}
