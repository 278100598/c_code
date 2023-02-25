#include<iostream>
#include<time.h>
using namespace std;
bool ok[60*24];
int main() {
	srand(time(0));
	int count = 0;
	for(int i=0;i<60*24;i++) {
		if(rand()%3 == 0) {
			ok[i]=true;
			count++;
		} else ok[i]=false;
	}
	cout<<count<<endl;
	for(int i=0;i<60*24;i++) {
		if(!ok[i]) continue;
		char c;
		if(rand()%10 == 0) c='U';
		else c='S';
		
		string a=to_string(i/60),b = to_string(i%60);
		cout<<a<<":"<<b<<" "<<c<<endl;
	}
	
	return 0;
}
