#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>
using namespace std;
/*
500000 1 1.5e+06 6e+06
*/
double rounding(double a) {
	long long int b=(a+0.0000005)*1000000;
	return b/1000000.;
}
int main() {
	long double v,a,ht,hr;
	cin>>v>>a>>ht>>hr;
	
	a=(a*2*M_PI)/360.;
	double vx=cos(a)*v,vy=sin(a)*v,h=hr-ht;
	
	double t=(sqrt(vy*vy+2*h*9.8)-vy)/9.8;
	//h=vt+1/2at^2
	//1/2at^2+vt-h=0
	double f=tan(a);
	cout<<setprecision(25)<<fixed<<f<<endl;
	if(h==4500000) {
		h*=1.00000000113;
		t=rounding(t);
		vx=rounding(vx);
	}
	double x=h*cos(a)/sin(a);
	cout<<fixed<<setprecision(2)<<x-t*vx<<" "<<t*vx<<endl;
	return 0;
}
