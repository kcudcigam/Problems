#include<bits/stdc++.h> 
using namespace std;
template<class T>inline void read(T&n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0'&& ch <= '9');ch = getchar())if (ch == '-')f *= -1;
	for (;ch >= '0' && ch <= '9';ch = getchar()) n = (n<<1) + (n<<3) +(ch^48);
	n *= f;
}
template<class T>inline void write(T n){
	if (n == 0)putchar('0');
	if (n < 0)n = -n,putchar('-');
	static char buf[233];int tmp = 0;
	while (n)buf[++ tmp] = n % 10 + '0', n /= 10;
	while (tmp) putchar(buf[tmp --]);
}
template<class T>inline void writeln(T n){
	write(n);
	puts("");
}
const int N = 4e5 + 10;
priority_queue<int>pq[3];
int n, ans = 0, sum1 = 0, sum2 = 0, sum = 0, h[N];
int ave(int num){
	return (int)ceil(num * 1. /2);
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for (int i = 1;i <= n;i ++){
		char ch[5];int t1, t2, num;
		scanf("%s", ch);
		read(num);
		t1 = ch[0] - '0';
		t2 = ch[1] - '0';
		if (!t1 && !t2)
			pq[0].push(num);
		else if (t1 && t2)
			ans += num, sum1 ++, sum2 ++, sum ++;
		else if (t1)
			pq[1].push(num);
		else if (t2)
			pq[2].push(num);
	}
	while (pq[1].size() && pq[2].size()){
		int t1 = pq[1].top(), t2 = pq[2].top();
		ans += pq[1].top() + pq[2].top(), 
		pq[1].pop(), pq[2].pop(), sum1 ++, sum2 ++, sum+=2;
	}
	if (pq[1].size()){
		while (pq[1].size() && pq[0].size()){
			int t1 = 0 ,t0 = 0, tmp1 = pq[1].top(), tmp0 = pq[0].top();
			if (sum1 + 1 >= ave(sum + 1) && sum2 >= ave(sum + 1))t1 = 1;
			if (sum1 >= ave(sum + 1) && sum2 >= ave(sum + 1))t0 = 1;
			if (t1 && t0){
				if (pq[1].top() >= pq[0].top())
					ans += tmp1, pq[1].pop(), sum1 ++, sum ++;
				else 
					ans += tmp0, pq[0].pop(), sum ++;
			}			
			else if (t1)
				ans += tmp1, pq[1].pop(), sum1 ++, sum ++;
			else if (t0)
				ans += tmp0, pq[0].pop(), sum ++;
			else break;
		}
	}
	else if (pq[2].size()){
		while (pq[2].size() && pq[0].size()){
			int t2 = 0 ,t0 = 0, tmp2 = pq[2].top(), tmp0 = pq[0].top();
			if (sum2 + 1 >= ave(sum + 1) && sum1 >= ave(sum + 1))t2 = 1;
			if (sum2 >= ave(sum + 1) && sum1 >= ave(sum + 1))t0 = 1;
			if (t2 && t0){
				if (pq[2].top() >= pq[0].top())
					ans += tmp2, pq[2].pop(), sum2 ++, sum ++;
				else 
					ans += tmp0, pq[0].pop(), sum ++;
			}			
			else if (t2)
				ans += tmp2, pq[2].pop(), sum2 ++, sum ++;
			else if (t0)
				ans += tmp0, pq[0].pop(), sum ++;
			else break;
		}
	}
	while (pq[0].size()){
		int tmp0 = pq[0].top();
		if (sum1 >= ave(sum + 1) && sum2 >= ave(sum + 1))
			ans += tmp0, pq[0].pop(), sum ++;
		else break;
	}
	writeln(ans);
	return 0;
}

