#include <iostream>
#include <cmath>
#include <vector>
#include <float.h>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

float distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

float perimeter(pair <int, int> p1, pair <int, int> p2, pair <int, int> p3){
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}

pair<float, vector<pair<int, int>>> helper(vector<pair<int, int>>& strip, float p) {
    float min_pr = p;
    vector<pair<int, int>> new_pair;

    sort(strip.begin(), strip.end(), compare2);

    for (size_t i = 0; i < strip.size(); i++) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_pr; j++) {
            float dist_ij = distance(strip[i], strip[j]);
            for (size_t k = j + 1; k < strip.size() && (strip[k].second - strip[j].second) < min_pr; k++) {
                float dist_jk = distance(strip[j], strip[k]);
                float dist_ki = distance(strip[k], strip[i]);
                float pr = dist_ij + dist_jk + dist_ki;
                if (pr < min_pr){
                    min_pr = pr;
                    new_pair.clear();
                    new_pair.push_back(strip[i]);
                    new_pair.push_back(strip[j]);
                    new_pair.push_back(strip[k]);
                }
            }
        }
    }

    return {min_pr, new_pair};
}

pair<float, vector<pair<int, int>>> devide_con(vector<pair<int, int>> points, float p) {
    if (points.size() <= 5) {
        return helper(points, p);
    };

    int mid = points.size() / 2;
    vector<pair<int, int>> L(points.begin(), points.begin() + mid);
    vector<pair<int, int>> R(points.begin() + mid, points.end());
    pair<int, int> midPoint = points[mid];

    pair<float, vector<pair<int, int>>> L_result = devide_con(L, p);
    pair<float, vector<pair<int, int>>> R_result = devide_con(R, p);
    pair<float, vector<pair<int, int>>> rec_res;
    pair<float, vector<pair<int, int>>> helper_res;
    rec_res = L_result.first <= R_result.first ? L_result : R_result;
    p = rec_res.first;

    vector<pair<int, int>> strip;
    for (const auto& point : points) {
        if (abs(point.first - midPoint.first) < p)
            strip.push_back(point);
    }
    helper_res = helper(strip, p);

    return rec_res.first <= helper_res.first ? rec_res : helper_res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    sort(points.begin(), points.end(), compare);
    vector<pair<int, int>> px(points.begin(), points.end());

    pair<float, vector<pair<int, int>>> result = devide_con(px, FLT_MAX);
    for (auto p : result.second) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}