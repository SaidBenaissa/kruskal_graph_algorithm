#include <iostream>



int32_t I = INT32_MAX;

using namespace std;

// To check cycle is formed or not ( the first element will not used for this reason dim set[] = 8
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

// union fct
void Myunion(int u, int v) {

    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }

}

// collapsing find
int find(int u) {
    int x = u;
    int v = 0;

    while (set[x] > 0) {
        x = set[u];
    }
// when you find a parent of any vertex you can directly connect to it
    while (u != x) {
        v = set[u];
        set[u] = x;
        u = v;
    }

    return x;
}

int edges[3][9] = {{1,1,2,2,3,4,4, 5,5},
                   {2,6,3,7,4,5,7,6,7},
                   {25,5,12,10,8,16,14,20,18}};


// To check if the edges has been included or not (total 9 edges)
int included[9] = {0};

// t[][]  solution array
int t[2][6];


int main() {
    int j, k, u, v;
    int n = 7;
    int e = 9;
    int i = 0;
    int min = I;

// Because we "(n-1) edges" for this reason we use "while(i < n-1)"
// find the minimum that not included before
    while (i < n-1) {
        min = I;
        for (j = 0; j < e; j++) {
            if (included[j] == 0 && edges[2][j]<min) {
                min = edges[2][j];

//            record u,v for this minimum edges(u,v)
//            first vertex u
                u = edges[0][j];
//            second vertex v
                v = edges[1][j];

                // record the minimum in k
                k = j;
            }
        }

//    Performing find parent of u and v. If it's the same it forming a cycle don't added it the t[][] solution array
//    but mark it as includes in the included array in order to not check it again

// Otherwise if there parent (of u,v are not the some) then added it (u,v) to the solution array t[][]
        if (find(u) != find(v)) {
            t[0][i] = u;
            t[1][i] = v;
// then not forming a cycle --> Perform the union of there parent find(u), find(u)
            Myunion(find(u), find(u));
            i++;
        }
        included[k] = 1;
    }

// Print t[][] solution array solution

    for (i = 0; i < n-1; i++) {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}
