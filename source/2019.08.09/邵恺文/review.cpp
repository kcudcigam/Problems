#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int a[100];
long long Y,nY=1;
int mi;
template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
int spe(int x){
	if(x==mi+2)return mi+3;
	else return x;
}
void print(int x){
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++)
		  cout<<spe(i)<<' '<<spe(j)<<endl;
	}
}                                                                                                                                                                                   
bool check(long long x){
	for(int i=1;i<=mi;i++)nY=nY*2;
	if(nY==x)return true;
	else return false;
}
int log2(long long x){
	int t=0;
	while(x>1){
		x=x/2;
		t++;
	}
	return t;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(Y);
	mi=log2(Y);
	if(check(Y)){
		int n=mi+2;
		cout<<n<<' '<<(1+(n-1))*(n-1)/2<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			cout<<i<<' '<<j<<endl;
		}
	}
	else{
		int n=mi+3,m=1,tot=0,t=0;
		int cha=Y-nY;
		while(cha>0){
		    tot++;
			a[tot]=cha%2;
			if(a[tot]==1)t++;
			cha=cha/2;	
		}
		cout<<n<<' '<<(1+(n-2))*(n-2)/2+t+1<<endl;
		print(mi+2);
		cout<<mi+2<<' '<<mi+3<<endl;
		for(int i=1;i<=tot;i++){
			if(a[i]==1){
				cout<<i+1<<' '<<mi+2<<endl;
			}
		}
	}
	return 0;
}


