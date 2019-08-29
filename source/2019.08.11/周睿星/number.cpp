#include<bits/stdc++.h>
using namespace std;
int h[10],flag=0;
int ch[100000000];
void check(int x){
	for(int i=1;i<=9;++i){
		h[i]=0;
	}
	int nu=0,t=x;
	while(x){
		if(!h[x%10]){
			nu++;
			h[x%10]=1;
		}
		x/=10;
	}
	if(nu>=3)
	flag=1;
}
long long read(){
	long long p=1,q=0;
	char ch=getchar();
	
	while(ch>'9'||ch<'0'){
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
	int T=read();	
	while(T--){
		long long n=read();
		bool flg=false;
		check(n);
		if(!flag){
			cout<<"1"<<endl;
			continue;	
		}
		flag=0;
		for(int i=1;i<=n/2;++i){
			check(i);
			check(n-i);
			if(!flg){
				cout<<"2"<<endl;
				flg=true;
				break;
			}
		}
		if(!flg)
		cout<<"3"<<endl;
	}
	return 0;
}


