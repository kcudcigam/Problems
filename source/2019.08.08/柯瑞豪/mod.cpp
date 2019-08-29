#include<bits/stdc++.h>
using namespace std;
int n,q,p,ans;
int A[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int Ans[11];
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
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
    q=read();
    for(int i=1;i<=q;i++){
    	n=read();p=read();
    	Ans[i]=A[n]%p;
	}
	for(int i=1;i<=q;i++)cout<<Ans[i]<<endl;
    return 0;
}
