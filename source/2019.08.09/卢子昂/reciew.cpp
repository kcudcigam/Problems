#include<bits/stdc++.h>
using namespace std;
long long y;
long long a[70];
int b[70];

int main(){
	int i,j,flag=0,n,m,cnt=1,vnt=0;
	long long k,del;
	scanf("%d",&y);	
	a[0]=1;
	for(i=1;i<=60;i++){
		a[i]=(2*a[i-1]);
		if(y==a[i]){flag=i;break;}
	}
	if(flag){
		n=flag+2;m=(n*(n-1))/2;
		printf("%d %d\n",n,m);
		for(i=1;i<=n-1;i++)
			for(j=i+1;j<=n;j++)
				printf("%d %d\n",i,j);
	}
	else{
		k=(log(y)/log(2))+1;n=k+2;
		del=a[k]-y;
		while(del){
			b[cnt]=del%2;
			if((del%2)==1)vnt++;
			del/=2;
			cnt++;
		}
		m=((n*(n-1))/2)-vnt;
		printf("%d %d\n",n,m);
		printf("1 %d\n",n);
		cnt=1;
		
		for(j=n-1;j>=2;j--){
			if(b[cnt]!=1)printf("1 %d\n",j);
			cnt++;
		}
		
		for(i=2;i<=n-1;i++)
			for(j=i+1;j<=n;j++)
				printf("%d %d\n",i,j);
	}
	return 0;
}

