#include <stdio.h>

int main() {

    int xs[100000],ys[100000];
    int w[6][2] = {{-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
    int x = 0, y = 1;
    int l = 1, d = 0, s = 0;
    int i = 2;
    
    xs[0] = 0;
    ys[0] = 0;
    ys[1] = 1;
    xs[1] = 0;
    
    while (i < 100000) {
        if (d == 0 && s == l - 1 || s == l) {
            d++;
            s = 0;
        }

        if (d == 6) {
            x += w[5][0];
            y += w[5][1];
            xs[i] = x;
            ys[i] = y;
            i++;
            d = 0;
            s = 0;
            l++;
        }

        x += w[d][0];
        y += w[d][1];
        xs[i] = x;
        ys[i] = y;
        i++;
        s++;
    }

    int n;
    while (scanf("%d", &n) == 1)
        printf("%d %d\n", xs[n - 1], ys[n - 1]);

    return 0;
}