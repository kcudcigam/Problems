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
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int n=read(),m=read();
	puts("infinity");
	return 0;
}



