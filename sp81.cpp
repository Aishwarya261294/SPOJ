//the game of mastermind
#include <iostream>
#include <cstring>
#define REP(i,n) for(int i = 0; i < n; i++)

using namespace std;
int P, C, M;

struct Query {
    int guess[105];
    int count[105];
    int hit, match;
}

query[105];
int solution[105];

bool solve(int p) {
    REP(m, M)
        if (query[m].hit < 0   || query[m].hit   > P-p ||
            query[m].match < 0 || query[m].match > P-p) return false;

    if (p == P) return true;

    REP(c, C) {
        solution[p] = c;

        REP(m, M) {
            if (query[m].guess[p] == c)
                --query[m].hit;
            if (query[m].count[c]-- > 0)
                --query[m].match;
        }

        if (solve(p + 1)) return true;

        REP(m, M) {
          if (query[m].guess[p] == c)
            ++query[m].hit;
          if (++query[m].count[c] > 0)
            ++query[m].match;
        }
    }

    return false;
}

void getGuess() {
    memset(query, 0, sizeof(query));
    cin >> P >> C >> M;

    REP(m, M) {
        REP(p, P) {
            int g;
            cin >> g;
            query[m].guess[p] = g-1;
            ++query[m].count[g-1];
        }

        cin >> query[m].hit >> query[m].match;
        query[m].match += query[m].hit;
    }

    if (solve(0)) {
        REP(p, P) {
            if (p > 0) cout << " ";
            cout << solution[p] + 1;
        }

        cout << endl;
    } else {
        cout << "You are cheating!" << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--)
        getGuess();

    return 0;
}
