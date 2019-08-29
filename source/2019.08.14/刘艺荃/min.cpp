#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar();while(isdigit(ch));
	x=f*r;
}
int n,A,B,C,D,minn=INT_MAX,maxn=0,sum=0;
int cal(int x){
	return A*x*x*x+B*x*x+C*x+D;
}
signed main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;i++){
		int x;read(x);
		minn=min(minn,x);
		sum+=cal(x);
	}
	int cal1=cal(minn);
	cout<<max(cal1,sum)<<endl;
	return 0;
}
/*
5 0 0 1 10
9 9 5 2 6

ABC
A>0&&B>0&&C>0 ZENG
A>0&&B<0&&C>0 ZENG
A<0&&B>0&&C>0 JIAN
A<0&&B<0&&C>0 ZENG
A>0&&B>0&&C<0 ZENG
A>0&&B<0&&C<0 ZENG
A<0&&B>0&&C<0 JIAN
A<0&&B<0&&C<0 JIAN
*/
