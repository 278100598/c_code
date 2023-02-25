#include<iostream>
using namespace std;
int N;
long long int sum=0;

int main() {
	cin>>N;
	
	int x,pre;
	cin>>pre;
	for(int i=1;i<N;i++) {
		cin>>x;
		if(x < pre) sum += pre-x;
		else pre = x;
	}
	cout<<sum;
	
	return 0;
}
