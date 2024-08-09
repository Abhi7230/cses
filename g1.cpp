#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, m;
vector<vector<char>> maps;
vector<vector<bool>> visited;

bool allowed(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && maps[i][j] != '#';
}

int main() {
    cin >> n >> m;
    maps = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == '#') {
                visited[i][j] = true;
            }
            if (maps[i][j] == 'A') {
                start = {i, j};
            }
            if (maps[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    queue<tuple<pair<int, int>, string>> q;
    q.push({start, ""});
    visited[start.first][start.second] = true;

    string ans = "-1";

    while (!q.empty()) {
        auto [pos, path] = q.front();
        q.pop();

        if (pos == end) {
            ans = path;
            break;
        }

        int i = pos.first;
        int j = pos.second;

        // Check all four directions
        if (allowed(i, j + 1)) {
            q.push({{i, j + 1}, path + "R"});
            visited[i][j + 1] = true;
        }
        if (allowed(i + 1, j)) {
            q.push({{i + 1, j}, path + "D"});
            visited[i + 1][j] = true;
        }
        if (allowed(i - 1, j)) {
            q.push({{i - 1, j}, path + "U"});
            visited[i - 1][j] = true;
        }
        if (allowed(i, j - 1)) {
            q.push({{i, j - 1}, path + "L"});
            visited[i][j - 1] = true;
        }
    }

    if (ans == "-1") {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    return 0;
}
