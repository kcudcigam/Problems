#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,ans;
int a[maxn][5];
int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
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
			num++;
//			cout<<l1<<"  "<<r1<<"  "<<l2<<"  "<<r2<<"   "<<num<<endl;
			x=l1;
			y=l2;
			for(z=1;z<num&&x<=r1&&y<=r2;z++){
//				cout<<a[x][1]<<"   "<<a[y][2]<<endl;
				if(a[x][1]<a[y][2])
					x++;
				else
					y++;
			}
//			cout<<x<<"  "<<y<<"  "<<z<<endl;
			if(z==num){
//				cout<<x<<"  "<<y<<endl;
				printf("%d\n",min(a[x][1],a[y][2]));
				continue;
			}
			for(;z<=num&&x<=r1;z++)
				x++;
			if(z==num+1){
//				cout<<x<<endl;
				printf("%d\n",a[x][1]);
				continue;
			}
			for(;z<=num,y<=r2;z++,y++);
//			cout<<y<<endl;
			printf("%d\n",a[y][2]);
			continue;
		}
		x=ri();
		y=ri();
		z=ri();
		a[y][x+1]=z;
	}
	return 0;
}

