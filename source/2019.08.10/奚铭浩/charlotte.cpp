#include<bits/stdc++.h>
using namespace std;
void main2();
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	scanf("%d",&T);
	
	while(T--){
		main2();
	}
	return 0;
}
struct Info{
	int Time;
	int x,y;
}a;
void main2(){
	int n;
	scanf("%d",&n);
	
	a.Time=a.x=a.y=0;
	for(int i=1;i<=n;++i){
		Info b;
		scanf("%d %d %d",&b.Time,&b.x,&b.y);
		
		if(abs(a.x-b.x)+abs(a.y-b.y)>(b.Time-a.Time)||((a.x+a.y+b.x+b.y+a.Time+b.Time)%2!=0)){
			puts("No");
			return;
		}
		
		a=b;
	}
	
	puts("Yes");
	return;
}

