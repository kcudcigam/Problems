#include<bits/stdc++.h>
using namespace std;
int n,ans,A[100010],S[100010],Ma[100010],Mi[100010],Mx[100010];
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
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)A[i]=read();
	S[1]=A[1];
    for(int i=2;i<=n;i++)S[i]=A[i]+S[i-1];
    Ma[n]=Mi[n]=n;
    for(int i=n-1;i;i--)Ma[i]=S[i]>S[Ma[i+1]]?i:Ma[i+1];
    for(int i=n-1;i;i--)Mi[i]=S[i]<=S[Mi[i+1]]?i:Mi[i+1];   
    for(int i=1;i<=n;i++)Mx[i]=S[i]<=S[Mx[i-1]]?i:Mx[i-1];
    for(int B=2;B<n;B++){
    	int A=Mx[B-2],C=Mi[B],D=Ma[C+1];
        ans=max(ans,S[D]-S[A]-S[C]+S[B-1]);
	}
	cout<<ans<<endl;
	return 0; 
}
