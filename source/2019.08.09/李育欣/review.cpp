#include<bits/stdc++.h>
using namespace std;
int y,ans,point,edge,a[1001],u[1001];
int m[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%d",&y);
	if(y==1){
		printf("1 1\n1 2");return 0;
	}
	if(y==2){
		printf("3 3\n1 2\n2 3\n1 3");return 0;
	}
	if(y==3){
		printf("4 5\n1 2\n2 4\n1 4\n1 3\n3 4");return 0;
	}
	if(y==4){
		printf("4 6\n1 2\n2 3\n3 4\n1 4\n1 3\n3 4");return 0;
	}
	if(y==5){
		printf("5 8\n1 2\n1 3\n1 4\n1 5\2 5\n3 5\n4 5\n3 4");return 0;
	}
	int g,Y,f=0,y1=y;
	while(y1!=0){
		g=0;Y=1;
		while(Y<y1){
			g++;Y*=2;
		}
		if(Y==y){
			g+=2;
			printf("%d %d\n",g,(g-1)*g/2);
			for(int i=1;i<=g;i++){
				for(int j=i+1;j<=g;j++){
					printf("%d %d\n",i,j);
				}
			}
			return 0;
		}
		if(f==0){
			f=1;point=g+2;
		}
		Y/=2;
		y1-=Y;
		edge+=((g-1)*g/2);
		if(y1=1){
			edge+=2;break;
		}
	}
	printf("%d %d\n",point,edge);
	for(int i=1;i<=point;i++){
		for(int j=i+1;j<=point;j++){
			if(j!=point-1)
			printf("%d %d\n",i,j);
		}
	}
	int now=m[point];
	for(int i=1;now<=edge;i++){
		printf("%d %d\n",i,point-1);
		if(i>=2)now+=((i+1)*1/2);
		else now+=2;
	}
	return 0;
}

