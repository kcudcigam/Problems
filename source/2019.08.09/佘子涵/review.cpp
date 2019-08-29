#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long y,f[6500],s[6500],tot,now,ans;
bool nop[6500];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(y);
	if(y==1){
		printf("2 1\n1 2\n");
		return 0;
	}
	if(y==2){
		printf("3 3\n1 2\n1 3\n2 3\n");
		return 0;
	}
	f[1]=0;f[2]=1;f[3]=2;
	s[1]=0;s[2]=1;s[3]=3;
	tot=3;
	while(f[tot]<y){
		f[tot+1]=s[tot]+1;
		s[tot+1]=s[tot]+f[tot+1];
		tot++;
	}
	ans=(tot-1)*tot/2;
	if(f[tot]==y){
		printf("%lld %lld\n",tot,ans);
		for(int i=1;i<tot;i++){
			for(int j=i+1;j<=tot;j++){
				printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
	now=tot;
	while(f[tot]>y){
		if(f[tot]-f[now]>=y){
			f[tot]-=f[now];
			ans--;
			nop[now]=1;
		}
		now--;
	}
	printf("%lld %lld\n",tot,ans);
	for(int i=1;i<tot;i++){
		for(int j=i+1;j<=tot;j++){
			if(i==1&&nop[j]) continue;
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}
