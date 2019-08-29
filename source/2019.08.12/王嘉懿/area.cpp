#include<bits/stdc++.h>
using namespace std;
int x,y;
template <typename T>void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
   read(x);read(y);
   x++;y++;
   
   if(x%4==2&&y%4==2)
   { cout<<1;return 0;}
   
    if(x==1||y==1||(x==2&&y%2==1)||(y==2&&x%2==1))
   { cout<<"infinity";return 0;}
   
   if(x%8==2&&y%8==2||x%8==4||x%8==1&&y%8==4)
   {cout<<5;return 0;}
   
   cout<<"infinity";return 0;
} 
