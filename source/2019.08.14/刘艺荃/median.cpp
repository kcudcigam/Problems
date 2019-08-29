#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar();while(isdigit(ch));
	x=f*r;
}
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
int a[500010],b[500010];
int gb(int l1,int r1,int l2,int r2){
	int p1=l1,p2=l2,ans=0,len=0;
	int len1=r1-l1+1,len2=r2-l2+1;
	int mid=(len1+len2)/2+1;
	while(len<mid){
		if(a[p1]<b[p2]){ans=a[p1];p1++;}
		else {ans=b[p2];p2++;}
		len++;
	}
	return ans;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=m;i++){
		int opt;read(opt);
		if(opt==1){
			int x,y,z;
			read(x);read(y);read(z);
			if(x==0)a[y]=z;
			else if(x==1)b[y]=z;
		}else if(opt==2){
			int l1,r1,l2,r2;
			read(l1);read(r1);read(l2);read(r2);
			int len1=r1-l1+1,len2=r2-l2+1;
			int res=gb(l1,r1,l2,r2);
			write(res);putchar('\n');
		}
	}
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
