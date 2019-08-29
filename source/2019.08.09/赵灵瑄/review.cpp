#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int y,t,n,t1;
int main(){
	freopen("review.in","r",stdin);
    freopen("review.out","w",stdout);
    read(y);
    if(y==0){
    	cout<<"1 0"<<endl;
    	return 0;
	}
	if(y==1){
    	cout<<"2 1"<<endl;
    	cout<<"1 2"<<endl;
    	return 0;
	}
	if(y==2){
		cout<<"3 3"<<endl;
		cout<<"1 2"<<endl;
		cout<<"2 3"<<endl;
		cout<<"1 3"<<endl;
		return 0;
	}
	if(y==3){
		cout<<"4 5"<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"1 4"<<endl;
		cout<<"2 4"<<endl;
		cout<<"3 4"<<endl;
		return 0;
	}
	if(y==5){
		cout<<"5 8"<<endl;
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"1 4"<<endl;
		cout<<"1 5"<<endl;
		cout<<"2 4"<<endl;
		cout<<"2 5"<<endl;
		cout<<"3 5"<<endl;
		cout<<"4 5"<<endl;
		return 0;
	}
	t=log(y)/log(2);
	t1=pow(2,t);
	if(t1==y){
		n=log(y)/log(2)+2;
		cout<<n<<' '<<n*(n-1)/2<<endl;
		for(int i=1;i<=n-1;i++)
		    for(int j=i+1;j<=n;j++)
		        cout<<i<<' '<<j<<endl;
		return 0;
	}
	   else{
	   	n=log(y)/log(2)+3;
	   	cout<<n<<' '<<n*(n-1)/2-(t1*2-y)<<endl;
	   }
	return 0;
}

