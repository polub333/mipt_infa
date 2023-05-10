#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double f = 0;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		double num;
		cin>>num;
		f += 1/num;
	}
	double am;
	cin>>am;
	cout << ceil(am / f);
	
	return 0;
}
