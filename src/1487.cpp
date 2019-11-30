#include <bits/stdc++.h>

using namespace std;

#define MAX_ITEM 110
#define MAX_W 610

int V[MAX_ITEM];
int W[MAX_ITEM];

int memo[MAX_ITEM][MAX_W];

int knapsack(int i, int w) {
    if (i < 0 || w <= 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];

    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    return memo[i][w] = max(knapsack(i - 1, w),
      max(knapsack(i - 1, w - W[i]) + V[i],
      knapsack(i, w - W[i]) + V[i]));

}


int main() {


    int N, capacidade;
    int k=1;
    while(cin >> N >> capacidade,N){
      memset(memo, -1, sizeof memo);


    for(int i = 0; i < N; ++i) {
        cin >> W[i] >> V[i];
    }
    cout << "Instancia " << k << endl;
    cout << knapsack(N - 1, capacidade) << endl<< endl;
    k++;
  }
    return 0;
}
