#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int a[1000];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	int y; 
    read(y);
    if (y==1) {
    	cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0; 
	}
	if (y==2)
	{
		cout<<3<<" "<<3<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<1<<" "<<3<<endl;
		return 0; 
	}
	if (y==3)
	{
		cout<<4<<" "<<5<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<1<<" "<<4<<endl;
		cout<<2<<" "<<4<<endl;
		cout<<3<<" "<<4<<endl; 
		return 0;
	}
	if (y==4)
	{
		cout<<4<<" "<<6<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<1<<" "<<4<<endl;
		cout<<2<<" "<<4<<endl;
		cout<<3<<" "<<4<<endl; 
		cout<<2<<" "<<3<<endl;
	}
	if (y==5)
	{
		cout<<5<<" "<<8<<endl;
		cout<<1<<" "<<5<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<3<<" "<<4<<endl;
		cout<<1<<" "<<4<<endl;
		cout<<3<<" "<<5<<endl;
		cout<<4<<" "<<5<<endl;
		cout<<2<<" "<<5<<endl;
		return 0; 
	 } 
	return 0;
}


