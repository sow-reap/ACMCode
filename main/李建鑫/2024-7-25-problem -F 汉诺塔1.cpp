//这个程序看上去是On，但是n很大会超时，
//可以发现每层塔是2^n-1,那么
//通过快速幂直接求值会更简单更快
//2024.8.5
#include<iostream>
using namespace std;
int n;
int main()
{
	int a[10001];
	a[1]=1;
	for(int i=2;i<=10000;i++)
		a[i]=(a[i-1]*2+1)%1000000;
	int sum=a[10000];
	cin>>n;
	while(n--)
	{
		sum=a[10000];
		int t;
		cin>>t;
		if(t<=10000)
			cout<<a[t]<<endl;
		else 
		{
			for(int i=10001;i<=t;i++)
				sum=(sum*2+1)%1000000;
			cout<<sum<<endl;
		}
	}
	return 0;
}
