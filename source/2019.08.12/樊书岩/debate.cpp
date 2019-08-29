#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define ULL unsigned long long
using namespace std;
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
const int maxn = 400040;
int n, ans = 0;
int a[maxn], op1[maxn], op2[maxn], tot1 = 0, tot2 = 0;
struct node {
	int id, val;
};
bool operator < (const node &a, const node &b) {
	return a.val < b.val;
}
priority_queue<node> Heap[4];
void bf(int dep, int p1, int p2, int tot, int cans) {
//	cout << dep << " " << p1 << " " << p2 << " " << tot << " " << cans << endl; 
	if(dep == n) {
		if(p1 * 2 >= tot && p2 * 2 >= tot) {
	//		cout << dep << " " << p1 << " " << p2 << " " << tot << " " << ans << endl;
			ans = max(ans, cans);
		}
		return;
	} 
	bf(dep + 1, p1, p2, tot, cans);
	bf(dep + 1, p1 + op1[dep + 1], p2 + op2[dep + 1], tot + 1, cans + a[dep + 1]);
}
int main() {
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	read(n);
	_rep(i, 1, n) {
		int x;
		read(x); read(a[i]);
		op1[i] = x / 10;
		op2[i] = x % 10;
		tot1 += op1[i], tot2 += op2[i];
	//	ans += a[i];
		node temp;
		temp.id = i; temp.val = a[i];
		Heap[op1[i] * 2 + op2[i]].push(temp);
	}
	int maxp = min(n, min(tot1, tot2) * 2);
	int c = 0, k1 = 0, k2 = 0;
	while(!Heap[3].empty()) {
		node u = Heap[3].top();
		Heap[3].pop();
		ans += u.val;
		c++;
		k1++, k2++;
	//	cout << c << " " << ans << endl;
	}
	
	if(tot1 < tot2) {
		while(!Heap[2].empty()) {
			node u = Heap[2].top();
			Heap[2].pop();
			ans += u.val;
			c++;
			k1++;
		}
		while(k2 < maxp / 2 && !Heap[1].empty()) {
			node u = Heap[1].top();
			Heap[1].pop();
			ans += u.val;
			c++; k2++;
		}
		while(c < maxp && (!Heap[0].empty() || !Heap[1].empty())) {
			node u, v;
			u.id = 0, u.val = 0, v.val = 0, v.id = 0; 
			int maxn = 0;
			if(!Heap[0].empty()) {u = Heap[0].top(); maxn = max(maxn, u.val);}
			if(!Heap[1].empty()) {v = Heap[1].top(); maxn = max(maxn, v.val);}
			Heap[u.val > v.val ? 0 : 1].pop();
			ans += maxn;
			c++;
		}
		
	} else {
		while(!Heap[1].empty()) {
			node u = Heap[1].top();
			Heap[1].pop();
			ans += u.val;
			c++; k2++;
		//	cout << c << " " << u.id << " " << ans << endl; 
		}
		while(k1 < maxp / 2 && !Heap[2].empty()) {
			node u = Heap[2].top();
			Heap[2].pop();
			ans += u.val;
			c++; k1++;
		//	cout << c << " " << u.id << " " << ans << endl;
		}
		while(c < maxp && (!Heap[0].empty() || !Heap[2].empty())) {
			node u, v;
			u.id = 0, u.val = 0, v.val = 0, v.id = 0; 
			int maxn = 0;
			if(!Heap[0].empty()) {u = Heap[0].top(); maxn = max(maxn, u.val);}
			if(!Heap[2].empty()) {v = Heap[2].top(); maxn = max(maxn, v.val);}
			Heap[u.val > v.val ? 0 : 2].pop();
			ans += maxn;
			c++;
		//	cout << c << " " << v.id << " " << ans << endl;
		}
	//	cout << c << endl;
	}
	writesp(ans);
//	int res = n;
//	while((tot1 * 2 < res || tot2 * 2 < res) && (Heap[3].size() || Heap[2].size() || Heap[1].size() || Heap[0].size())) {
//		node u = Heap.top();
//		Heap.pop();
//		int id = u.id;
//		cout << tot1 << " " << tot2 << " " << res << endl;
//		writesp(u.id, ' '); writesp(u.val);
//		if(tot1 * 2 < res && op1[id] == 1) continue;
//		if(tot2 * 2 < res && op2[id] == 1) continue;
//		ans -= u.val;
//		tot1 -= op1[id]; tot2 -= op2[id];
//		res -= 1;
//		
//	}
//	cout << tot1 << " " << tot2 << " " << res << endl;
//	writesp(ans);	
	
	return 0;
}

