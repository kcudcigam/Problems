#include<bits/stdc++.h>
using namespace std;
priority_queue<int> ly;
priority_queue<int> ll;
priority_queue<int> yl;
int zcy;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int a,x;long long ans=0;
	read(a);
	string s;
	for(int i=1;i<=a;i++){
		cin>>s;
		read(x);
		if(s=="00"){
			ll.push(x);
		}
		if(s=="10")yl.push(x);
		if(s=="01")ly.push(x);
		if(s=="11"){
			zcy+=1;
			ans+=x;
		}
	}
	while(yl.size()&&ly.size()){
		ans+=yl.top();
		ans+=ly.top();
		yl.pop();
		ly.pop();
	}
	if(ly.size()){
		while(zcy&&ly.size()&&ll.size()){
			if(ly.top()>ll.top()){
				ans+=ly.top();ly.pop();zcy--;
			}
			if(ll.top()>=ly.top()){
				ans+=ll.top();ll.pop();zcy--;
			}
		}
		if(zcy!=0){
			if(ly.size()){
				while(zcy&&ly.size()){
					ans+=ly.top();ly.pop();zcy--;
				}
			}
			else{
				while(zcy&&ll.size()){
					ans+=ll.top();ll.pop();zcy--;
				}
			}
		}
	}
	else{
			while(zcy&&yl.size()&&ll.size()){
			if(yl.top()>ll.top()){
				ans+=yl.top();ly.pop();zcy--;
			}
			if(ll.top()>=yl.top()){
				ans+=ll.top();ll.pop();zcy--;
			}
		}
		if(zcy!=0){
			if(yl.size()){
				while(zcy&&yl.size()){
					ans+=yl.top();yl.pop();zcy--;
				}
			}
			else{
				while(zcy&&ll.size()){
					ans+=ll.top();ll.pop();zcy--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


