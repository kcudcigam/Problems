#include<bits/stdc++.h>
using namespace std;
struct node{
	bool f1,f2;
	int x;
}a[400010],b[400010];
bool cmp1(node a1,node a2){
	if(a1.f1!=a2.f1)return a1.f1>a2.f1;
	return a1.x>a2.x;
}
bool cmp2(node a1,node a2){
	if(a1.f1&&a1.f2&&a2.f1&&a2.f2)return a1.x>a2.x;
	if(a1.f1&&a1.f2)return 1;
	if(a2.f1&&a2.f2)return 0;
	return a1.x>a2.x;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	char ch1,ch2;
	int n,y,n1=0,n2=0,t1=0,t2=0,t3=0,t4=0,h=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch1>>ch2>>y;
		if(ch1+ch2!=97){
			if(ch1==49&&ch2==49)t3++;
			else t4++;
			n1++;
			a[n1].f1=ch1-48;
			a[n1].f2=ch2-48;
			a[n1].x=y;
		}
		else{
			if(ch1==49&&ch2==48)t1++;
			else t2++;
			n2++;
			b[n2].f1=ch1-48;
			b[n2].f2=ch2-48;
			b[n2].x=y;
		}
	}
	sort(b+1,b+n2+1,cmp1);
	for(int i=1;i<=n2;i++){
		cout<<b[i].f1<<b[i].f2<<b[i].x<<endl;
	}
	for(int i=1;i<=min(t1,t2);i++)h=h+b[i].x+b[i+t1].x;
	if(t1>t2){
		for(int i=t2+1;i<=t1;i++){
			n1++;
			t4++;
			a[n1]=b[i];
		}
	}
	else{
		for(int i=t1*2+1;i<=n2;i++){
			n1++;
			t4++;
			a[n1]=b[i];
		}
	}
	cout<<h<<endl;
	sort(a+1,a+n1+1,cmp2);
	for(int i=1;i<=t3;i++)
	{
		h+=a[i].x;
		if(i+t3<=n1)h+=a[i+t3].x;
	}
	cout<<h<<endl;
	return 0;
} 
