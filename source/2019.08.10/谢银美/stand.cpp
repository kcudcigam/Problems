#include<cstdio>
using namespace std;
int n,m;
int a[10],l[300],r[300],flag;
int tot,cnt,Max;
int Ans,y;
bool book[300];
int b[10000005];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= 5; ++ i)
		scanf("%d",&a[i]);
	for (int i = 1; i <= n; ++ i){
		scanf("%d%d",&l[i],&r[i]);
		if (l[i]!=1||r[i]!=m)
			flag = 1;
	}
	if (!flag){
		tot = 1;
		for (int i = 1; i <= 5; ++ i){
			tot *= n;
			Ans += tot*a[i];
		}
		printf("%d",Ans);
		return 0;
	}
	else{
		for (int i = 1; i <= n; ++ i)
			for (int  j = l[i]; j <= r[i]; ++ j)
				b[j] ++;
		while (cnt < n){
			Max = 0;
			for (int i = 1; i <= m; ++ i)
				if (Max < b[i]){
					Max = b[i];
					y = i;
				}
			tot = 1;
			cnt += Max;
			for (int i = 1; i <= 5; ++ i){
				tot *= Max;
				Ans += tot*a[i];
			}
			for (int i = 1; i <= n; ++ i)
				if (l[i] <= y && r[i] >= y && !book[i]){
					book[i] = 1;
					for (int j = l[i]; j <= r[i]; ++ j)
						b[j] --;
				}
		}
		printf("%d",Ans);
	}
	return 0;
}


