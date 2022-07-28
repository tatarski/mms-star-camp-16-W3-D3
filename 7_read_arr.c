#include<stdio.h>
// arr will be loaded from arr_file
int arr[100];
int arrC = 0;
int main() {
    // Open file for reading
    FILE* f = fopen("arr_file", "r");

    int cur_num;
    // Read int into cur_num
    // If fscanf returns EOF - stop
    while(fscanf(f, "%d", &cur_num) != EOF) {
        // Store cur_num to arr
        arr[arrC] = cur_num;
        arrC++;
    }
    // We could use this empty while instead
    // Not very readable :)
    // while(fscanf(f, "%d", arr + (arrC++))!=EOF){}

    // Print values from arr to stdout
    for(int i = 0; i < arrC; i++) {
        printf("%d ", arr[i]);
        // Instead we could use:
        // fprintf(stdout, "%d ", arr[i]);
    }
    fclose(f);
    return 0;
}