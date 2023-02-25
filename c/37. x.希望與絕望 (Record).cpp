#include<iostream>
using namespace std;
int main() {
	string s;
	int atk,mh,c=0,mp=0;
	int enemy[3][3];
	cin>>s>>atk>>mh;
	bool out=true;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cin>>enemy[i][j];
			if(enemy[i][j]>0) out=false;
		}
	}
	int turn=0;
	for(;turn<s.size()&&!out;turn++) {
		int tx,ty;
		out=true;
		for(int i=2;i>=0&&out;i--) {
			for(int j=0;j<3&&out;j++) {
				if(enemy[j][i]>0) {
					out=false;
					tx=i;
					ty=j;
				}
			}
		}
		
		switch(s[turn]) {
			case 'C':
				enemy[ty][tx]-=atk;
				mp+=2;
				c+=1;
				break;
			case 'A':
				enemy[ty][tx]-=atk;
				mp+=(20+2*c);
				c=0;
				break;
			case 'B':
				enemy[ty][0]-=(atk*(1+0.2*c));
				enemy[ty][1]-=(atk*(1+0.2*c));
				enemy[ty][2]-=(atk*(1+0.2*c));
				c=0;
				break;
			case 'b':
				enemy[0][tx]-=(atk*(1+0.2*c));
				enemy[1][tx]-=(atk*(1+0.2*c));
				enemy[2][tx]-=(atk*(1+0.2*c));
				c=0;
				break;
		}
		
		if(mp>=100) {
			for(int i=0;i<3;i++) {
				for(int j=0;j<3;j++) {
					enemy[i][j]-=mh;
				}
			}
			mp=0;
		}
		
		out=true;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(enemy[i][j]>0) {
					out=false;
				}
			}
		}
	}
	
	if(turn==s.size()&&!out) {
		cout<<-1;
	} else {
		cout<<turn;
	}
	return 0;
}
