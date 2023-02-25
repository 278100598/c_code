#include<iostream>
using namespace std;
int N,arr[100];
int main() {
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	
	int d = arr[1] - arr[0];
	bool yes=true;
	for(int i=1;i<N;i++) {
		if(arr[i-1] + d != arr[i]) yes = false;
	}
	if(yes) cout<<arr[N-1]+d;
	else cout<<arr[N-1];
	
	return 0;
}
