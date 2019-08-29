#include<bits/stdc++.h>
using namespace std;
vector<int> a[300001];
set<int> b[300001];
int add[300001];
int sum[300001];

template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	T l=0;
	unsigned long long y=0;
	if(!x){putchar(48);return;}
	if(x<0){x=-x;putchar('-');}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
bool pc(int x,int y){
	int ans=b[x].size();
	b[x].insert(y);
	int ans1=b[x].size();
	if(ans==ans1)return true;
	else return false;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q,x,y,typ;
	read(n);
	read(m);
	read(q);

	for(int i=1;i<=m;i++) {
		read(x);
		read(y);
		if(!pc(x,y)){
			a[x].push_back(y);
			a[y].push_back(x);
	}

	}
	if(n<=3000&&m<=3000&&q<=3000){
	int ans=0;
	for(int i=1;i<=q;i++){
		read(typ);
		if(typ==1){
			read(x);read(y);
			add[x]+=y;
		}
		if(typ==0){
			ans=0;
			read(x);
			
			for(int i=0;i<a[x].size();i++){
				ans+=add[a[x][i]];
			}
			writeln(ans+add[x]);
			}
		}
	}


	else{
		int ans=0;
		for(int i=1;i<=q;i++){
			read(typ);
				if(typ==1){
					read(x);read(y);
					if(a[x].size()<=10){
						for(int i=0;i<a[x].size();i++){
							sum[a[x][i]]+=y;	
						}sum[x]+=y;
					}
					
					else add[x]+=y;
		}
		if(typ==0){
			
			read(x);
			ans=sum[x];
			if(a[x].size()>10)writeln(sum[x]);
			else{
				for(int i=0;i<a[x].size();i++){
					ans+=add[a[x][i]];
				}
				writeln(ans);
			} 
		}
	}
	}
	
	return 0;
}



