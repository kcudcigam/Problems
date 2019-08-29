#include<bits/stdc++.h>
using namespace std;
/*template <typename T> void read(T &x) {
	x=0; char c=getchar();int f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
priority_queue<int,vecctor<int>,greater<int> >q1;*/
priority_queue<int,vector<int>,less<int> >q2;
priority_queue<int,vector<int>,less<int> >q3;
priority_queue<int,vector<int>,less<int> >q4;
int main(){
ios::sync_with_stdio(false);
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
    int n;cin>>n;int sum=0;int num=0;
    for(int i=1;i<=n;i++){
    	char a,b;cin>>a;cin>>b;
    	int w;cin>>w;
    	if(a=='1'&&b=='1'){
		num++;sum+=w;}
    	if(a=='0'&&b=='0')q2.push(w);
    	if(a=='1'&&b=='0')q3.push(w);
    	if(a=='0'&&b=='1')q4.push(w);
	}
	
	while(!q3.empty()&&!q4.empty()){
		sum+=q3.top();q3.pop();
		sum+=q4.top();q4.pop();
	}
	while(!q3.empty()){
		int w=q3.top();q3.pop();
		q2.push(w);
	}
		while(!q4.empty()){
		int w=q4.top();q4.pop();
		q2.push(w);
	}
	while(num&&!q2.empty()){
		int w=q2.top();q2.pop();
		sum+=w;
		num--;
	}
	cout<<sum;
	return 0;
}


