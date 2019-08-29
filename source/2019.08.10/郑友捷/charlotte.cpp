#include<cstdio> 
#include<algorithm>
using namespace std;
inline int jd(int x){
	if(x>=0) return x;
	else return -x;
}
int t,n;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool flag=false;
		int lt=0,lx=0,ly=0;
		for(register int i=1;i<=n;i++){
			int ti,x,y;
			scanf("%d%d%d",&ti,&x,&y);
			int nx=jd(x-lx),ny=jd(y-ly);
			int now=(ti-lt)-(nx+ny);
			if((now%2==0&&now>=0)){
				lt=ti;
				lx=x;
				ly=y;
			}
			else {
				flag=true;
			}
		}
		if(flag){
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
}
