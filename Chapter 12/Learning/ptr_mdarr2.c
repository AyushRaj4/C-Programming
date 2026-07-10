// Name: ptr_mdarr2.c
// Purpose: To test some things related to multidimensional arrays and pointers.
// Author: Ayush Raj

int main(void) {
    int a[2][3], (*p)[3], b[2][3][4], (*p2)[3][4];
    p = a;
    p2 = b;

    int m = 2, n = 3, o = 4;
    int c[n][m], (*r)[3], d[n][m][o], (*r2)[m][o];
    r = c;
    r = a;
    r2 = d;
    r2 = b;

    // There is no difference in the type of a pointer pointing to the same dimension vla or fla, see lines 16, 17.
    // The difference is that the type of vla and its pointers is variably modified type, for fla and its pointer, the type is a complete type.
    // In a fixed-size array, the compiler calculates the jump size (e.g., rows * cols * sizeof(int)) at compile-time. In a VLA, it calculates that same size at runtime based on whatever values rows and cols hold at that moment.

    return 0;
}
