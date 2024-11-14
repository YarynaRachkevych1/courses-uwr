#include <iostream>
#include <vector>

using namespace std;

void decode_coins(int W, int N, vector<int> chosenCoins, vector<int> wg){
    vector<int> result(N, 0);
    int w = W;
    while (w > 0 && chosenCoins[w] != -1) {
        result[chosenCoins[w]]++;
        w -= wg[chosenCoins[w]]; 
    }
    for (int i=0; i<N; i++){
        cout<<result[i]<< " ";
    }
    cout << endl;
}

bool solve2(int W, int N, vector<int> val, vector<int> wg){
    vector<int> values(W+1, 0);
    vector<int> weights(W+1, 0);
    vector<int> chosenCoins(W+1, -1); 

    for (int w=0; w < (W+1); w++){
        values[w] = 0;

        for (int i=0; i<N; i++){
            if (wg[i] <= w){
                int val_temp = values[w - wg[i]] + val[i];
                int weight_temp = weights[w - wg[i]] + wg[i];

                if (val_temp < values[w] || values[w] == 0){
                    values[w] = val_temp;
                    weights[w] = weight_temp;
                    chosenCoins[w] = i; // Record the index of the chosen coin
                }
            }
        }
    }

    if (weights[W] == W){
        cout << "TAK" << endl;
        cout << values[W] << endl;
        decode_coins(W, N, chosenCoins, wg);
        return true;
    } else {
        cout << "NIE" << endl;
        return false;
    }
}

bool solve(int W, int N, vector<int> val, vector<int> wg){
    vector<int> values(W+1);
    vector<int> weights(W+1);
    vector<int> chosenCoins(W+1, -1); 

    for (int w=0; w < (W+1); w++){
        values[w] = 0;

        for (int i=0; i<N; i++){
            if (wg[i] <= w){
                int val_temp = values[w - wg[i]] + val[i];
                int weight_temp = weights[w - wg[i]] + wg[i];

                if (val_temp > values[w]){
                    values[w] = val_temp;
                    weights[w] = weight_temp;
                    chosenCoins[w] = i; // Record the index of the chosen coin
                }
            }
        }
    }

    if (weights[W] == W){
        cout << values[W] << endl;
        decode_coins(W, N, chosenCoins, wg);
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int W, N;
    cin >> W;
    cin >> N;
    vector<int> val(N);
    vector<int> wg(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        val[i] = x;
        wg[i] = y;
    }

    if (solve2(W, N, val, wg)==true) {
        solve(W, N, val, wg);
    }

    return 0;
}