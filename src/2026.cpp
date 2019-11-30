#include<bits/stdc++.h>

using namespace std;

#define n  1000
#define m  1005

int V[n];
int W[m];
int memo[1005][1005];
int knapsack(int num,int w){

        if(num<0 || w<0){return 0;}

        if(memo[num][w]!=-1){
            return memo[num][w];
        }
        else if(w - W[num]<0){ return knapsack(num-1,w);}

        else {
            return memo[num][w] = max(V[num]+knapsack(num-1,w - W[num]),knapsack(num-1,w));
        }

}


int main(){

    int num;
    cin >> num;
    int C;
    int v,w;
    for(int i=1;i<=num;i++){
        int num2;
        cin >> num2;
        cin >> C;
        memset(memo,-1,sizeof memo);
        memset(V,0,sizeof V);
        memset(W, 0, sizeof W );
        for(int j=0;j<num2;j++){
            cin >> V[j] >> W[j];
        }
            cout <<"Galho " << i << ":\nNumero total de enfeites: "<< knapsack(num2 -1,C)<< endl<< endl;

    } 

    return 0;
}