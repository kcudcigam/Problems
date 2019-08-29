#include<bits/stdc++.h>
#define RG register
#define U(x, y, z) for (RG int x = y; x <= z; ++x)
#define D(x, y, z) for (RG int x = y; x >= z; --x)
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; char c; T f = 1;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
template <typename T> inline void write(T n){
	if (n < 0){
		putchar('-');
		n = -n;
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int n, k, tot;
int a[32];
int bh[32], bl[32], bal[32];
int hh[32][32], hl[32][32], hd[32][32], hal[32][32];
vector <int> bd[32];
inline void dfs(int dep){
	if (dep > 31){
		++tot;
		if (tot == k){
			puts("Found");
			U(i, 1, 31)
				cout << a[i] << " ";
			cout << endl;
			exit(0);
		}
		return ;
	}
	if (a[dep]){
		dfs(dep + 1);
	} 
	else{
		U(i, 1, n){
			bool f = 1;
			U(j, 0, bd[dep].size() - 1)
				if (hd[bd[dep][j]][i]){
					f = 0;
					break ;
				}
			if (hl[bl[dep]][i] || hh[bh[dep]][i] || hal[bal[dep]][i]) f = 0;
			if (f == 0) continue ;
			U(j, 0, bd[dep].size() - 1)
				hd[bd[dep][j]][i] = 1;
			hl[bl[dep]][i] = hh[bh[dep]][i] = hal[bal[dep]][i] = 1;
			a[dep] = i;
			dfs(dep + 1);
			a[dep] = 0;
			U(j, 0, bd[dep].size() - 1)
				hd[bd[dep][j]][i] = 0;
			hl[bl[dep]][i] = hh[bh[dep]][i] = hal[bal[dep]][i] = 0;
		}
	}
	
}
int main(){
	FO("hexodoku");
	read(n), read(k);
	bh[1] = bh[2] = 1;
	bh[3] = bh[4] = bh[5] = bh[6] = bh[7] = 2;
	bh[8] = bh[9] = bh[10] = bh[11] = bh[12] = bh[13] = 3;
	bh[17] = bh[18] = bh[14] = bh[15] = bh[16] = 4;
	bh[19] = bh[20] = bh[21] = bh[22] = bh[23] = bh[24] = 5;
	bh[25] = bh[26] = bh[27] = bh[28] = bh[29] = 6;
	bh[30] = bh[31] = 7;
	bd[5].push_back(5);
	bd[1].push_back(5);
	bd[2].push_back(5);
	bd[4].push_back(5);
	bd[6].push_back(5);
	bd[10].push_back(5);
	bd[11].push_back(5);
	bd[9 - 6].push_back(9);
	bd[9 - 5].push_back(9);
	bd[9 - 1].push_back(9);
	bd[9 + 1].push_back(9);
	bd[9 + 5].push_back(9);
	bd[9 + 6].push_back(9);  
	bd[9].push_back(9);  
	bd[16 - 6].push_back(16);
	bd[16 - 5].push_back(16);
	bd[16 - 1].push_back(16);
	bd[16 + 1].push_back(16);
	bd[16 + 5].push_back(16);
	bd[16 + 6].push_back(16);  
	bd[16].push_back(16);  
	bd[12 - 6].push_back(12);
	bd[12 - 5].push_back(12);
	bd[12 - 1].push_back(12);
	bd[12 + 1].push_back(12);
	bd[12 + 5].push_back(12);
	bd[12 + 6].push_back(12);
	bd[12].push_back(12);  
	bd[20 - 6].push_back(20);
	bd[20 - 5].push_back(20);
	bd[20 - 1].push_back(20);
	bd[20 + 1].push_back(20);
	bd[20 + 5].push_back(20);
	bd[20 + 6].push_back(20);
	bd[20].push_back(20);  
	bd[23 - 6].push_back(23);
	bd[23 - 5].push_back(23);
	bd[23 - 1].push_back(23);
	bd[23 + 1].push_back(23);
	bd[23 + 5].push_back(23);
	bd[23 + 6].push_back(23);
	bd[23].push_back(23);  
	bd[27].push_back(27);
	bd[30].push_back(27);          
	bd[31].push_back(27);          
	bd[26].push_back(27);          
	bd[28].push_back(27);          
	bd[21].push_back(27);          
	bd[22].push_back(27);  
	bl[7] = bl[13] = 1;
	bl[2] = bl[6] = bl[12] = bl[18] = bl[24] = 2;
	bl[1] = bl[5] = bl[11] = bl[17] = bl[23] = bl[29] = 3;
	bl[4] = bl[10] = bl[16] = bl[22] = bl[28] = 4;
	bl[3] = bl[9] = bl[15] = bl[21] = bl[27] = bl[31] = 5;
	bl[8] = bl[14] = bl[20] = bl[26] = bl[30] = 6;
	bl[19] = bal[25] = 7;  
	bal[3] = bal[8] = 1;
	bal[1] = bal[4] = bal[9] = bal[14] = bal[19] = 2;
	bal[2] = bal[5] = bal[10] = bal[15] = bal[20] = bal[25] = 3;
	bal[6] = bal[11] = bal[16] = bal[21] = bal[26] = 4;
	bal[7] = bal[12] = bal[17] = bal[22] = bal[27] = bal[30] = 5;
	bal[13] = bal[18] = bal[23] = bal[28] = bal[31] = 6;
	bal[24] = bal[29] = 7;  
	U(i, 1, 31){
		read(a[i]);
		U(j, 0, bd[i].size() - 1)
			hd[bd[i][j]][a[i]] = 1;
		hal[bal[i]][a[i]] = hl[bl[i]][a[i]] = hh[bh[i]][a[i]] = 1;
	}
	dfs(1);
	puts("No way");
	return 0;
}

