#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int f[100];
inline int ch(int x){
	memset(f,0,sizeof(f));
	while(x)f[x%10]=1,x/=10;
	int sum=0;
	fir(i,0,9)sum+=f[i];
	if(sum<=2)return 1;
	return 0;
}
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
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int t=read();
    fir(i,1,t){
    	int n=read(),ans=3;
    	if(ch(n))ans=1;
    	else fir(i,1,n>>1)
    	        if(ch(i)&&ch(n-i)){
    	    	    ans=2;
    	    	    break;
			    }
		cout<<ans<<endl;
	}
	return 0;
}
