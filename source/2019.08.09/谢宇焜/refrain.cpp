#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
#define ll long long
using namespace std;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

const int Mod = 1e9+7;
int num, n, m1, m2;
int rela[1010][1010];
bool vis[100010];
int t[100010];

in bool check()
{
	fir(i, 1, n)
	{
		fir(j, i+1, n)
			if(rela[i][j] != rela[t[i]][t[j]]) return 1;
	}
	return 0;
}

ll ans = 0;
void work(int k)
{
	if(k == n)
	{
		if(check() == 1) ans = (ans + 1) % Mod;
		return;	
	} 
	fir(i, 1, n)
	{
		if(vis[i] == 1) continue;
		vis[i] = 1;
		t[k+1] = i;
		work(k + 1);
		vis[i] = 0;
	}
}

int main()
{
    freopen("refrain.in","r",stdin);
    freopen("refrain.out","w",stdout);
	read(num);
	read(n); read(m1); read(m2);
	if(n == 1 || n == 2) 
	{
		cout<<0<<endl;
		return 0;
	}
	int x, y;
	fir(i, 1, m1)
	{
		read(x); read(y);
		rela[x][y] = rela[y][x] = 1;
	}
	fir(i, 1, m2)
	{
		read(x); read(y);
		rela[x][y] = rela[y][x] = 2;
	}
	
	work(0);
	cout<<ans<<endl;
	return 0;
}


