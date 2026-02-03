#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], 
                               dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][W];
}

// Space-optimized version using 1D array
int knapsackOptimized(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // Traverse from right to left to avoid overwriting
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    return dp[W];
}

int main() {
    int n, W;
    
    cout << "Enter number of items: ";
    cin >> n;
    
    cout << "Enter knapsack capacity: ";
    cin >> W;
    
    vector<int> values(n), weights(n);
    
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    int maxValue = knapsack(W, weights, values, n);
    cout << "\nMaximum value (2D DP): " << maxValue << endl;
    
    int maxValueOptimized = knapsackOptimized(W, weights, values, n);
    cout << "Maximum value (1D DP): " << maxValueOptimized << endl;
    
    return 0;
}
