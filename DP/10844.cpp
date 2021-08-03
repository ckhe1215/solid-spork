#include <iostream>
using namespace std;

long long dp[101][11] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++) {
			if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for(int i = 0; i <= 9; i++){
		sum += dp[n][i];
	}
	cout << sum % 1000000000;
}
