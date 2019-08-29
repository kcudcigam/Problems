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
const int t[10] = {0, -6, -5, -1, 0, 1, 5, 6};
int k, n, num = 0, s[50], h[50];
int group[10][10], rgroup[35][10];
/*bool check(int p){
	for (int i = 1;i <= 7;i ++)
		for (int j = i + 1;j <= 7;j ++)
			if (s[p + t[i]]&&s[p + t[j]]&&s[p + t[i]] == s[p + t[j]])
				return 0;
	return 1;
}
void dfs(int dep){
	if (dep > 31){
		num ++;
		if (num == n){
			puts("Found");
			for (int i = 1;i <= 31;i ++){
				if (i > 1)putchar(' ');
				write(s[i]);
			}
			puts("");exit(0);	
		}
	}
	if (s[dep]){
		dfs(dep + 1);
	}else{
		if (dep == 5||dep == 9||dep == 12||dep == 16||dep == 20||dep == 23||dep == 27)
			if (!check(dep)) return;
		for (int i = 1;i <= k;i ++){
			s[dep] = i;
			dfs(dep + 1);
			s[dep] = 0;
		}
	}
}
void inti(){
	gruop[1][1] = 1;
	gruop[1][2] = 2;
	gruop[1][3] = 4;
	gruop[1][4] = 5;
	gruop[1][5] = 6;
	gruop[1][6] = 10;
	gruop[1][7] = 11;
	gruop[2][1] = 3;
	gruop[2][2] = 4;
	gruop[2][3] = 8;
	gruop[2][4] = 9;
	gruop[2][5] = 10;
	gruop[2][6] = 14;
	gruop[2][7] = 15;
	gruop[3][1] = 10;
	gruop[3][2] = 11;
	gruop[3][3] = 15;
	gruop[3][4] = 16;
	gruop[3][5] = 17;
	gruop[3][6] = 21;
	gruop[3][7] = 22;
	gruop[4][1] = 6;
	gruop[4][2] = 7;
	gruop[4][3] = 11;
	gruop[4][4] = 12;
	gruop[4][5] = 13;
	gruop[4][6] = 17;
	gruop[4][7] = 18;
	gruop[5][1] = 14;
	gruop[5][2] = 15;
	gruop[5][3] = 19;
	gruop[5][4] = 20;
	gruop[5][5] = 21;
	gruop[5][6] = 25;
	gruop[5][7] = 26;
	gruop[6][1] = 21;
	gruop[6][2] = 22;
	gruop[6][3] = 26;
	gruop[6][4] = 27;
	gruop[6][5] = 28;
	gruop[6][6] = 30;
	gruop[6][7] = 31;
	gruop[7][1] = 17;
	gruop[7][2] = 18;
	gruop[7][3] = 22;
	gruop[7][4] = 23;
	gruop[7][5] = 24;
	gruop[7][6] = 28;
	gruop[7][7] = 29;
	
	rgroup[1][1] = 1;
	rgroup[2][1] = 1;
	rgroup[3][1] = 2;
	rgroup[4][1] = 1;
	rgroup[4][2] = 2;
	rgroup[5][1] = 1;
	rgroup[6][1] = 1;
	rgroup[6][2] = 4;
	rgroup[7][1] = 4;
	rgroup[9][1] = 2;
	rgroup[10][1] = 1;
	rgroup[10][2] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
	rgroup[1][1] = 1;
*/
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	read(k), read(n);
	for (int i = 1;i <= n;i ++)
		read(s[i]);
	puts("No way");
	return 0;
}

