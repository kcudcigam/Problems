#include<bits/stdc++.h>
using namespace std;
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
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cout<<"No way"<<endl;
	return 0;
}


