#include<stdio.h>
// arr will be written to arr_file
int arr[] = {1325, 1512, 125, 123, 15, 2141, 5561, 162, 6213513, 36325};
int arrC = 10;
int main() {
    // Open file for writing
    FILE* f = fopen("arr_file", "w");
    if(f==NULL) {
        perror("Coult not open file\n");
        return -1;
    }
    // Use fprintf to convert ints to strings and write then to file
    for(int* i = arr; i < arr + arrC; i++) {
        fprintf(f, "%d ", *i);
    }
    fclose(f);
}