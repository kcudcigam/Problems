#include<cstdio>
#include<cmath>
using namespace std;
int T,n,fx,fy,ft,flag;
int t,x,y,h;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while (T --){
		scanf("%d",&n);
		fx=0,fy=0,ft=0,flag=0;
		while (n --){
			scanf("%d%d%d",&t,&x,&y);
			h = abs(x-fx) + abs(y-fy);
			if (((t-ft)%h)%2 == 0 && (t-ft) >= h){
				fx = x;
				fy = y;
				ft = t;
			}
			else{
				flag = 1;
				printf("No\n");
				break;
			}
		}
		if (flag == 0)
			printf("Yes\n");
	}
	return 0;
}

