#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 200000
using namespace std;
struct info{
	int t,x,y;
}a[N];
bool cmp(info x,info y){
	return x.t<y.t;
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
    freopen("charlotte.in","r",stdin);
    freopen("charlotte.out","w",stdout);
    int T=read();
    fir(i,1,T){
    	a[0].t=0,a[0].x=0,a[0].y=0;
    	int n=read();
    	fir(j,1,n)a[j].t=read(),a[j].x=read(),a[j].y=read();
    	sort(a+1,a+n+1,cmp);
    	int flg=1;
    	fir(j,1,n){
    		int s=abs(a[j].x-a[j-1].x)+abs(a[j].y-a[j-1].y),dt=a[j].t-a[j-1].t;
    		if(dt<s||(dt-s)%2){
    			flg=0;
    			break;
			}
		}
		if(flg)puts("Yes");
		else puts("No");
	}
	return 0;
}
