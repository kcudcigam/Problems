#include<bits/stdc++.h>

using namespace std;

#define N 500000

int a[N+5],b[N+5];
int n,m;

int solve(int la,int ra,int lb,int rb,int rk){
//cout<<"solve: la="<<la<<" ra="<<ra<<" lb="<<lb<<" rb="<<rb<<" rk="<<rk<<endl;	
	if(la > ra)return b[lb + rk - 1];
	if(lb > rb)return a[la + rk - 1];
	if(rk == 1)return min(a[la],b[lb]);
	int rka = rk >> 1,rkb = rk - rka;
	int pa = la + rka - 1;
	int pb = lb + rkb - 1;
//cout<<pa<<" "<<pb<<endl;
	if(pa > ra){
		if(a[ra] <= b[pb])return b[lb + rk - ra + la - 2];
		else return solve(la,ra,pb + 1,rb,rk - rkb);
	}
	if(pb > rb){
		if(b[rb] <= a[pa])return a[la + rk - rb + lb - 2];
		else return solve(pa + 1,ra,lb,rb,rk - rka);
	}
//cout<<a[pa]<<" "<<b[pb]<<endl;	
	if(a[pa] == b[pb])return a[pa];
	if(a[pa] < b[pb])return solve(pa + 1,ra,lb,rb,rk - rka);
	if(a[pa] > b[pb])return solve(la,ra,pb + 1,rb,rk - rkb);
}

inline int read(){
	int s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

inline void write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x / 10);
	putchar('0' + x % 10);
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n = read();m = read();
	int i;
	for(i = 1;i <= n;i++)a[i] = read();
	for(i = 1;i <= n;i++)b[i] = read();
	while(m--){
		int opt = read();
		if(opt == 1){
			int x = read(),y = read(),z = read();
			if(x == 0)a[y] = z;
			else b[y] = z;
		}
		if(opt == 2){
			int la = read(),ra = read(),lb = read(),rb = read();
//cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<endl;
			int len = ra - la + 1 + rb - lb + 1;
			write(solve(la,ra,lb,rb,(len + 1) >> 1));
			putchar('\n');
		}
	}
	return 0;
}

