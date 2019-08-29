#include<bits/stdc++.h>
#define enter '\n'
using namespace std;
template <class _T> inline _T read(_T &x){
	char ch=getchar(),minus=0;
	x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')ch=getchar(),minus=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	if(minus)x=-x;
	return x;
}
template <typename T>void print (const T x){
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template <typename T>inline void write(const T x){
	if (x<0) putchar('-'),print(-x);
	else print(x);
}
template <typename T>inline void writeln(const T x,const char ch){
	write(x);
	putchar(ch);
}

priority_queue<int >q1,q2,q3,q4;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		int x,y;
		read(x);
		read(y);
		int p2=x%10,p1=x/10;
		if(p2==1&&p1==1)q1.push(y);//all support
		if(p1==0&&p1==0)q2.push(y);//all against
		if(p1==1&&p2==0)q3.push(y);//only 1
		if(p1==0&&p2==1)q4.push(y);//only 2
	} 
	long long ans=0;
	while(!q1.empty()){
		int x=-1,y=-1,z=-1;
		if(!q2.empty())x=q2.top();
		if(!q3.empty())y=q3.top();
		if(!q4.empty())z=q4.top();
		if(y>-1&&z>-1){
			ans+=y+z;
			q3.pop();
			q4.pop();
			continue;
		}
		if(x>y&&x>z){
			ans+=q1.top()+x;q2.pop();
		}
		if(y>x&&y>z){
			ans+=q1.top()+y;q3.pop();
		}
		if(z>x&&z>y){
			ans+=q1.top()+z;q4.pop();
		}
		q1.pop();
	} 
	writeln(ans,enter);
	return 0;
}


