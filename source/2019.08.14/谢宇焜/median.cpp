#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(register int a = b; a <= c; a ++)
using namespace std;
inline int read(){
	int xx = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for(; isdigit(c); c = getchar()) xx = xx * 10 + c - '0';
	return xx * f;
}

const int N = 500000;
int n, m, a[N+5], b[N+5];

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n = read(); m = read();
	int ans = 0;
	fir(i, 1, n) a[i] = read();
	fir(i, 1, n) b[i] = read();
	int opt, x, y, z, l1, l2, r1, r2;
	
	fir(i, 1, m){
		opt = read();
		ans = 0;
		if(opt == 1){
			x = read(); y = read(); z = read();
			if(x == 0) a[y] = z;
			else b[y] = z;
		}
		else{
			l1 = read(); r1 = read(); l2 = read(); r2 = read();
			int cnt1 = r1-l1+1;
			if(cnt1 % 2 == 1){
				int zws = a[(l1+r1) >> 1];
				int pos2 = upper_bound(b+l2, b+r2+1, zws) - b;
				pos2 --;
				int len1 = pos2 - l2 + 1, len2 = r2 - pos2 + 1;
				if(pos2 < l2) pos2 ++, len2 --;
				if(b[pos2] < zws) len2 --;
				if(len1 == len2){printf("%d\n", zws); continue;}
				if(len1 > len2){
					int ws = (len1-len2) >> 1;
					int pos1 = (l1+r1) >> 1;
					pos1 --;
					int cnt = 0;
					if(b[pos2] == zws) cnt = -1;
					while(cnt < ws){
						if(pos1 < l1){ans = b[pos2-ws+cnt+1]; break;}
						if(pos2 < l2){ans = a[pos1-ws+cnt+1]; break;}
						if(b[pos2] >= a[pos1]) {
							ans = b[pos2];
							pos2 --;
						}
						else
						{
							ans = a[pos1];
							pos1 --;
						}
						cnt ++;
					}
				}
				
				if(len2 > len1){
					int ws = (len2-len1) >> 1;
					int pos1 = (l1+r1) >> 1;
					pos1 ++;					
					if(b[pos2] < zws) pos2 ++;
					//if(pos2 < l2) pos2 = l2;
					int cnt = 0;
					if(b[pos2] == zws) cnt = -1; 
					while(cnt < ws){
						if(pos2 > r2){ans = a[pos1+ws-cnt-1]; break;}
						if(pos1 > r1){ans = b[pos2+ws-cnt-1]; break;}						
						if(b[pos2] <= a[pos1]) {
							ans = b[pos2];
							pos2 ++;
						}
						else
						{
							ans = a[pos1];
							pos1 ++;
						}
						cnt ++;				
					}
				}
			}
			
			else{
				int zws = b[(l2+r2) >> 1];
				int pos1 = upper_bound(a+l1, a+r1+1, zws) - a;
				pos1 --;
				int len1 = pos1 - l1 + 1, len2 = r1 - pos1 + 1;
				if(pos1 < l1) pos1 ++, len2 --;
				if(a[pos1] < zws) len2 --;
				if(len1 == len2){printf("%d\n", zws); continue;}
				if(len1 > len2){
					int ws = (len1-len2) >> 1;
					int pos2 = (l2+r2) >> 1;
					pos2 --;
					int cnt = 0;
					if(a[pos1] == zws) cnt = -1;
					while(cnt < ws){
						if(pos1 < l1){ans = b[pos2-ws+cnt+1]; break;}
						if(pos2 < l2){ans = a[pos1-ws+cnt+1]; break;}
						if(b[pos2] >= a[pos1]) {
							ans = b[pos2];
							pos2 --;
						}
						else {
							ans = a[pos1];
							pos1 --;
						}
						cnt ++;
					}
				}
				
				if(len2 > len1){
					int ws = (len2-len1) >> 1;
					int pos2 = (l2+r2) >> 1;
					pos2 ++;
					if(a[pos1] < zws) pos1 ++;
				//	if(pos1 < l1) pos1 ++;
					int cnt = 0;
					if(a[pos1] == zws) cnt = -1;
					while(cnt < ws){
						if(pos2 > r2){ans = a[pos1+ws-cnt-1]; break;}
						if(pos1 > r1){ans = b[pos2+ws-cnt-1]; break;}						
						if(b[pos2] <= a[pos1]) {
							ans = b[pos2];
							pos2 ++;
						}
						else
						{
							ans = a[pos1];
							pos1 ++;
						}
						cnt ++;					
					}
				}				
				}
				printf("%d\n", ans);
			}		
	}
	return 0;
}
