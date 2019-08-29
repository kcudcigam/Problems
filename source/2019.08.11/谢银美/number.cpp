#include<cstdio>
#include<cstring>
using namespace std;
int T,n,s,tot;
int book[500005],flag,pd[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for (int i = 10; i <= 300005; ++ i){
		int h = i;
		tot = 0;
		memset(pd,0,sizeof(pd));
		while (h){
			s = h%10;
			if (!pd[s]){
				pd[s] = 1;
				tot ++;
			}
			h /= 10;
		}
		if (tot == 2)
			book[i] = 1;
	}
	while (T --){
		scanf("%d",&n);
		if (book[n])
			printf("1\n");
		else{
			flag = 0;
			for (int i = 10; i <= n/2; ++ i)
				if (book[i] && book[n-i]){
					printf("2\n");
					flag = 1;
					break;
				}
			if (flag == 0)
				printf("0\n");
		}
				
	}
	return 0;
}

