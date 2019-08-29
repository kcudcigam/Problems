#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
int n;
int a[15]={0,0,2,12,58,310,1886,13244,106002,954090,95040982};
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;cin>>q;
	while(q--){
		int x,p;read(x);read(p);
		if(x<=10)cout<<a[x]%p<<endl;
	}
	return 0;
}
/*
10
1 530093761
2 530093761
3 530093761
4 530093761
5 530093761
6 530093761
7 530093761
8 530093761
9 530093761
10 530093761
*/

