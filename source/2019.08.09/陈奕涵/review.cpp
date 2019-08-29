#include<bits/stdc++.h>
using namespace std;
long long Y;
//特判:Y<=5 或 Y是2的幂 
namespace tepan{

int calc(){
	long long i=0,x=1;
	while((x<<i)<Y)i++;
	if((x<<i)==Y)return i;
	else return -1;
}
bool check(){
	return (Y<=5 || calc()!=-1);
}
void putans(){
	if(Y==3)printf("4 5\n1 2\n1 3\n1 4\n2 4\n3 4\n");
	else if(Y==5)printf("5 8\n1 2\n1 3\n1 4\n1 5\n2 5\n3 5\n4 5\n2 4\n");
	else{
		int n=calc()+2,m=n*(n-1)/2;
		printf("%d %d\n",n,m); 
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				printf("%d %d\n",i,j);
	}
}

} 
//10+10+30=50
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	if(Y>1e9)return 0;
	//特判 
	if(tepan::check()){
		tepan::putans();
		return 0;
	}
	//正解:不会,告辞
	return 0; 
} 
