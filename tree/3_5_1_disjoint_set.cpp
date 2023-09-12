#include <stdio.h>
#include <stdlib.h>

#define size 10

bool Initial(int set[]);

bool Union(int set[], int root1, int root2);

int Find(int set[], int x);


int main() {
    int disjointSet[size];
    return 0;
}

bool Initial(int set[]) {
    for(int i = 0; i < size; i++) {
        set[i] = -1;
    }
    return true;
}

bool Union(int set[], int root1, int root2) {
    if(root1 == root2)
        return false;
    set[root1] = root2;
    return true;
}

int Find(int set[], int x) {
    while(set[x] != -1) {
        x = set[x];
    }
    return x;
}
