#include<bits/stdc++.h>
using namespace std;
int read(){
	int p=1,q=0;
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
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		bool flg=true;
		int lt=0,lx=0,ly=0;
		for(int i=1;i<=n;++i){
			int t=read(),x=read(),y=read();
			if((t-lt-abs(x-lx)-abs(y-ly))<0||(t-lt-abs(x-lx)-abs(y-ly))%2!=0){
				flg=false;
			}			
		}
		if(flg==true)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;		
	}
	return 0;
}
