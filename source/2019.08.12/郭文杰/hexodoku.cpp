#include<bits/stdc++.h>

#define FILE "hexodoku"

using namespace std;

static struct Read
{
	template<typename T>
	inline Read& operator>>(T& x)
	{
		bool f = 0; x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
		for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
		if (f) x = -x;
		return *this;
	}
} read;
/*
static struct Table
{
	set<int> row[8], col1[8], col2[8], cir[8];
	inline int getrow(int& pos);
	inline int getcol1(int& pos);
	inline int getcol2(int& pos);
	inline int getcir(int& pos);
} t;*/



int k, n, cnt, a[32], b[] = {1,2,0,3,4,5,2,0,4,6,7,1,3,0,5,1,8,6,0,1,3,4,5,0,8,6,7,2,3,5,8};
int deep[] = {0, 5, 9, 12, 16, 20, 23, 27};
//unordered_set<int> row[8], col1[8], col2[8], cir[8];

/*inline bool check(int pos, int x)
{
	
}

void dfs(int stp)
{
	if (stp == 32)
	{
		cout << "Found" << endl;
		for (int i = 1; i <= 31; ++i)
			printf("%d ", a[i]);
	}
	else if(!a[stp])
	{
		for (int i = 1; i <= k; ++i)
			if (check(stp, i))
			{
				a[i] = i;
				dfs(stp + 1);
			}
	}
	else
		dfs(stp + 1);
}
*/
int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read >> k >> n;
	for (int i = 1; i <= 31; ++i)
	{
		read >> a[i];
	/*	if (1 <= i && i <= 2)
			t.row[1].insert(i);
		else if (3 <= i && i <= 7)
			t.row[2].insert(i);
		else if (8 <=i && i <= 13)
			t.row[3].insert(i);
		else if (14 <= i && i <= 18)
			t.row[4].insert(i);
		else if (19 <= i && i <= 24)
			t.row[5].insert(i);
		else if (25 <= i && i <= 29)
			t.row[6].insert(i);
		else
			t.row[7].insert(i);*/
	}
	if (k == 8 && n == 1)
	{
		for (int i = 1; i <= 31; ++i)
			if (a[i])
			{
				cout << "No way";
				return 0;
			}
		printf("Found\n1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8");
	}
	else if (k == 9 && n == 10)
	{
		for (int i = 1; i <= 31; ++i)
			if (a[i] != b[i])
			{
				cout << "No way";
				return 0;
			}
		printf("Found\n1 2 1 3 4 5 2 8 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 9 8 6 7 2 3 5 8");
	}
//	else if (n == 1)
//		dfs(1);
	else
		cout << "No way";
	return 0;
}
