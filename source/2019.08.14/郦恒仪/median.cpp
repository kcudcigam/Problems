#include<bits/stdc++.h>
using namespace std;

int n,m,t,l,r,x,y,k,mid,ans,j,tt;
int a[500010],b[500010],h[500010][3];

void read(int &x){
	x=0;char h=' ';
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<1)+(x<<3)+h-48;
}
void work(int l,int r,int x,int y,int t,int s){
	int tl=l;
	while (l+1<r){
		mid=(l+r)/2;
		if (mid-tl+1+max(min(h[mid][t],y)-x+1,0)>s) r=mid-1;
								               else l=mid;
	}
	if (l-tl+1+max(min(h[l][t],y)-x+1,0)==s) ans=l,tt=t;l++;
	if (l-tl+1+max(min(h[l][t],y)-x+1,0)==s) ans=l,tt=t;
}


int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	j=0;b[n+1]=INT_MAX;
	for (int i=1;i<=n;i++){
		while (a[i]>=b[j+1]) j++;
		h[i][0]=j;
	}
	j=0;a[n+1]=INT_MAX;
	for (int i=1;i<=n;i++){
		while (b[i]>a[j+1]) j++;
		h[i][1]=j;
	}
	for (int i=1;i<=n;i++){
		read(t);
		if (t==1) {
			read(k);read(x);read(y);
			if (k==0) {
				k=h[x][0];
				if (y>a[x]) {
					while (y>=b[h[x][0]+1]) h[x][0]++;
					for (int j=k+1;j<=h[x][0];j++) h[j][1]--;
				}
					   else {
					while (y<b[h[x][0]]) h[x][0]--;
					for (int j=h[x][0]+1;j<=k;j++) h[j][1]++;
				}
				a[x]=y;
			}
				 else {
				k=h[x][1];
				if (y>b[x]) {
					while (y>a[h[x][1]+1]) h[x][1]++;
					for (int j=k+1;j<=h[x][1];j++) h[j][0]--;
//					if (i==55) cout<<k<<' '<<h[x][1]<<endl;
				}
					   else {
					while (y<=a[h[x][1]]) h[x][1]--;
					for (int j=h[x][1]+1;j<=k;j++) h[j][0]++;
				}
				b[x]=y;
			}
			continue;
		}
		read(l);read(r);read(x);read(y);
		
		work(l,r,x,y,0,(y-x+r-l+3)/2);
		work(x,y,l,r,1,(y-x+r-l+3)/2);
		if (tt==0) cout<<a[ans]<<endl;
			  else cout<<b[ans]<<endl;
//		if (l==7 && r==67 && x==32 && y==89) {
//			cout<<ans<<' '<<tt<<' '<<h[ans][0]<<endl;
//			for (int i=l;i<r;i++) cout<<a[i]<<' ';cout<<a[r]<<endl;
//			for (int i=x;i<y;i++) cout<<b[i]<<' ';cout<<b[y]<<endl;
//		}
	}
	return 0;
}

