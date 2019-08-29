#include<bits/stdc++.h>
using namespace std;
long long a[700000][3];	
int f=0,r=9;
long long ans;
long long i;
int t;
long long n; 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
bool cz(long long x){
	int f=1,l=r;
	int mid; 
	while(f<l){
		mid=(f+l)/2;
		if(a[mid][0]>x)l=mid;
		if(a[mid][0]<x)f=mid+1;
		if(a[mid][0]==x)return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=9;i++){
		a[i][0]=i;
		a[i][1]=i;
		a[i][2]=-1;
	}
	read(t) ;
	while(a[r][0]<1e13){
		f++;
		ans=a[f][0]*10;
		if(ans==1e13)break;
		if(a[f][2]==-1){
			for(i=0;i<=9;i++){
				if(i!=a[f][1]){
					r++;
					a[r][2]=max(a[f][1],i);
					a[r][1]=min(a[f][1],i);
					a[r][0]=a[f][0]*10+i;
				}
				else{
					r++;
					a[r][1]=a[f][1];
					a[r][2]=-1;
					a[r][0]=a[f][0]*10+i;
				}
			}
		}
		if(a[f][2]!=-1){
			r++;
			a[r][0]=a[f][0]*10+a[f][1];
			a[r][1]=a[f][1];
			a[r][2]=a[f][2];
			r++;
			a[r][0]=a[f][0]*10+a[f][2];
			a[r][1]=a[f][1];
			a[r][2]=a[f][2];
		}
	}

	a[r+1][0]=1e13;	
	r++; 
	int flag=3;
	for(register int i=1;i<=t;i++){
		read(n);
		for(register int j=1;j<=r;j++){
			if(a[j][0]>n)break;
			if(a[j][0]==n){
				flag=1;
				break;
			}
			if(flag==3)
				if(cz(n-a[j][0])){
					flag=2;
				}
		}
		writeln(flag);
		flag=3;
	}
	return 0;
}


