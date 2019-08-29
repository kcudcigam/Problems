#include<bits/stdc++.h>
using namespace std;
long long Y;
int N,M;
long long Lg[65];
int ans[65];
void work1(int x){
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++){
			printf("%d %d\n",i,j);
		}
	}
}
void work2(long long x){
	int num;
	for(int i=2;i<N;i++)if(x<Lg[i]){num=i-1;break;}
	while(x){
		while(x<Lg[num])num--;
		ans[++ans[0]]=num;
		M++;
		x-=Lg[num];
	}
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
/*	if(Y<64){
		n=Y+1;m=(Y<<1)-1;
		cout<<n<<" "<<m<<endl;
		for(long long i=1;i<n;i++)prlong longf("%lld %lld\n",i,i+1);
		for(long long i=3;i<=n;i++)prlong longf("1 %lld\n",i);
		exit(0);
	}*/
	Lg[1]=Lg[2]=1;
	for(int i=2;i<=64;i++){
		Lg[i]=Lg[i-1]<<1;
		if(Y<=Lg[i]){cout<<i<<endl;N=i;break;}
	}
	if(Y==Lg[N]){
		cout<<N<<endl;
		M=(N*(N-1))/2;
		cout<<M<<endl;
		printf("%d %d\n",N,M);
	    work1(N);exit(0);
	}
	N--;
	M=(N*(N-1))/2;
	long long n=Y-Lg[N];
	ans[++ans[0]]=N;
	M++;
	N++;
	work2(n);
	printf("%d %d\n",N,M);
	work1(N-1);
	for(int i=1;i<=ans[0];i++)
	printf("%d %d\n",ans[i],N);
	return 0;
}
