#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
struct Tree{
	int l, r;
	int dat;
}t[maxn*4];

long long a[maxn], n, x, b, c, d, las, y;
long long s[maxn], sum[maxn], ans = 0;
bool flag = false;

template<typename T> void read(T &x){
	T f = 1; x = 0; char c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x<<3)+(x<<1)+c-'0';
	x *= f;
}
void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = a[l]; 
		return;
	}
	int mid = (l + r) / 2;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	t[p].dat = min(t[p*2].dat, t[p*2+1].dat);
}
int ask(int p, int l, int r){
	if(l <= t[p].l && r >= t[p].r) return t[p].dat;
	int mid = (t[p].l + t[p].r) / 2;
	int val = 1<<30;
	if(l <= mid) val = min(val, ask(p*2, l, r));
	if(r > mid) val = min(val, ask(p*2+1, l, r));
	return val;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	read(n); read(x); read(b); read(c); read(d);
	for(int i = 1; i <= n; ++i){
		read(a[i]);
		s[i] = x*a[i]*a[i]*a[i] + b*a[i]*a[i] + c*a[i] + d;
		sum[i] = sum[i-1] + s[i];
	}
	build(1, 1, n);
	for(int i = 2; i <= n; ++i){
		if(s[i] < 0 && s[i-1] < 0){
			if(a[i] < a[i-1])
				s[i-1] = 0;
			else{
				s[i] = s[i-1];
				s[i-1] = 0;
				a[i] = a[i-1];
			}
		} else {
			if(s[i] > 0 && s[i-1] < 0){
				if(flag == false){
					flag = true;
					las = i-1;
				} else {
					y = ask(1, las, i-1);
					if(sum[i-1] - sum[las-1] < s[y]){
						for(int j = las; j <= i-2; ++j)
							s[j] = 0;
						s[i-1] = s[y];
						flag = false; 
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		ans += s[i];
	printf("%lld\n", ans);
	return 0;
}



