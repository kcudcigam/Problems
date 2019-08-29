#include<bits/stdc++.h>
using namespace std;
long long Y,n,m,a[20000];
bool MAP[17000][17000];
void write(){
	cout<<n<<" "<<m<<endl;
		for(int ii=1;ii<=n;++ii)
			for(int jj=ii+1;jj<=n;++jj)
				if(MAP[ii][jj]==false)
					cout<<ii<<" "<<jj<<endl;
}
void deal(int x,int num){
	int i=1;
	while(num){
		if(num%2==1){
			m--;
			MAP[i][x]=true;
		}
		i++;
		num/=2;
	}
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);	
	
	cin>>Y;
	a[1]=1,a[2]=1;
	for(int i=2;i<=20000;++i){
		if(i!=2) a[i]=a[i-1]*2;
		if(a[i]==Y){
			n=i;
			m=i*(i-1)/2;
			write();
		}
		if(a[i]>Y){
			n=i;
			m=i*(i-1)/2;
			break;
		}
	}
	
	deal(n,a[n]-Y);

	write();
	return 0;
} 
