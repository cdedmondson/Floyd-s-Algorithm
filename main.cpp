/*
 *
 *  My solution to Floyd's algorithm
 *
 */


#include <iostream>
#include <array>

using namespace std;

// Path 'P'
int P[200][200];

void path(int q, int r);

int main() {

    // Initialize matrix size
    int n = 4;
    // Distance 'D'
    int D[n][n];

    char exit;
    int q, r;

    // Adjacency matrix graph
    int W[n][n] = {{0,    8,    2000, 1},
                   {2000, 0,    1,    2000},
                   {4,    2000, 0,    2000},
                   {2000, 2,    9,    0},
    };

    /*
     * Copy original graph 'W' to Distance matrix 'D'
     * and initialize Path matrix 'P'
     */
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            D[i][j] = (W[i][j]);
            P[i][j] = 0;

        }
    }

    std::cout << "\n";

    /*
     * Use Floyd's algorithm to find shortest path
     * and distance from each node
     * i = row
     * j = column
     * k = iteration
     */
    for (int k = 0; k < n; k++) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (D[i][k] + D[k][j] < D[i][j]) {

                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];

                }
            }
        }

    }

    // Display Distance matrix in console
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    // Display Path matrix in console
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }

    do {

        cout << "\n";

        cout << "Enter starting vertex 'q': ";
        cin >> q;
        q = q - 1;
        cout << "Enter ending vertex 'r': ";
        cin >> r;
        r = r - 1;

        // Print starting vertex q
        cout << "Shortest path: v" << q + 1 << "--->";

        path(q, r);

        // Print ending vertex r
        cout << "v" << r + 1;
        // Display weight
        cout << "\nweight = " << D[q][r];

        cout << "\nEnter 'e' to exit program: ";
        cin >> exit;

    } while (exit != 'e');

    return 0;
}

void path(int q, int r) {

    if (P[q][r] != 0) {

        path(q, P[q][r] - 1);
        cout << "v" << P[q][r] << "--->";
        path(P[q][r] - 1, r);

    }

}
