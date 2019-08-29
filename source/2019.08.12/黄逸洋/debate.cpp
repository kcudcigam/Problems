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
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
priority_queue<int>q11,q10,q01,q00;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);

	int n;
	read(n);
	for(int i=1;i<=n;i++){
		int opt,x;
		read(opt);read(x);
		if(opt==11)q11.push(x);
		if(opt==10)q10.push(x);
		if(opt==01)q01.push(x);
		if(opt==00)q00.push(x);
	}
	
	int t01=0,t02=0,ans=0;
	while(!q11.empty()){
		ans+=q11.top();q11.pop();
		t01++;t02++;
	} 
	while(!q10.empty()&&!q01.empty()){
		ans+=q10.top()+q01.top();
		q10.pop();q01.pop();
	}
	
	while(!q10.empty()){
		q00.push(q10.top());q10.pop();
	}
	while(!q01.empty()){
		q00.push(q01.top());q01.pop();
	}
	
	while(t01&&t02){
		ans+=q00.top();q00.pop();
		t01--;t02--;
	}
	
	writeln(ans);
	return 0;
}


