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