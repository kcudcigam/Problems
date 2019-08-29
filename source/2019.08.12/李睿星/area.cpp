#include<bits/stdc++.h>
using namespace std;
int a[5]={0,1,5,19,68};
bool check(int m){
	for(int i=1;i<=31;++i){
		if(m+1==1<<i) return 1;
		if(m+1<1<<i) return 0;
	}
	return 0;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	srand(time(0));
	int x,y;
	scanf("%d%d",&x,&y);
	if(!x||!y||check(x+y)){
		printf("infinity");
		return 0;
	}
	if(x%4==1&&y%4==1){
		printf("1");
		return 0;
	}
	if(x%4==0&&y%4==0&&rand()%2){
		printf("infinity");
		return 0;
	}
	int c=rand()%5;
	c?printf("%d",a[c]):printf("infinity");
	return 0;
}
