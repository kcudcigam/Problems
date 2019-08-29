#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
int Num;
int n,m1,m2;
ll mod=1e9+7;
ll ans;

int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d",&Num);
	scanf("%d%d%d",&n,&m1,&m2);
	if(m1==n-1||m2==n-1){
		puts("0"); return 0;
	}
	if(m1==1||m2==1){
		ll tot=1;
		for(rint i=1;i<=n;++i) tot*=i;
		ll minus=1;
		for(rint i=1;i<=n-2;++i) minus=2*(minus*i);
		ans=(tot-minus)%p;
		cout<<ans<<'\n';
		return 0;
	}
	if(n==1){
		puts("0"); return 0;
	}
	else if(n==2){
		pits("0"); return 0;
	}
	return 0;
}










