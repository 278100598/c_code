#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	
	int count=0;
	while(true) {
		count++;
		
		system("make.exe > make.txt");
		system("G.exe < make.txt > A.txt");
		system("GGG.exe < make.txt > B.txt");
		if(system("fc A.txt B.txt")) break;
		cout<<count;
	}
	
	return 0;
}
/*
4
00:00 U
00:01 U
01:29 S
01:30 U
*/
