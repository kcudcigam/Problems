#include<bits/stdc++.h>
using namespace std;
long long a[9],ans[20];
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'&&ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x=read(),y=read();
	if(x%4==2&&y%4==2){
		cout<<"1"<<endl;
	}
	else cout<<"infinity"<<endl;
	return 0;
}
/*
*/

