#include<bits/stdc++.h>
using namespace std;
int ri(){
	char c=getchar();
	int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)-'0'+c;
	return x;
}
int a[500010],b[500010];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n=ri(),m=ri(),f1,f2,l1,l2,r1,r2,k1,k2,k3,c;
	for(int i=1;i<=n;i++)a[i]=ri();
	for(int i=1;i<=n;i++)b[i]=ri();
	for(int i=1;i<=m;i++){
		f1=ri();
		if(f1==1){
			f2=ri();
			l1=ri();
			l2=ri();
			if(f2)b[l1]=l2;
			else a[l1]=l2;
		}
		else{
			l1=ri();
			r1=ri();
			l2=ri();
			r2=ri();
			k1=l1;
			k2=l2;
			k3=0;
			while(k1<=r1||k2<=r2){
				k3++;
				if(k1>r1||a[k1]>=b[k2]){
					c=b[k2];
					k2++;
				}
				else{
					c=a[k1];
					k1++;
				}
				if(k3==(r1+r2-l1-l2+3)/2){
					printf("%d\n",c);
					break;
				}
			}
		}
	}
	return 0;
}
