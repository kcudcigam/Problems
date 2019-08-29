#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int Ans;
struct xym{
	int a,b,c;
}x[400005];
int cmp(xym a,xym b){
	return a.c < b.c;
}
int n;
char s[5];
int tot1,tot2,cnt1,cnt2;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i){
		cin>>s;
		x[i].a = (int)(s[0]-'0');
		x[i].b = (int)(s[1]-'0');
		scanf("%d",&x[i].c);
		if (x[i].a == 1)
			tot1 ++;
		if (x[i].b == 1)
			tot2 ++;
		Ans += x[i].c;
	}
	cnt1 = n-tot1;
	cnt2 = n-tot2;
	if (tot1 >= cnt1 && tot2 >= cnt2){
		printf("%d",Ans);
		return 0;
	}
	sort(x+1,x+1+n,cmp);
	for (int i = 1; i <= n; ++ i){
		if (tot1 >= cnt1 && tot2 >= cnt2)
			break;
		if (x[i].a&&x[i].b)
			continue;
		if (!x[i].a&&!x[i].b){
			Ans -= x[i].c;
			cnt1 --;
			cnt2 --;
		}
		else{
			if (x[i].a&&!x[i].b&&tot1>=cnt1+1){
				Ans -= x[i].c;
				tot1 --;
				cnt2 --;
			}
			else
				if (!x[i].a&&x[i].b&&tot2>=cnt2+1){
					Ans -= x[i].c;
					tot2 --;
					cnt1 --;
				}
		}
	}
	printf("%d",Ans);
	return 0;
}
/*
7
11 18
00 20
11 32
00 16
00 25
01 30
10 21
*/








