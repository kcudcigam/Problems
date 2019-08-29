#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[2][N];
int ans,record,Limit;
vector<int>v;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int check(int pos,int which){
	int rlast=record-1;
	int last=record-1,len=1;
	while(len){
		if(a[which][pos]>=a[which^1][last+len]&&last+len<=Limit)last+=len,len*=2;//按2的次幂划分 
		else len/=2;
	}
	return last-rlast;
}
int chose(int l,int r,int which){
	int ori_l=l,mid,num;
	while(l+1<r){
		mid=(l+r)/2;
		num=check(mid,which);
		if(num+mid-ori_l==ans)return mid;
		if(num+mid-ori_l<ans)l=mid+1;
		else r=mid;
	}
	num=check(l,which);
	if(num+l-ori_l==ans)return l;
	else return 0;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n=read(),m=read();
	for(int i=0;i<=1;i++)
		for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=m;i++){
		int op=read();
		if(op==1){
			int x=read(),y=read(),z=read();
			a[x][y]=z;
		}
		if(op==2){
			int l1=read(),r1=read(),l2=read(),r2=read();
			ans=((r1-l1+1)+(r2-l2+1)-1)/2;
			record=l2,Limit=r2;
			int c0=chose(l1,r1+1,0);
			record=l1,Limit=r1;
			int c1=chose(l2,r2+1,1);
			if(a[0][c0])printf("%d\n",a[0][c0]);
			else {
				if(a[1][c1]==0){
					int p1,p2;
					for(p1=l1,p2=l2;p1<=r1&&p2<=r2;){
						if(a[0][p1]<=a[1][p2]){
							v.push_back(a[0][p1]) ;
							p1++;
						}
						else {
							v.push_back(a[1][p2]);
							p2++; 
						}
					}
					while(p1<=r1){
						v.push_back(a[0][p1++]); 
					}
					while(p2<=r2){
						v.push_back(a[1][p2++]);
					}
					printf("%d\n",v[ans+1]);
					v.clear();
				}
				else printf("%d\n",a[1][c1]);
			}
		}
	}
	return 0;
}
/*
5 1
1 2 3 4 5
1 2 3 4 5
2 1 5 1 4

*/

