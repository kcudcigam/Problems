#include<bits/stdc++.h>
using namespace std;
int jj(int k){
	int s=0;
	for(int i=1;i<=k;++i){
		s+=i;
	}
	return s;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long y;
	scanf("%lld",&y);
	
	if(y==1){
		puts("2 1");
		puts("1 2");
		exit(0);
	}
	if(y==2){
		puts("3 3");
		puts("1 2");
		puts("2 3");
		puts("1 3");
		exit(0);
	}
	
	if(y<=100){
		int k=64;
		printf("%d %lld\n",k,k+y-2);
		
		for(int i=1;i<k;++i){
			printf("%d %d\n",i,i+1);
		}
		int l=0;
		for(int i=1;i<k-1;++i){
			for(int j=2;j<=k-i;++j){
				l++;
				printf("%d %d\n",i,i+j);
				if(l==y-1){
					exit(0);
				}
			}
		}
	}
	
	int k=2;long long y2=y;
	bool flg=true;
	while(y2!=1){
		if(y2%2!=0)flg=false;
		y2/=2;
		++k;
	}
	if(flg){
		printf("%d %d\n",k,jj(k-1));
		for(int i=1;i<k;++i){
			for(int j=i+1;j<=k;++j){
				printf("%d %d\n",i,j);
			}
		}
		exit(0);
	}
	printf("%d %lld\n",k,k+y-2);
	
	for(int i=1;i<k;++i){
		printf("%d %d\n",i,i+1);
	}
	int l=0;
	for(int i=1;i<k-1;++i){
		for(int j=2;j<=k-i;++j){
			l++;
			printf("%d %d\n",i,i+j);
		}
	}
	return 0;
}


