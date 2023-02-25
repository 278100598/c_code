#include<iostream>
#include<iomanip>
using namespace std;
int C,R;

int main() {
	cin>>R>>C;
	cout<<fixed<<setprecision(7)<<(R-C)*(R-C)*100/(double)(R*R);
	
	return 0;
}
