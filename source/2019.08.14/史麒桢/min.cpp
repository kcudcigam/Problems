#include<bits/stdc++.h>
using namespace std;
long long n,A,B,C,D;
int a[222222];
long long b[222222];
long long c[222222];
long long ans;
long long calc(int aa){
	long long x=(long long)aa;
	return (((A*x+B)*x+C)*x+D);
}
long long tg_calc(int aa){
	long long x=(long long)aa;
	return ((3*A*x+2*B)*x+C);
}
template <typename T> void read(T &x){
	T f=1; x=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
}
template <typename T> void writing(T x){
	if (x>9){
		writing(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void write(T x){
	if (x<0){
		x=-x;
		putchar('-');
	}
	writing(x);
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);
	read(A);
	read(B);
	read(C);
	read(D);
	ans=0;
	for (int i=1;i<=n;i++){
		read(a[i]);
		b[i]=tg_calc(a[i]);
		c[i]=calc(a[i]);
	}
	if (A==0){
		if (B==0){
			if (C==0){
				if (D>0){
					ans=D*n;
				}
				else {
					ans=D;
				}
			}
			else {
				long long kk=0;
				for (int i=1;i<=n;i++){
					if (c[i]>0){
						if (kk!=0){
							ans+=kk;
							kk=0;
						}
						ans+=c[i];
					}
					else {
						if (kk==0){
							kk=c[i];
						}
						else {
							kk=max(kk,c[i]);
						}
					}
				}
				if (kk!=0){
					ans+=kk;
				}
			}
		}
		else {
			for (int i=1;i<=n;){
				if (c[i]>=0){
					ans+=c[i];
					++i;
				}
				else {
					long long kk=c[i++];
					int ki=a[i];
					while (c[i]<0){
						if (c[i]>kk&&ki>a[i]){
							ki=a[i];
							kk=c[i];
						}
						++i;
					}
					ans+=kk;
				}
			}
		}
	}
	else {
		for (int i=1;i<=n;){
			if (c[i]>=0){
				ans+=c[i];
				++i;
			}
			else {
				long long kk=c[i++];
				int ki=a[i];
				while (c[i]<0){
					if (c[i]>kk&&ki>a[i]){
						ki=a[i];
						kk=c[i];
					}
					++i;
				}
				ans+=kk;
			}
		}
	}
	writeln(ans);
	return 0;
}

