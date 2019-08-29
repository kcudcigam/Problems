#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,p;
int a[15];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
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
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&p);
		printf("%d\n",a[n]%p);
	}
}
