#include <assert.h>
#include <stdio.h>
#define TABLE_SIZE 1000001
int table[TABLE_SIZE] = {0, 1, 1};

int main() {
    for (int i = 2; i < TABLE_SIZE; ++i) {
        table[i] = (table[i-1] + table[i-2]) % 100000007;
    }
    int n = 0;
    scanf("%i", &n);
    
    for (int i = 0; i < n; ++i) {
        int index = 0;
        scanf("%i", &index);
        printf("%i\n", table[index]);
    }
}
