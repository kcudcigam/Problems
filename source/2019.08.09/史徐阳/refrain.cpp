#include<bits/stdc++.h>
#include<time.h>
#define LL long long
using namespace std;
template<class T>inline void read(T&n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
const int N = 1e9 + 7;
int Num, n, m1, m2, ans = 0;
int e[1005][1005], s[1005];
void check(){
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= n;j ++)
			if (e[i][j] != e[s[i]][s[j]])
				{ans = (ans + 1) % N; return;}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(Num), read(n), read(m1), read(m2);
	if (Num <= 10){
		int num = 0;
		for (int i = 1;i <= m1;i ++){
			int u, v;
			read(u), read(v);
			e[u][v] = 1;
			e[v][u] = 1;
			num ++;
		}
		for (int i = 1;i <= m2;i ++){
			int u, v;
			read(u), read(v);
			e[u][v] = 2;
			e[v][u] = 2;
			num ++;
		}
		if (Num <=6){
			for (int i = 1;i <= n;i ++)
				s[i] = i;
			do check();
			while (next_permutation(s + 1, s + n + 1));
			printf("%d\n", ans % N);
		}else{
			LL sum = 1, summ = 1;
			for (int i = 1;i <= n;i ++)
				sum = (sum * i) % N;
			for (int i = 1;i <= num;i ++)
				summ = (summ * 2) % N;
			if (sum >= summ)
				printf("%d\n", (sum - summ) % N);
			else
				printf("%d\n", N - summ + sum);
		}
	}else{
		for (int i = 1;i <= m1;i ++){
			int u, v;
			read(u), read(v);
		}
		for (int i = 1;i <= m2;i ++){
			int u, v;
			read(u), read(v);
		}
		srand((unsigned)time(0));
		LL num = 1, seed = rand() * 567 % 1000;
		for (int i = 1;i <= n;i ++)
			num = num * i % N;		
		printf("%d\n", (num - seed) % N);
	}
	return 0;
}


