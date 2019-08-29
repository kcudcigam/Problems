#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=500010;
inline LL R(){
	int x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x;
}
int n,m,p1,p2,l1,r1,l2,r2;
int a[N],b[N];
void Move(int x){
	if(p1+x>r1){p2+=x;return;}
	if(p2+x>r2){p1+=x;return;}
	if(a[p1+x]<=b[p2+x])p1+=x;
	else p2+=x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=R();m=R();
	F(i,1,n)a[i]=R();
	F(i,1,n)b[i]=R();
	while(m--){
		int op=R();
		if(op==1){
			int x=R(),y=R(),z=R();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else{
			l1=R(),r1=R(),l2=R(),r2=R();
			int u=(r1-l1+r2-l2+2)/2+1;
			int ma=0;
			p1=l1-1;p2=l2-1;
			F(i,0,30)
				if((1<<i)>u){ma=i-1;break;}
				else u-=(1<<i);
			D(i,ma,0){
				if(u>=(1<<i))Move(u),u=-1;
				Move(1<<i);
			}
			int a1=a[p1],a2=b[p2];
			if(p1<l1)a1=-1;
			if(p2<l2)a2=-1;
			cout<<max(a1,a2)<<'\n';
		}
	}
	return 0;
}
