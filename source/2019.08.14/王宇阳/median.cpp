#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q1;
priority_queue<int,vector<int>,greater<int> >q2;
inline int ri(){
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x =(x<<3)+(x<<1)+(c^48); return x;
}
int n,m;
long long a[500005],b[500005];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();m=ri();
	for(int i=1;i<=n;i++){
		a[i]=ri();
	}
	for(int i=1;i<=n;i++){
		b[i]=ri();
	}
	while(m--){
		int cz=ri();
		if(cz==1){
			int x=ri(),y=ri(),z=ri();
			if(x==0)a[y]=z;
			else a[y]=z;
		}else{
			int l1=ri(),r1=ri(),l2=ri(),r2=ri();
			int t1=0,t2=1;
			q2.push(a[l1]);
			for(int i=l1+1;i<=r1;i++){
				if(a[i]>=a[l1]){
					t2++;
					q2.push(a[i]);
				}else{
					t1++;
					q1.push(a[i]);
				}
				if(t2>t1+1){
					t2--;
					t1++;
					q1.push(q2.top());
					q2.pop();
				}else{
					if(t2<t1+1){
						t2++;
						t1--;
						q2.push(q1.top());
						q1.pop();	
					}
				}
			}
			for(int i=l2;i<=r2;i++){
				if(b[i]>=b[l1]){
					t2++;
					q2.push(b[i]);
				}else{
					t1++;
					q1.push(b[i]);
				}
				if(t2>t1+1){
					t2--;
					t1++;
					q1.push(q2.top());
					q2.pop();
				}else{
					if(t2<t1+1){
						t2++;
						t1--;
						q2.push(q1.top());
						q1.pop();	
					}
				}
			}
			cout<<q2.top()<<endl;
			while(!q1.empty()){
				//cout<<q1.top()<<' ';
				q1.pop();
			}
			//cout<<endl;
			while(!q2.empty()){
				//cout<<q2.top()<<' ';
				q2.pop();
			}
			//cout<<endl;
		}
	}
	return 0;
}


