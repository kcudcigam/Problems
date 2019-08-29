#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[1000];
inline int ch(int n){
	int x=n;
	while(x%2==0)x>>=1;
	if(x==1)return 1;
	else return 0;
}
int main(){
	freopen("review","r",stdin);
    freopen("review","w",stdout);
	long long y;
	cin>>y;
	long long x=1;
	int n=2;
	while(x<y)x<<=1,n++;
    if(y==3)cout<<"4 5"<<endl<<"1 2"<<endl<<"1 3"<<endl<<"1 4"<<endl<<"2 4"<<endl<<"3 4"<<endl;
    if(y==5)cout<<"5 8"<<endl<<"1 2"<<endl<<"1 3"<<endl<<"1 4"<<endl<<"1 5"<<endl<<"2 3"<<endl<<"2 5"<<endl<<"3 5"<<endl<<"4 5"<<endl;
    if(ch(y)){//y=2^n
    	int m=n*(n-1)/2;
    	cout<<n<<' '<<m<<endl;
    	fir(i,1,n-1)
    	    fir(j,i+1,n)
    	        cout<<i<<' '<<j<<endl;
	}
	if(!ch(y)&&y>5){
		int m=(n-1)*(n-2)/2;
		int s=1;
		fir(i,1,n-3)s*=2;
		memset(a,0,sizeof(a));
		for(int i=n-1;i>1;i--,s>>=1)
		    if(y>=s)y-=s,m++,a[i]=1;
		cout<<n<<' '<<m<<endl;
		fir(i,1,n-2)
		    fir(j,i+1,n-1)
		        cout<<i<<' '<<j<<endl;
		fir(i,2,n-1)
		    if(a[i])cout<<i<<' '<<n<<endl;
	}
	return 0;
}
