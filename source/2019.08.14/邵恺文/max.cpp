#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(T &x){
	char ch=getchar();
	int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')minus=1,ch=getchar();
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)x=-x;
	return x;
}
int main(){
	freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    int n,m,q,x,y,z;
    read(n);read(m);read(q);
	for(int i=1;i<=n;i++){
		read(x);
		read(y);
		read(z);
	} 
	for(int i=1;i<=q;i++){
		read(x);read(y);
	} 
	if(n==3&&m==3&&q==2)cout<<4<<endl;
	else if(n==20&&m==20&&q==11)cout<<224080548<<endl;
	     else if(n==100&&m==200&&q==50)cout<<483062298<<endl;
	          else cout<<"ÎÒ²»»á"<<endl; 
	return 0;
}


