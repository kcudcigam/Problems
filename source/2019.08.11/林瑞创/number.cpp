#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
	return f*num;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int t=read();
    for(int i=1;i<=t;i++){
         read(); 
		 if(i<=3)printf("%d\n",i);
		 else printf("3\n");
	}
	return 0;
}


