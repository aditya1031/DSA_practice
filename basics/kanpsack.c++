#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
  int weight;
  int value;
};

int knapsack_dp(vector<Item>& items, int capacity) {
  // Create a table to store the maximum profit that can be obtained by filling
  // the knapsack with items up to a certain capacity.
  vector<vector<int>> table(items.size() + 1, vector<int>(capacity + 1, 0));

  // Initialize the table.
  for (int i = 0; i <= items.size(); i++) {
    for (int j = 0; j <= capacity; j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else if (items[i - 1].weight <= j) {
        table[i][j] = max(table[i - 1][j],
                          table[i - 1][j - items[i - 1].weight] + items[i - 1].value);
      } else {
        table[i][j] = table[i - 1][j];
      }
    }
  }

  // Return the maximum profit that can be obtained by filling the knapsack with items.
  return table[items.size()][capacity];
}

int main() {
  vector<Item> items = {{1, 2}, {2, 3}, {3, 4}};
  int capacity = 5;

  int max_profit = knapsack_dp(items, capacity);

  cout << max_profit << endl;

  return 0;
}