#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[101][1001]; // assuming n <= 100 and W <= 1000

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Number of items: ";
    cin >> n;

    int wt[100], val[100]; // assuming max 100 items

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Max value: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
