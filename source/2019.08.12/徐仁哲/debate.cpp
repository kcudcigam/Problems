#include<bits/stdc++.h>
using namespace std;
int a11[5010];
int len11,len10,len01,len00;
int r1,r2,total,ans;
priority_queue<int> q10;
priority_queue<int> q01;
priority_queue<int> q00;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
	int n;
	n=read();
	if(n<=5000){
		for(int i=1;i<=n;i++){
			char ch1,ch2;
			ch1=getchar();
			ch2=getchar();
			int hyd;
			hyd=read();
			if(ch1=='1'&&ch2=='1') a11[++len11]=hyd;
			if(ch1=='1'&&ch2=='0') q10.push(hyd);
			if(ch1=='0'&&ch2=='1') q01.push(hyd);
			if(ch1=='0'&&ch2=='0') q00.push(hyd);
		}
		for(int i=1;i<=len11;i++){
			total++;
			r1++;
			r2++;
			ans+=a11[i];
		}
		while(!q10.empty()&&!q01.empty()&&!q00.empty()&&2*r1>=total&&2*r2>=total){
			if(q10.top()+q01.top()>=q00.top()){
				int lst=total+2;
				int lsr1=r1+1;
				int lsr2=r2+1;
				if(2*lsr1>=lst&&2*lsr2>=lst){
					total=lst;
					r1=lsr1;
					r2=lsr2;
					ans+=q10.top()+q01.top();
					q10.pop();
					q01.pop();
				}
			}else{
				int lst=total+1;
				if(2*r1>=lst&&2*r2>=lst){
					total=lst;
					ans+=q00.top();
					q00.pop();
				}
			}
		}
		while(q10.empty()&&!q01.empty()&&!q00.empty()&&2*r1>total&&2*r2>total){
			if(q01.top()>=q00.top()){
				int lst=total+1;
				int lsr2=r2+1;
				if(2*r1>=lst&&2*lsr2>=lst){
					total=lst;
					r2=lsr2;
					ans+=q01.top();
					q01.pop();
				}
			}else{
				int lst=total+1;
				if(2*r1>=lst&&2*r2>=lst){
					total=lst;
					ans+=q00.top();
					q00.pop();
				}
			}
		}
		while(!q10.empty()&&q01.empty()&&!q00.empty()&&2*r1>total&&2*r2>total){
			if(q10.top()>=q00.top()){
				int lst=total+1;
				int lsr1=r1+1;
				if(2*lsr1>=lst&&2*r2>=lst){
					total=lst;
					r1=lsr1;
					ans+=q10.top();
					q10.pop();
				}
			}else{
				int lst=total+1;
				if(2*r1>=lst&&2*r2>=lst){
					total=lst;
					ans+=q00.top();
					q00.pop();
				}
			}
		}
		while(!q10.empty()&&!q01.empty()&&q00.empty()&&2*r1>total&&2*r2>total){
			int lst=total+2;
			int lsr1=r1+1;
			int lsr2=r2+1;
			if(2*lsr1>=lst&&2*lsr2>=lst){
				total=lst;
				r1=lsr1;
				r2=lsr2;
				ans+=q10.top()+q01.top();
				q10.pop();
				q01.pop();
			}
		}
		while(q10.empty()&&q01.empty()&&!q00.empty()&&2*r1>total&&2*r2>total){
			int lst=total+1;
			int lsr1=r1;
			int lsr2=r2;
			if(2*lsr1>=lst&&2*lsr2>=lst){
				total=lst;
				r1=lsr1;
				r2=lsr2;
				ans+=q00.top();
				q00.pop();
			}
		}
		while(!q10.empty()&&q01.empty()&&q00.empty()&&2*r1>total&&2*r2>total){
			int lst=total+1;
			int lsr1=r1+1;
			int lsr2=r2;
			if(2*lsr1>=lst&&2*lsr2>=lst){
				total=lst;
				r1=lsr1;
				r2=lsr2;
				ans+=q10.top();
				q10.pop();
			}
		}
		while(q10.empty()&&!q01.empty()&&q00.empty()&&2*r1>total&&2*r2>total){
			int lst=total+1;
			int lsr1=r1;
			int lsr2=r2+1;
			if(2*lsr1>=lst&&2*lsr2>=lst){
				total=lst;
				r1=lsr1;
				r2=lsr2;
				ans+=q01.top();
				q01.pop();
			}
		}
		cout<<ans<<endl;
	}else{
		for(int i=1;i<=n;i++){
			char ch1,ch2;
			ch1=getchar();
			ch2=getchar();
			int hyd;
			hyd=read();
			if(ch1=='1'&&ch2=='1') a11[++len11]=hyd;
			if(ch1=='0'&&ch2=='0') q00.push(hyd);
		}
		for(int i=1;i<=len11;i++){
			total++;
			ans+=a11[i];
		}
		while(total!=0){
			ans+=q00.top();
			q00.pop();
			total--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
