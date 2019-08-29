#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T=read();
	while(T--){
		int x=0,y=0,last=0;
		bool flg=1;
		int n=read();
		for(int i=1;i<=n;i++){
			int t=read(),g_x=read(),g_y=read();
			if(abs(g_x-x)+abs(g_y-y)>t-last)flg=0;
			else if((t-last-(abs(g_x-x)+abs(g_y-y)))&1)flg=0;
			x=g_x,y=g_y,last=t;
		}
		if(flg)puts("Yes");
		else puts("No");
	}
	return 0;
}


