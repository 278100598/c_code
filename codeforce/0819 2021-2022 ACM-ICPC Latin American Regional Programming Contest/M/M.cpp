#include<iostream>
#include<vector>
#define mp make_pair
using namespace std;

struct ASMT {
	int t,d,index;
	bool used=false;
	ASMT(int t,int d,int i) {
		this->t = t;
		this->d = d;
		this->index = i;
	}
};

int N;
vector<ASMT> vec;
vector<int> ans;

int main()
{
    cin>>N;
    long long int sum=0;
    for(int i=0;i<N;i++) {
    	int t,d;
    	cin>>t>>d;
    	sum+=t;
    	vec.push_back(ASMT(t,d,i+1));
	}
	
	for(int i=0;i<N;i++) {
		for(int j=vec.size()-1;j>=0;j--) {
			if(vec[j].used) continue;
			
			if(sum <= vec[j].d) {
				sum -= vec[j].t;
				vec[j].used=true;
				ans.push_back(vec[j].index);
				break;
			}
		}
		
		if(ans.size() != i+1) {
			cout<<"*";
			return 0;
		}
	}
    
    for(auto i=ans.rbegin();i!=ans.rend();i++) cout<<*i<<" ";
    
    return 0;
}
/*
8
8 59
7 56
7 57
9 60
7 56
8 55
7 50
7 44
*/
