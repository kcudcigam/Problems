#include<cstdio>
#include<iostream>
#include<cmath>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n;
long long m;
long long a[500005];
int l,r,s,e;
int main(){
	freoepn("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	while(m--){
		scanf("%d %d %d %d",&l,&r,&s,&e);
		int temp=(e-s)/(r-l);
		int now_plus=s;
		for(int i=l;i<=r;i++){
			a[i]+=now_plus;
			now_plus+=temp;
		}
	}
	long long ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans^a[i];
	}
	printf("%d\n",ans);
	return 0;
}
