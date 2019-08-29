#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,bo,t[111111],x[111111],y[111111],T;
int read(){
	char ch;
	int num=0;
	ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	for(int i=1;i<=T;++i){
		n=read();
		bo=0;
		for(int j=1;j<=n;++j){
			t[j]=read();
			x[j]=read();
			y[j]=read();
		}
		for(int j=1;j<=n;++j){
			if((abs(x[j]-x[j-1])+abs(y[j]-y[j-1]))>(t[j]-t[j-1])){
				bo=1;
			}
			else if(((t[j]-t[j-1])-abs(x[j]-x[j-1])-abs(y[j]-y[j-1]))%2==1){
				bo=1;
			}
			if(bo==1){
				break;
			}
		}
		if(bo==0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
