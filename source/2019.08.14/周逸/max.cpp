#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,ans;
int a[maxn][5];
int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int zy(int op,int l,int r,int num){
	int Mid=l+r>>1;
	while(l<r){
		if(a[Mid][op]<=num)
			l=Mid;
		else
			r=Mid;
		Mid=l+r>>1;
	}
	return Mid;
}
void mid(int l1,int r1,int l2,int r2,int num){
	cout<<"a";
	if(ans)
		return;
	int x,y;
	if(r1-l1>r2-l2){
		x=num+l1+l2-r2-1;
		y=zy(2,l2,r2,a[x][1]);
		if(x-l1+1+y-l2+1==num){
			ans=max(a[x][1],a[y][2]);
			return;
		}
		if(x-l1+1+y-l2+1<num)
			mid(x,r1,y,r2,num-(x-l1+1+y-l2+1));
		else
			mid(l1,x,l2,y,num);
	}
	else{
		x=num+l1+l2-r1-1;
		y=zy(1,l1,r2,a[x][2]);
		if(x-l1+1+y-l2+1==num){
			ans=max(a[x][1],a[y][2]);
			return;
		}
		if(x-l1+1+y-l2+1<num)
			mid(y,r1,x,r2,num-(x-l1+1+y-l2+1));
		else
			mid(l1,y,l2,x,num);
	}
}
int main(){
	n=ri();
	m=ri();
	int i,op,num;
	int x,y,z,l1,l2,r1,r2;
	for(i=1;i<=n;i++)
		a[i][1]=ri();
	for(i=1;i<=n;i++)
		a[i][2]=ri();
	for(i=1;i<=m;i++){
		op=ri();
		if(op==2){
			l1=ri();
			r1=ri();
			l2=ri();
			r2=ri();
			num=(r1-l1+1)+(r2-l2+1)>>1;
			if(r1-l1+1>=num){
				x=l1+num-1;
				y=zy(2,l2,r2,a[x][1]);
				mid(l1,x,l2,y,num);
			}
			else{
				x=l2+num-1;
				y=zy(1,l1,r1,a[x][2]);
				mid(l1,y,l2,x,num);
			}
			printf("%d",ans);
			ans=0;
			continue;
		}
		x=ri();
		y=ri();
		z=ri();
		a[y][x+1]=z;
	}
	return 0;
}

