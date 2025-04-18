#include <stdio.h>
#include <stdlib.h>

// Proper macro to calculate the size of a given variable
#define SIZEOF_VAR(var) ((char*)(&var + 1) - (char*)(&var))

typedef struct XYZ {
    char b;
    // a valid char member
    // void a; // Removed as void cannot be a member variable type.
    int c; 
    int d;
    char a;// Added an int member for demonstration.
} xyz;

int main() {
    xyz st;
    printf("%d\n", sizeof(st));  // This will print the size of the structure 'xyz'.
    return 0;
}
