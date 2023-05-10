#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int a, b, n;
	cin>>a>>b>>n;
	int res = abs(a-b);
	
	for(int i=0;i<n;++i){
		int da, db;
		cin>>da>>db;
		a += da;
		b += db;
		int newRes = abs(a-b);
		if(newRes > res){
			res = newRes;
		}
	}
	cout<<res;
	
	
	return 0;
}
