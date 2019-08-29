#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int A[2][N],C[N];
int n,m;
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
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();m=read();
    for(int i=1;i<=n;i++)A[0][i]=read();
	for(int i=1;i<=n;i++)A[1][i]=read();
	while(m--){
		int flag=read();
		if(flag==1){
			int x=read(),y=read(),z=read();
			A[x][y]=z;
		}
		else{
			int L=read(),R=read(),l=read(),r=read();
			int mid=(R+r-L-l+2)/2+1;
			int ans=0;
			for(int i=1;i<=mid;i++){
				if(l>r||L<=R&&A[1][L]<A[0][l])ans=A[1][L++];
				else ans=A[0][l++];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

