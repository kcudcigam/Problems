#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[501000];
int b[501000];
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	vector<int>d[110000];
	int n,q;
	read(n);
	read(q);	
	for (int i=1;i<=n;i++){
		b[i]=i;
		a[i]=0;
	}

	for (int i=1;i<=q;i++){
		int t,x,y;
		read(t);
		read(x);
		read(y);
		if (t==1){
			b[x]=b[y];
			d[b[y]].push_back(x);
		}
		else{
			int ll=b[x];
			for (int j=0;j<d[ll].size();j++){
				a[d[ll][j]]+=y;
			}
			a[b[x]]+=y;
		}
	}
	for (int i=1;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n]<<endl;
	return 0;
}


