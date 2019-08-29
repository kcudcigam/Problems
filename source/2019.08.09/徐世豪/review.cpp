#include<iostream>
#include<cstdio>
using namespace std;
int n=2,m=1,total=1;
long long y,s=2;
long long t[100];
int book[100][100];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&y);
	t[1]=1;
	while(t[total]<y){
		total++;
		t[total]=t[total-1]*2;
		m+=s;
		n++;
		s++;
	}
	y=t[total]-y;
	total--;
	while(y){
		if(y-t[total]>=0){
			book[1][n-total]=1;
			y-=t[total];
			m--;
		}
		total--;
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(!book[i][j]) printf("%d %d\n",i,j);
	return 0;
}
