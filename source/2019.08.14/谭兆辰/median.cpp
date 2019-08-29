#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
#define N 500500
#define R register
int a[N],b[N]; 
inline bool check1(int l,int r,int x,int k,int s){
	int p=x-s+1;
	if(p>=k) return true;
	if(l+k-p-1>r) return false;
	if(b[l+k-p-1]<=a[x]) return true;
	else return false;
}
inline bool check2(int l,int r,int x,int k,int s){
	int p=x-s+1;
	if(p>=k) return true;
	if(l+k-p-1>r) return false;
	if(a[l+k-p-1]<=b[x]) return true;
	else return false;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n),read(m);
	for(R int i=1;i<=n;i++) read(a[i]);
	for(R int i=1;i<=n;i++) read(b[i]);
	a[0]=b[0]=-1,a[n+1]=b[n+1]=2e9;
	while(m--){
		R int opt;
		read(opt);
		if(opt==1){
			R int x,y,z;
			read(x),read(y),read(z);
			if(!x){
				a[y]=z;
			}
			else{
				b[y]=z;
			}
		}
		else{
			R int l1,r1,l2,r2;
			read(l1),read(r1),read(l2),read(r2);
			R int l=l1,r=r1,now=(r1-l1+r2-l2+2)/2+1;
			while(l<r){
				int mid=l+r>>1;
				if(check1(l2,r2,mid,now,l1)){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
//			cout<<check1(l2,r2,3,now)<<" ";
			int p=l-l1+1;
			if((b[l2+now-p]>=a[l]||l2+now-p>r2)&&(b[l2+now-p-1]<=a[l]||l2+now-p-1<l2)){
				printf("%d\n",a[l]);
			}
			else{
				l=l2,r=r2;
				while(l<r){
					R int mid=l+r>>1;
					if(check2(l1,r1,mid,now,l2)){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				p=l-l2+1;
				if((a[l1+now-p]>=b[l]||l1+now-p>r1)&&(a[l1+now-p-1]<=b[l]||l1+now-p-1<l1)){
					printf("%d\n",b[l]);
				}
			}
		}
	}
	return 0;
}
