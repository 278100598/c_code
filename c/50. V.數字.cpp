#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	srand(time(NULL));
	for(int i=0;i<t;i++) {
		cout<<(rand()%10)<<endl;
	}
	return 0;
}
