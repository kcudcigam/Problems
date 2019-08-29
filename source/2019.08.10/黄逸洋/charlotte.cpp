#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
struct Point{
	int x,y;
};
int Juli(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
bool check(){
	int n;
	read(n);
	int t_now=0;
	Point now=(Point){0,0};
	for(int i=1;i<=n;i++){
		int t,x,y;
		read(t);read(x);read(y);
		Point dest=(Point){x,y};
		
		int needed=Juli(now,dest);
		if(needed>t-t_now)return false;
		
		int more=t-t_now-needed;
		if(more%2)return false;
	}
	return true;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);

	int T;
	read(T);
	while(T--){
		if(check())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	return 0;
}


