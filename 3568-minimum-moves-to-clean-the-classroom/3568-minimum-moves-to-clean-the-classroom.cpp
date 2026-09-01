class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // litter[i][j] = bit number of litter at this cell
        vector<vector<int>> litter(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        // mask = uncollected litter
        int fullMask = (1 << cnt) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<array<int, 4>> q;

        // row, col, current energy, remaining litter
        q.push({sr, sc, energy, fullMask});
        vis[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Can't make another move
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Reset area restores energy
                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int id = litter[nr][nc];
                        nmask &= ~(1 << id);
                    }

                    if (!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};