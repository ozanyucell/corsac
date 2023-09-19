#include <stdio.h>
#include <math.h>

int gcd(int x, int y) {
    int gcd_val = (( x < y ) ? x : y);
    while (gcd_val > 0) {
        if (x % gcd_val == 0 && y % gcd_val == 0) {
            break;
        }
        gcd_val--;
    }
    return gcd_val;
}

int lcm(int x, int y) {
    int lcm_val = (( x > y ) ? x : y);
    while (lcm_val > 0) {
        if (lcm_val % x == 0 && lcm_val % y == 0) {
            break;
        }
        lcm_val++;
    }
    return lcm_val;
}

int main() {
    const int PRIMES[10] = {7841, 7853, 7867, 7873, 7877,
                            7879, 7883, 7901, 7907, 7919};

    int p = 3;
    int q = 7;
    printf("p = %d | ", p);
    printf("q = %d\n", q);

    int n = p * q;
    printf("n = %d\n", n);

    // int phi = (p-1) * (q-1);
    int phi = lcm(p-1, q-1);
    printf("phi = %d\n", phi);

    // 1 < e < phi,
    // and greatest common divisor between e and phi has to be 1,
    // in other words; e and phi has to be coprime numbers.
    int e;
    for (e = 2; 1 < e < phi; e++) {
        if (gcd(e, phi) == 1) {
            e = 17;
            break;
        }
    }
    printf("e = %d\n", e);

    int d = 2;
    while(d * e < phi) {
        if (gcd(d * e, phi) == 1) {
            break;
        }
        d += 1;
    }
    printf("d = %d\n", d);

    // char text[100];
    // scanf("%[^\n]s", text);

    return 0;
}
