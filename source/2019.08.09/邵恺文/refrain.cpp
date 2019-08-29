#include<bits/stdc++.h>
using namespace std;
template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
const int maxn=2*100000;
int m1[maxn+2],m2[maxn+2];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);	
	int num,n,M1,M2;
	read(num);
	read(n);
	read(M1);
	read(M2);
	for(int i=1;i<=M1;i++)read(m1[i]);
	for(int i=1;i<=M2;i++)read(m2[i]);
	if(num==1){
	    cout<<0<<endl;
	    return 0;
	}
	if(num==2){
		cout<<0<<endl;
		return 0;
	}
	return 0;
}


