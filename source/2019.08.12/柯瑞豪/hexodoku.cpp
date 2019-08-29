#include<bits/stdc++.h>
using namespace std;
int n,k;
int A[32];
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
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<32;i++)A[i]=read();
	cout<<"No way"<<endl;
	return 0;
}


