#include<bits/stdc++.h>
using namespace std;
int a[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int read(){
	int p=1,q=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
		p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("mod","r",stdin);
	freopen("mod","w",stdout);
	int q;
	q=read();
	while(q--){
		int n,p,ans=0;
		n=read();
		p=read();
		cout<<a[n]%p<<endl;
	}
	return 0;
}


