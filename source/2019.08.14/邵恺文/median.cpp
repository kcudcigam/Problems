#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(T &x){
	char ch=getchar();
	int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')minus=1,ch=getchar();
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)x=-x;
	return x;
}
template <typename T> void printe(const T x)
{
    if(x>=10)printe(x/10);
    putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
    if(x<0)putchar('-'),printe(-x);
    else printe(x);
}
const int maxn=500005;
int a[maxn],b[maxn];
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    int n,m,_t;
    read(n);
    read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=n;i++)read(b[i]);
    for(int _i=1;_i<=m;_i++){
        read(_t);
        if(_t==1){
        	int x,y,z;
        	read(x);read(y);read(z);
        	if(x==0)a[y]=z;
        	else b[y]=z;
		}
		else{
			int l1,l2,r1,r2;
			read(l1);read(r1);read(l2);read(r2);
			int t1=r1-l1+1,t2=r2-l2+1;
			if(a[r1]<=b[l2]){
				int t =((t1+t2) >> 1)  + 1;
			    if(t1>t2)print(a[l1+t-1]);
			    else print(b[l2+t-t1-1]);
			    putchar('\n');
				continue;	
			}
			if(b[r2]<=a[l1]){
				int t =((t1+t2) >> 1)  + 1;
			    if(t1>t2)print(a[t-t2+l1-1]);
			    else print(b[l2+t-1]);
			    putchar('\n');
			    continue;	
			}
			int i=l1,j=l2,t=0,c = ((t1+t2) >> 1) + 1,pre;
			while(t<=c){
				if(t==c){
					print(pre);
					putchar('\n');
					break;
				}
				if(i>r1){
					print(b[j+c-t-1]);
					putchar('\n');
					break;
				}
				if(j>r2){
					print(a[i+c-t-1]);
					putchar('\n');
					break;
				}
				if(a[i]<=b[j])t++,pre=a[i],i++;
				else t++,pre=b[j],j++;
			}
		}
	}
	return 0;
}


