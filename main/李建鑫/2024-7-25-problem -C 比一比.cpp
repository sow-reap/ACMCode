#include<iostream>
#include<algorithm>
using namespace std;
int a[1005],b[1005];
int n,sum;
int main()
{
	cin>>n;
	while(n)
	{
		sum=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++)
			if(a[n-i-1]>b[i]) sum++;
			else if(a[n-i-1]<b[i]) sum--;
		cout<<sum*200<<endl;
		cin>>n;
	}
	return 0;
}