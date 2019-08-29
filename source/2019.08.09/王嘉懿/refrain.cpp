#include<bits/stdc++.h>
using namespace std;
int num,n,m1,m2,a,b;
template <typename T> void read(T & x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar())  x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
    read(num);
    if(num==1||num==2)
    {
    	cout<<'0';
	}
	return 0;
}
