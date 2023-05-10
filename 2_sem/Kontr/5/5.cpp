#include <iostream>
#include <vector>
#include <cmath>

#define int long long

using namespace std;

int r = 10000001;

signed main()
{
	int n;
	cin>>n;
	vector<int> dp(6, 0);
	dp[0]=1;
	int sum = 1;
	for(int i=1;i<6;++i){
		dp[i] = sum + 1;
		sum += dp[i];
	}
	
	if(n <= 6){
		cout << pow(2, (n-1));
		return 0;
	}
	
	
	sum = 63;
	for(int i=0;i<n-6;++i){
		int tmp  = dp[i%6];
		dp[i%6] = sum;
		sum = (2*sum+r - tmp)%r;
		//cout << i+6+1<<" : "<<dp[i%6]<<endl;
	}
	for(int i=0;i<6;++i){
		//cout<<dp[i]<<" ";
	}
	cout<<endl<<(dp[(n-1)%6])%r;
	
	/*
	for(int n=7;n<37;++n){
	int res = 32;
	for(int i=0;i<(n-6);++i){
		res = (res*2 - 1)%r;
	}
	cout<<n<<": "<<res<<endl;
}
cout<<11986433%r;
*/	
	return 0;
}
