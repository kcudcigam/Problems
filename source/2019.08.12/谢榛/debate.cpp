#include<bits/stdc++.h>
using namespace std;

void read(int &x){
	x=0;char h=' ';
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<1)+(x<<3)+h-48;
}
int n,x,sum,s,Max,ti;
priority_queue<int> q1,q2,q3;
char h1,h2;

int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++){
		h1=getchar();h2=getchar();read(x);
		if (h1=='0' && h2=='0') {q1.push(x);continue;}
		if (h1=='1' && h2=='0') {q2.push(x);continue;}
		if (h1=='0' && h2=='1') {q3.push(x);continue;}
		sum+=x;s++;
	}
	while (!q2.empty() && !q3.empty()){
		sum+=q2.top()+q3.top();
		q2.pop();q3.pop();
	}
	for (int i=1;i<=s;i++){
		Max=0;
		if (!q1.empty() && q1.top()>Max) {
			Max=q1.top();ti=1;
		}
		if (!q2.empty() && q2.top()>Max) {
			Max=q2.top();ti=2;
		}
		if (!q3.empty() && q3.top()>Max) {
			Max=q3.top();ti=3;
		}
		sum+=Max;
		if (ti==1) q1.pop();
		if (ti==2) q2.pop();
		if (ti==3) q3.pop();
	}
	cout<<sum<<endl;
	return 0;
}

