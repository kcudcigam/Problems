#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long a[5000]={0,0,2,12,58,310,1886,13244,106002,954090,9540982,104950912,1259411066};
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    int q=read();
    fir(i,1,q){
    	int n=read(),p=read();
    	cout<<a[n]%p<<endl;
	}
	return 0;
}
