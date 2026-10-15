#include <stdio.h>


int mccarthy91(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return mccarthy91(mccarthy91(n + 11));
    }
}

int main() {
    // Testing values from 85 to 105
    for (int i = 85; i <= 105; i++) {
        printf("M(%d) = %d\n", i, mccarthy91(i));
    }
    return 0;
}
