#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1001],b[1001],c[1001],flag,Ans,q,p;
void Search(int step){
	if (step == n){
		if (!flag){
			flag =1;
			for (int i = 1; i <= n; ++ i)
				c[i] = a[i];
		}
		else{
			for (int i = 1; i <= n; ++ i){
				if (a[i] != c[i])
					Ans ++;
				c[i] = a[i];
			}
			Ans = Ans % p;
		}
		return;
	}
	for (int i = 1; i <= n; ++ i)
		if (!b[i]){
			a[step+1] = i;
			b[i] = 1;
			Search(step+1);
			b[i] = 0;
		}
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%d",&q);
	while(q --){
		scanf("%d%d",&n,&p);
		flag = 0;
		Ans = 0;
		for (int i = 1; i <= n; ++ i){
			a[1] = i;
			b[i] = 1;
			Search(1);
			b[i] = 0;
		}
		printf("%d\n",Ans%p);
	}
}
