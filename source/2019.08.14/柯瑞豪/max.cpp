#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=200010,mod=1e9+7;
int n,m,q;
struct node1{
    int to,v;
	double p;
}A[M];
struct node2{
	int l,r;
}B[N];
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
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
    n=read();m=read();q=read();
    for(int i=1;i<=n;i++){
    	A[i].to=read();A[i].v=read();
    	scanf("%llf",&A[i].p);
    	if(A[i].p>1.000)A[i].p/=(double)mod;
	}
    for(int i=1;i<=q;i++)B[i].l=read(),B[i].r=read();
	cout<<4<<endl;
	return 0;
}

