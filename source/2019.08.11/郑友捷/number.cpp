#include<cstdio>
#include<algorithm>
using namespace std;
int t,cnt;
long long n;
bool inv[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		for(register int i=0;i<=9;i++) inv[i]=true;
		cnt=0;
		long long now=n;
		while(now){
			if(!inv[now%10]){
				inv[now%10]=true;
				cnt++;
			}
			now/=10;
		}
		if(cnt<=2){
			printf("1\n");
		}
		else {
			printf("2\n");
		}
	}
} 
