#include<bits/stdc++.h>
using namespace std;
int n ,m ,Q ;
int num [333333];
vector < pair < int , int > > e;
int bi_searchx (int x,int l,int r){
	int mid=(l+r)>>1;
	if ((e[mid+1].first>=x)&&(e[mid].first<x)){
		return mid;
	}
	else if (e[mid].first>=x){
		return bi_searchx(x,l,mid);
	}
	else {
		return bi_searchx(x,mid+1,r);
	}
}
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);
	read(m);
	read(Q);
	memset(num,0,sizeof(num));
	while (!e.empty()){
		e.pop_back();
	}
	e.push_back(make_pair(0,0));
	int cnt=0;
	while (m--){
		int u,v;
		read(u);
		read(v);
		if (u!=v){
			cnt+=2;
			e.push_back(make_pair(u,v));
			e.push_back(make_pair(v,u));
		}
	}
	sort(e.begin(),e.end());
	int nowi = 0;
	for (int i=1;i<=cnt;i++){
		if (e[nowi]==e[nowi+1]){
			e.erase(e.begin()+nowi+1);
		}
		else {
			++nowi;
		}
	}
	m = nowi;
	e.push_back(make_pair(n+1,n+1));
	while (Q--){
		int typeq;
		read(typeq);
		if (typeq){
			int x,y;
			read(x);
			read(y);
			num[x]+=y;
			int ll = bi_searchx(x,0,m+1)+1;
			int rr = bi_searchx(x+1,0,m+1);
			for (int i=ll;i<=rr;i++){
				num[e[i].second]+=y;
			}
		}
		else {
			int x;
			read(x);
			writeln(num[x]);
		}
	}
	return 0;
}


