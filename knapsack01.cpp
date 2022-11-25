#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &val, vector<int> &wt, int w, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (wt[i - 1] <= w)
			{
				dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][w];
}

int main()
{
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};

	int w = 50;			// capacity of knapsack
	int n = val.size(); // number of items

	cout << knapsack(val, wt, w, n);

	return 0;
}

// int knapSack(int W, int wt[], int val[], int n)
// {
// 	int i, w;
// 	vector<vector<int>> K(n + 1, vector<int>(W + 1));

// 	for(i = 0; i <= n; i++) {
// 		for(w = 0; w <= W; w++) {
// 			if (i == 0 || w == 0) K[i][w] = 0;
// 			else if (wt[i - 1] <= w) {
//                 K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
//             }
// 			else K[i][w] = K[i - 1][w];
// 		}
// 	}
// 	return K[n][W];
// }

// int main()
// {
// 	int val[] = { 60, 100, 120 };
// 	int wt[] = { 10, 20, 30 };
// 	int W = 50;
// 	int n = sizeof(val) / sizeof(val[0]);

// 	cout << knapSack(W, wt, val, n);	// n = 3

// 	return 0;
// }
