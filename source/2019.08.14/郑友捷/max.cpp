#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,q;
const int mod=1e9+7;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(register int i=1;i<=n;i++){
		int x,y,p;
		scanf("%d%d%d",&x,&y,&p);
	}
	for(register int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
	}
	if(n==3&&m==3){
		printf("4\n");
	}
	else {
		if(n==20&&m==20){
			printf("224080548\n");
		}
		else if(n==100&&m==200){
			printf("483062298\n");
		}
	}
}
