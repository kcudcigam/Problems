#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,a[500010],b[500010],q,k,k1,k2;
long long m;
int boss(int v){
	if (a[v]==v) return v;
	boss(a[v]);
}
void merge(int f1,int f2){
	int t1=boss(f1);
	int t2=boss(f2);
	a[t1]=t2;
}
int main(){
  freopen("merge.in","r",stdin);
  freopen("merge.out","w",stdout);
  read(n);
  read(q);
  for (int i=1;i<=n;i++){
  	a[i]=i;
  }
  for (int i=1;i<=q;i++){
  	read(k);read(k1);read(k2);
  	if (k==1) merge(k1,k2);
  	if (k==2) {
  		int kzy=boss(k1);
  		for (int i=1;i<=n;i++){
  			if (boss(i)==kzy) b[i]+=k2; 
		  }
	  }
  }
  for (int i=1;i<=n;i++){
  	cout<<b[i]<<" ";
  }
  cout<<endl;
return 0;
}
