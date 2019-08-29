#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long T,n;
struct eve{
	long long t,x,y;
} q[100010];
bool cmp(eve a,eve b){
	return a.t<b.t;
}
long long Abs(long long a){
	return a>0?a:-a;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			read(q[i].t);read(q[i].x);read(q[i].y);
		}
		sort(q+1,q+1+n,cmp);
		bool fl=0;
		for(int i=1;i<=n;i++){
			if((q[i].t&1)^((q[i].x+q[i].y)&1)){
				fl=1;break;
			} 
			if(Abs(q[i].x-q[i-1].x)+Abs(q[i].y-q[i-1].y)>q[i].t-q[i-1].t){
				fl=1;break;
			}
		}
		if(fl) printf("No\n");
		else printf("Yes\n");
	}
	return 0; 
} 
