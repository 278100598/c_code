#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
const int MXT=10000;
int main() {
	for(int i=0;i<MXT;i++) {
		
		cout<<i<<"X\n";
		system("make.exe > make.txt");

		system("C.exe < make.txt > A.txt");
		system("Cxx.exe < make.txt > B.txt");
		 
		if(system("fc A.txt B.txt")) break;
	}
	return 0;
}
