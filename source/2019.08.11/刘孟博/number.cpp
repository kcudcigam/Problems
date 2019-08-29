#include<bits/stdc++.h>
#define rg register
using namespace std;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int T,a[20],cnt,len,b[20],ans=INF;
char c[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	while(T--){
		scanf("%s",c+1),len=strlen(c+1);
		for(rg int i=1;i<=len;i++)a[i]=b[i]=c[i]-'0';
		sort(a+1,a+1+len);cnt=unique(a+1,a+1+len)-(a+1);
		if(cnt<=2)printf("1\n");
		else printf("2\n");
	}
	return 0;
}
