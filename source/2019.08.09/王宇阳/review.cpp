#include<bits/stdc++.h>
using namespace std;
long long y;
long long n,m;
long long pic[100005][2];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
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
		cout<<"2 3"<<endl;
		cout<<"3 4"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 4"<<endl;
		return 0;
	}
	if(y==5){
		cout<<"5 7"<<endl;
		cout<<"1 2"<<endl;
		cout<<"2 3"<<endl;
		cout<<"3 4"<<endl;
		cout<<"4 5"<<endl;
		cout<<"1 3"<<endl;
		cout<<"3 5"<<endl;
		cout<<"1 5"<<endl;
		return 0;
	}
	if(log2(y)==(int)log2(y)){
		n=log2(y)+2;
		cout<<n<<' ';
		m=0;
		for(int i=1;i<n;i++){
			m+=i;
		}
		cout<<m<<endl;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<i<<' '<<j<<endl;
			}
		}
		return 0;
	}else{
		n=(int)log2(y)+3;
	}
	cout<<n<<' ';
	n--;
	m=0;
	for(int i=1;i<n;i++){
		m+=i;
	}
	int num=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			pic[++num][1]=i;
			pic[num][2]=j;
		}
	}
	m++;
	long long cy=1; 
	for(int i=1;i<=n-2;i++){
		cy*=2;
	}
	long long k=y-cy;
	int t=0;
	n++;
	while(k!=0){
		t++;
		int x=k%2;
		if(x==1){
			if(t!=1){
				pic[++num][1]=t;
				pic[num][2]=n;
				m++;
			}else{
				pic[++num][1]=1;
				pic[num][2]=n;
				m++;
			}	
		}
		k=k/2;
	}
	cout<<m<<endl;
	for(int i=1;i<=num;i++){
		cout<<pic[i][1]<<' '<<pic[i][2]<<endl;
	}
	cout<<n-1<<' '<<n<<endl;
	return 0;
} 

