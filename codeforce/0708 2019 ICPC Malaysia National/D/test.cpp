#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	
	int count=1;
	while(true) {
		system("make.exe");
		system("D.Ali_The_Multi-billionaire.exe < make.txt > A.txt");
		system("DDD.exe < make.txt > B.txt");
		
		if(system("fc A.txt B.txt")) break;
		cout<<count++<<endl;
	}
	
	return 0;
}
