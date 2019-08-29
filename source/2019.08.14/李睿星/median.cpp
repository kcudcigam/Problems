#include<cstdio>
using namespace std;
void read(int &x){
	char c=getchar();x=0;int f=1; 
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)-'0'+c;
	x*=f;
}
int n,m,a[500005],b[500005],c,x,y,z,l1,r1,l2,r2,cnt;bool f;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) read(b[i]);
	for(int i=1;i<=m;++i){
		read(c);
		if(c==1){
			read(x);read(y);read(z);
			x?b[y]=z:a[y]=z;
		}
		else{
			read(l1);read(r1);read(l2);read(r2);
			cnt=(r1-l1+r2-l2+3)>>1;
			for(int j=1;j<cnt;++j){
				if(l1>r1){
					printf("%d\n",b[l2+cnt-j]);
					f=1;break;
				}
				if(l2>r2){
					printf("%d\n",a[l1+cnt-j]);
					f=1;break;
				}
				a[l1]<b[l2]?++l1:++l2;
			}
			if(!f) printf("%d\n",a[l1]<b[l2]?a[l1]:b[l2]);
			f=0;
		}
	}
	return 0;
}
