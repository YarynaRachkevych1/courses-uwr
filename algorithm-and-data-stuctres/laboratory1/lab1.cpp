#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000005;

pair<int, int> edges[MAX_N];
int arrival[MAX_N];
int departure[MAX_N];
int indexes[MAX_N];
int stack[MAX_N];
int stack_index = 0;
int curr_time = 0;

int DFS()
{   
    stack[stack_index++] = 1;

    while (stack_index > 0) {
        int parent = stack[--stack_index];

        if (arrival[parent] == 0) {
            arrival[parent] = ++curr_time;

            stack[stack_index++] = parent;
            int i = indexes[parent];
            while (edges[i].first == parent){
                if (arrival[edges[i].second] == 0)
                   stack[stack_index++] = edges[i].second;
                i++;
            }
        } else {
            departure[parent] = ++curr_time;
        }
    }

    return 0;
}

void indexing(int n){
    for (int i = 0; i < n; i++)
        if (indexes[edges[i].first] == 0)
            indexes[edges[i].first] = i;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, q, v;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        cin >> v;
        edges[i].first = v;
        edges[i].second = i+1;
    }

    sort(edges, edges+n);
    indexing(n);

    DFS();

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (arrival[a] < arrival[b] && departure[a] > departure[b]) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }

    return 0;
}