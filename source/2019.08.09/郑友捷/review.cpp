#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[70],tot,cnt;
long long y;
inline void divide(long long x){
	while(x){
		a[++tot]=(x&1);
		x>>=1;
	}
}
bool inv[70][70];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&y);
	y--;
	divide(y);
	reverse(a+1,a+tot+1);
	for(register int i=1;i<=tot;i++){
		for(register int j=i+1;j<=tot;j++){
			long long now=(1<<(tot-i))|(1<<(tot-j));
			if(now<=y){
				inv[i][j]=true;
				cnt++;
			}
		}
	}
	for(register int i=1;i<=tot;i++){
		inv[0][i]=inv[i][tot+1]=true;
		cnt+=2;
	}
	cnt++; 
	printf("%d %d\n",tot+2,cnt);
	for(register int i=0;i<=tot+1;i++){
		for(register int j=i+1;j<=tot+1;j++){
			if(inv[i][j]){
				printf("%d %d\n",i+1,j+1);
			}
		}
	}
	printf("%d %d\n",1,tot+2);
	return 0;
}
