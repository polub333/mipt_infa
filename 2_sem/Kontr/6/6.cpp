#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int inf = 1000000000;
	int n;
	cin>>n;
	vector<int> v(n+1);
	v[1] = 0;
	v[0] = 0;
	for(int i=2;i<=n;++i){
		int a = inf;
		int b = inf;
		if(i%2 == 0){
			a = v[i/2];
		}
		if(i%3 == 0){
			b = v[i/3];
		}
		v[i] = min(min(a, b), v[i-1]) + 1;
	}
	
	cout<<v[n];
	
	return 0;
}
