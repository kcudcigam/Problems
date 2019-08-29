#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	
	long long Y;
	cin>>Y;
	if(Y==1ll) {
		printf("2 1\n1 2");
	}
	else if(Y==2ll) {
		printf("3 3\n1 2\n2 3\n1 3");
	}
	else if(Y==3ll) {
		printf("4 5\n1 2\n2 3\n3 4\n1 3\n2 4");
	}
	else if(Y==4ll) {
		printf("4 6\n1 2\n2 3\n3 4\n1 3\n2 4\n1 4");
	}
	else if(Y==5ll) {
		printf("5 7\n1 2\n2 3\n3 4\n4 5\n1 3\n2 4\n3 5");
	}
	else {
		long long t=1ll;
		int num=2;
		while(t<Y)t*=2ll,++num;
		printf("%d %d\n",num,num*(num-1)/2);
		for(int i=1;i<num;++i)
			for(int j=1;i+j<=num;++j)
				printf("%d %d\n",j,i+j);
	}
	
	fclose(stdin);
	fclose(stdout);
}
