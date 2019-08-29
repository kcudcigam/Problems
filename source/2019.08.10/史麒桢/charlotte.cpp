#include<bits/stdc++.h>
using namespace std;
pair < int , pair <int , int> > t[111111]; 
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
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	read(T);
	while (T--){
		int n;
		read(n);
		memset(t,0,sizeof(t));
		for (int i=1;i<=n;i++){
			read(t[i].first);
			read(t[i].second.first);
			read(t[i].second.second);
		}
		sort(t+1,t+n+1);
		bool flag=true;
		for (int i=1;i<=n;i++){
			int deltat=t[i].first-t[i-1].first;
			int deltax=abs(t[i].second.first-t[i-1].second.first);
			int deltay=abs(t[i].second.second-t[i-1].second.second);
			if (deltat<deltax+deltay){
				flag=false;
				puts("No");
				break;
			}
			int oddt=(deltat&1);
			int oddxy=((deltax+deltay)&1);
			if (oddt+oddxy==1){
				flag=false;
				puts("No");
				break;
			}
		}
		if (flag){
			puts("Yes");
		}
	}
	return 0;
}


