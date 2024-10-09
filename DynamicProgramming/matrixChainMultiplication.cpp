#include<iostream>
#include<vector>
#include<climits>  // For INT_MAX

using namespace std;

// Memoized solve function
int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) {
        return 0;  // No multiplication needed if only one matrix
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];  // Return previously computed result
    }
    
    int mn = INT_MAX;
    
    // Try partitioning at different points k
    for (int k = i; k <= j - 1; k++) {
        // Recursively calculate the cost of multiplying the two parts and the cost of multiplying the result
        int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        
        // Update the minimum cost
        if (temp < mn) {
            mn = temp;
        }
    }
    
    dp[i][j] = mn;  // Store the result in dp table
    return mn;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};  // Matrix dimensions array
    int n = arr.size();
    
    // Initialize the memoization table with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    // Call the solve function for the entire matrix chain
    int minCost = solve(arr, 1, n - 1, dp);  // Pass 1 and n-1 as i and j
    
    // Output the minimum multiplication cost
    cout << "Minimum number of multiplications is: " << minCost << endl;
    
    return 0;
}
