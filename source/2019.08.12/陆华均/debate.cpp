#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	char c = getchar();
	T f = 1;
	x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	w(x);
	putchar(c);
}
priority_queue <int> qa, qb, qc;
int main(){
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	int n, s = 0;
	int ans = 0;
	read(n);
	for (int i = 1; i <= n; i ++) {
		string st;
		cin >> st;
		int x;
		read(x);
		if (st == "11") {
			ans += x;
			s ++;
		}
		else if (st == "10") {
			qa.push(x);
		}
		else if (st == "01") {
			qb.push(x);
		}
		else {
			qc.push(x);
		}
	}
	while(!qa.empty() && !qb.empty()) {
		ans += qa.top() + qb.top();
		qa.pop(); qb.pop();
	}
	if (qa.empty()) {
		while(!qb.empty() && !qc.empty() && s) {
			if (qb.top() >= qc.top()) {
				ans += qb.top();
				qb.pop();
			}
			else {
				ans += qc.top();
				qc.pop();
			}
			s --;
		}
		while(!qb.empty() && s) {
			ans += qb.top();
			qb.pop();
			s --;
		} 
		while(!qc.empty() && s) {
			ans += qc.top();
			qc.pop();
			s --;
		}
	}
	else {
		while(!qa.empty() && !qc.empty() && s) {
			if (qa.top() >= qc.top()) {
				ans += qa.top();
				qa.pop();
			}
			else {
				ans += qc.top();
				qc.pop();
			}
			s --;
		}
		while(!qa.empty() && s) {
			ans += qa.top();
			qa.pop();
			s --;
		} 
		while(!qc.empty() && s) {
			ans += qc.top();
			qc.pop();
			s --;
		}		
	}
	write(ans, '\n');
	return 0;
}


