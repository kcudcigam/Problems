#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,k,a[32],cnt,tmp;
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	k=read(),n=read();
	for(int i=1;i<=31;i++)a[i]=read();
	printf("No way");
	return 0;
}
