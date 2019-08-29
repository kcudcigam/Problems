#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
struct eve{
	int x,y,z;
} q[100010];
int n,m,w;
long long ans,mod=1e9+7;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	read(n);read(m);read(w);
	for(int i=1;i<=m;i++){
		read(q[i].x);read(q[i].y);read(q[i].z);
		ans+=q[i].y*q[i].z%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
