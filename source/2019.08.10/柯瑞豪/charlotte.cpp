#include<bits/stdc++.h>
using namespace std;
struct node{
	int t,x,y;
}A[100010];
int T,n;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
bool work(){
	for(int i=1;i<=n;i++){
		int T=A[i].t-A[i-1].t;
		int d=abs(A[i].x+A[i].y-A[i-1].x-A[i-1].y);
		if(T<d)return 0;
		if((T+d)%2==1)return 0;
	}
	return 1;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	A[0].t=0;A[0].x=0,A[0].y=0;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			A[i].t=read();A[i].x=read();A[i].y=read();
		}
		if(work())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
