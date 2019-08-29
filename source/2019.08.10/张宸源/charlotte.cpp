#include<bits/stdc++.h>
#define gc() getchar()
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) (x<0?-x:x)
using namespace std;
template <typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=100005;
int dis(int x,int y,int X,int Y)
{
	return abs(x-X)+abs(y-Y);
} 
int t[N],x[N],y[N];
int n,T; 
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);
		rep(i,1,n)
		read(t[i]),read(x[i]),read(y[i]);
		t[0]=x[0]=y[0]=0;
		bool fla=1;
		rep(i,1,n)
		{
			int d=dis(x[i],y[i],x[i-1],y[i-1]);
			if(t[i]-t[i-1]<d||(t[i]-t[i-1]-d)&1)
			{
				fla=0;
				break;
			}
		}
		puts(fla?"Yes":"No");
	}
	return 0;
}


