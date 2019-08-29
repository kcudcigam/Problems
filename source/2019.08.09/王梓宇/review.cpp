#include<bits/stdc++.h>
using namespace std;
long long  Y;
int sum[105];
long long inv[70];
void case_1(){
	cout<<"2 1"<<endl;
	cout<<"1 2";
	return;
}
void case_2(){
	cout<<"3 3"<<endl;
	cout<<"1 2"<<endl;
	cout<<"2 3"<<endl;
	cout<<"1 3"<<endl;return;
}
void case_3(){
	cout<<"4 5"<<endl;
	cout<<"1 2"<<endl;
	cout<<"1 3"<<endl;
	cout<<"1 4"<<endl;
	cout<<"2 4"<<endl;
	cout<<"3 4"<<endl;return;
}
void case_4(){
	cout<<"4 6"<<endl;
	cout<<"1 2"<<endl;
	cout<<"1 3"<<endl;
	cout<<"1 4"<<endl;
	cout<<"2 3"<<endl;
	cout<<"2 4"<<endl;
	cout<<"3 4"<<endl;return;
}
void case_5(){
	cout<<"5 7"<<endl;
	cout<<"1 2"<<endl;
	cout<<"1 3"<<endl;
	cout<<"1 4"<<endl;
	cout<<"1 5"<<endl;
	cout<<"2 5"<<endl;
	cout<<"3 4"<<endl;
	cout<<"4 5"<<endl;return;
}
void qvq_1(){
	int n_1=Y+2,m_1=Y*2;
	printf("%d %d\n",n_1,m_1);
	for(int i=2;i<=Y+1;++i){
		printf("1 %d\n",i);
	}
	for(int i=2;i<=Y+1;++i){
		printf("%d %d\n",i,n_1);
	}
	return;
}
void qvq_2(){
	queue<int>q;
	int n_2=2,m_2=0;
	while(Y){
		for(int i=100;i>=1;--i){
		if(sum[i]<=Y){
			q.push(i);
		
			Y-=sum[i];
			n_2+=i;
			m_2=m_2+i*2+(i-1);
		}
	}
	}
	printf("%d %d\n",n_2,m_2);
	int be_2=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=x;++i){
			printf("1 %d\n",be_2+i);
		}
		for(int i=1;i<x;++i){
			printf("%d %d\n",be_2+i,be_2+i+1);
		}
		for(int i=1;i<=x;++i){
			printf("%d %d\n",be_2+i,n_2);
		}
		be_2+=x;
	}
	return;
}
int fuck(long long x){
	if(x%2==1){
		return -1;
	}
	for(int i=3;i<=60;++i){
		if(inv[i]==x){
			return i;
		}
		if(inv[i]>x){
			return -1;
		}
	}
	return -1;
}
void qvq_3(int x){
	printf("%d %d\n",x,x*(x-1)/2);
	for(int i=1;i<=x;++i){
		for(int j=i+1;j<=x;++j){
			printf("%d %d\n",i,j);
		}
	}
}
void qvq_4(){
	int be=0,tot=0;
	for(int i=1;i<=62;++i){
		if(inv[i]>Y){
			be=i;
			break;
		}
	}
	int usb[100];memset(usb,0,sizeof(usb));
	long long cha=inv[be]-Y;
	for(int i=2;i<be;++i){
		if(cha>=inv[be-i-1]){
			usb[i]=1;
			cha-=inv[be-i-1];
		}
	}
	for(int i=2;i<=be;++i){
		if(!usb[i]){
			tot++;
		}
	}
	for(int i=2;i<=be;++i){
		for(int j=i+1;j<=be;++j){
			tot++;
		}
	}
	cout<<be<<" "<<tot<<endl;
	for(int i=2;i<=be;++i){
		if(!usb[i]){
			printf("1 %d\n",i);
		}
	}
	for(int i=2;i<=be;++i){
		for(int j=i+1;j<=be;++j){
			printf("%d %d\n",i,j);
		}
	}
	
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	sum[1]=1;
	for(int i=2;i<=100;++i){
		sum[i]=sum[i-1]+i;
	}
	inv[0]=1;
	for(int i=1;i<=62;++i){
		inv[i]=inv[i-1]*2;
	}
	scanf("%lld",&Y);
	if(Y==1){case_1();return 0;}
	if(Y==2){case_2();return 0;}
	if(Y==3){case_3();return 0;}
	if(Y==4){case_4();return 0;}
	if(Y==5){case_5();return 0;}
	if(Y<=50){
		qvq_1();
		return 0;
	}
	if(fuck(Y)!=-1){
		qvq_3(fuck(Y)+2);
		return 0;
	}
	qvq_2();
	if(Y>1000000000){
		qvq_4();
	}
		return 0;
	
	return 0;
}

