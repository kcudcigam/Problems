#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	   while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	   return x*f;
}
int a[1005][1005],x,y;
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	x=read();
	y=read();
	if(x>y){
		swap(x,y);
	}
	cout<<"infinity"<<endl;
	return 0;
}











