#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 3e1 + 5;
int num[N];
int k, n;
long long in1[N], in2[N], in3[N];
long long vis1[10], vis2[10], vis3[10], vis_ar[N];
vector <int> in_ar[N];

int p[N], tot;

namespace Prework
{
	int Fir;
	inline void Around(int dep)
	{
		int now = Fir;
		for (int i = 1; i <= 7; i++)
		{
			in_ar[now].push_back(dep);
			if (i == 2)
			{
				if (dep == 1) now += 2;
				else now += 4;
			}
			else if (i == 5) 
			{
				if (dep == 7) now += 2;
				else now += 4;
			}
			else now++; 
		}
	}
	inline void divide1(int dep, int len)
	{
		int now = Fir;
		for (int i = 1; i <= len; i++)
		{
			in1[now] = dep;
			now++;
		}
	}
	inline void divide2()
	{
		in2[3] = in2[8] = 1;
		in2[1] = in2[4] = in2[9] = in2[14] = in2[19] = 2;
		in2[2] = in2[5] = in2[10] = in2[15] = in2[20] = in2[25] = 3;
		in2[6] = in2[11] = in2[16] = in2[21] = in2[26] = 4;
		in2[7] = in2[12] = in2[17] = in2[22] = in2[27] = in2[30] = 5;
		in2[13] = in2[18] = in2[23] = in2[28] = in2[31] = 6;
		in2[24] = in2[29] = 7;
	}
	inline void divide3()
	{
		in3[19] = in3[25] = 1;
		in3[8] = in3[14] = in3[20] = in3[26] = in3[30] = 2;
		in3[3] = in3[9] = in3[15] = in3[21] = in3[27] = in3[31] = 3;
		in3[4] = in3[10] = in3[16] = in3[22] = in3[28] = 4;
		in3[1] = in3[5] = in3[11] = in3[17] = in3[23] = in3[29] = 5;
		in3[2] = in3[6] = in3[12] = in3[18] = in3[24] = 6;
		in3[7] = in3[13] = 7;
	}
	inline void solve()
	{
		Fir = 1; Around(1);
		Fir = 3; Around(2);
		Fir = 6; Around(3);
		Fir = 10; Around(4);
		Fir = 14; Around(5);
		Fir = 17; Around(6);
		Fir = 21; Around(7);
		
		Fir = 1; divide1(1, 2);
		Fir = 3; divide1(2, 5);
		Fir = 8; divide1(3, 6);
		Fir = 14; divide1(4, 5);
		Fir = 19; divide1(5, 6);
		Fir = 25; divide1(6, 5);
		Fir = 30; divide1(7, 2);
		
		divide2(); divide3();
	}
}
namespace Calc_Ans
{
	int sum = 0;
	inline void print()
	{
		puts("Found");
		for (int i = 1; i <= 30; i++) printf("%d ", num[i]);
		printf("%d\n", num[31]);
	}
	inline void add(int dep, int i)
	{
		num[p[dep]] = i;
		vis1[in1[p[dep]]] += (1 << i);
		vis2[in2[p[dep]]] += (1 << i);
		vis3[in3[p[dep]]] += (1 << i);
		for (int j = 0; j < in_ar[p[dep]].size(); j++)
		vis_ar[in_ar[p[dep]][j]] += (1 << i);
	}
	inline void del(int dep, int i)
	{
		num[p[dep]] = 0;
		vis1[in1[p[dep]]] -= (1 << i);
		vis2[in2[p[dep]]] -= (1 << i);
		vis3[in3[p[dep]]] -= (1 << i);
		for (int j = 0; j < in_ar[p[dep]].size(); j++)
		vis_ar[in_ar[p[dep]][j]] -= (1 << i);
	}
	inline void dfs(int dep)
	{
		if (dep > tot)
		{
			sum++;
			if (sum == n)
			{
				print();
				exit(0);
			}
			return;
		}
		
		long long now = (vis1[in1[p[dep]]] | vis2[in2[p[dep]]]);
		now |= vis3[in3[p[dep]]];
		
		for (int i = 0; i < in_ar[p[dep]].size(); i++)
		now |= vis_ar[in_ar[p[dep]][i]];
		
		for (int i = 1; i <= k; i++)
		if (((1 << i) & now) == 0)
		{
			add(dep, i);
			dfs(dep + 1);
			del(dep, i);
		}
	}
}
using namespace Prework;
using namespace Calc_Ans;
int main(){
	freopen ("hexodoku.in", "r", stdin);
	freopen ("hexodoku.out", "w", stdout);
	read(k); read(n);
	
	Prework::solve();
	
	for (int i = 1; i <= 31; i++)
	{
		read(num[i]);
		if (!num[i]) p[++tot] = i;
		else 
		{
			vis1[in1[i]] += (1 << num[i]);
			vis2[in2[i]] += (1 << num[i]);
			vis3[in3[i]] += (1 << num[i]);
			for (int j = 0; j < in_ar[i].size(); j++)
			vis_ar[in_ar[i][j]] += (1 << num[i]);
		}
	}
	Calc_Ans::dfs(1);
	
	puts("No way");
  return 0;
}
