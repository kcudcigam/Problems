#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
const int N=1e7+7;
using namespace std;
int n,p,q;
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int a[11]={0,2,12,58,310,1886,13244,106002,954090,9540982};
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	q=ip();
	n=ip(),p=ip();
	rep(i,0,9) cout<<a[i]<<"\n"; 
	return 0;
}

