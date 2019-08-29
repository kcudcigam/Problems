#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
ll n;
int q;
int cnt,sum[10],p[19];
int len;
bool candouble;
bool subtask1(ll x){
	cnt=0;
	memset(sum,0,sizeof(sum));
	len=0;
	while (x){
		p[++len]=x%10;
		if (!sum[x%10]) cnt++;
		sum[x%10]++;
		x/=10;
	}
	for (int i=1;i<=len/2;i++) swap(p[i],p[len-i+1]);
	return cnt<=2;
}
void dfs(int num1,int num2,int dep,bool flag,bool tag,int last,int cnt){
	if (cnt>2) return;
	if (dep>len){
		if (last<0) return;
		if (!sum[last]) cnt++;
		if (cnt>2) return;
		candouble=true;
		return;
	}
	if (flag){
		int w=cnt;
		if (dep>1){
			if (!sum[last]) w++;
			sum[last]++;
		}
		dfs(num1,num2,dep+1,flag,(last==0)&&tag,p[dep],w);
		if (dep>1) sum[last]--;
	}
	int a=last,b=num1;
	if (b>p[dep]){
		b-=10;
		a--;
	}
	if (a==0){
		if (tag) dfs(num1,num2,dep+1,false,true,p[dep]-b,cnt);
		else{
			int w=cnt;
			if (!sum[a]) w++;
			sum[a]++;
			dfs(num1,num2,dep+1,false,false,p[dep]-b,w);
			sum[a]--;
		}
	}
	else
		if (a>0){
			int w=cnt;
			if (!sum[a]) w++;
			sum[a]++;
			dfs(num1,num2,dep+1,false,false,p[dep]-b,w);
			sum[a]--;
		}
	a=last,b=num2;
	if (b>p[dep]){
		b-=10;
		a--;
	}
	if (a==0){
		if (tag) dfs(num1,num2,dep+1,false,true,p[dep]-b,cnt);
		else{
			int w=cnt;
			if (!sum[a]) w++;
			sum[a]++;
			dfs(num1,num2,dep+1,false,false,p[dep]-b,w);
			sum[a]--;
		}
	}
	else
		if (a>0){
			int w=cnt;
			if (!sum[a]) w++;
			sum[a]++;
			dfs(num1,num2,dep+1,false,false,p[dep]-b,w);
			sum[a]--;
		}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(q);
	while (q--){
		read(n);
		if (subtask1(n)) puts("1");
		else{
			candouble=false;
			for (int i=0;i<=8;i++){
				if (candouble) break;
				for (int j=i+1;j<=9;j++){
					memset(sum,0,sizeof(sum));
					dfs(i,j,1,true,true,0,0);
					if (candouble) break;
				}
			}
			if (candouble) puts("2");
			else puts("3");
		}
	}
	return 0;
}

