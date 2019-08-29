#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=5e5+5;
int n,q,a[N],b[N];
//
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=getint();q=getint();
	rep(i,n)a[i]=getint();
	rep(i,n)b[i]=getint();
	rep(qqq,q){
		int op=getint();
		if(op==1){
			int op2=getint(),x=getint()-1,y=getint();
			if(!op2)a[x]=y;
			else b[x]=y;
		}
		else{
			int l=getint(),r=getint(),x=getint(),y=getint();
			int L=(r-l+1+y-x+1+1)/2;
			//cout<<L<<endl;
			int lb=l-1,rb=r;
			bool flag=false;
			while(rb-lb>1){
				int mid=(lb+rb)>>1;
				int pos=lower_bound(b,b+n,a[mid])-b;
				int len;
				if(pos>=y)len=y-x+1;
				else if(pos<x)len=0;
				else len=pos-x+1;
			//	cout<<mid<<" "<<pos<<" "<<len<<endl;
				if(mid-l+2+len==L){
					flag=true;
					printf("%d\n",a[mid]);
					break;
				}
				if(mid-l+2+len<L)lb=mid;
				else rb=mid;
			}
			if(flag)continue;
			//cout<<"HH"<<endl;
			lb=x-1;rb=y;
			while(rb-lb>1){
				int mid=(lb+rb)>>1;
				int pos=upper_bound(a,a+n,b[mid])-a;
				int len;
				if(pos>=r)len=r-l+1;
				else if(pos<l)len=0;
				else len=pos-l+1;
				if(mid-x+2+len<=L)lb=mid;
				else rb=mid;
			}
			printf("%d\n",b[lb]);
		}
	}
	return 0;
}
