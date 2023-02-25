#include<iostream>
#include<time.h>
#include<set>
using namespace std;

int r(int min,int max) {
	int a = rand()%10000,b = rand()%10000,c = rand()%10;
	int d=a*100000+b*10+c;
	return d%(max-min+1)+min;
}
long long int llr(long long int min,long long int max) {
	long long int a=r(0,1e9-1),b=r(0,1e9-1);
	long long int c=a*1e9+b;
	return c%(max-min+1)+min;
}
long long int M,N;
string s="";

int main() {
	srand(time(0));
	
	
	N=r(1,20);
	M=r(1,N);
	cout<<N<<" "<<M<<endl;
	for(int i=0;i<M;i++) s+=char(r('a','c'));
	cout<<s<<endl;
	
	for(int i=0;i<N;i++) {
		set<char> st;
		st.insert(char(r('a','c')));
		st.insert(char(r('a','c')));
		st.insert(char(r('a','c')));
		
		cout<<st.size();
		for(char j:st) cout<<" "<<j;
		cout<<endl;
	}
	
	return 0;
}
