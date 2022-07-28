#include<stdio.h>
// We will be calling the program with the following command:
// ./a.out FILE_NAME
// argp[0] argp[1]
int main(int argc, char *argp[]) {
    // Open file for reading
    FILE* f = fopen(argp[1], "r");

    if(f == NULL) {
        perror("Could not open file\n");
        return 0;
    }

    int cur_sym;
    // '=' operator does 2 things:
    // - sets value of cur_sym
    // - return new value of cur_sym

    // (cur_sym = fgetc(f)) != EOF
    // Read symbol from file and store it in cur_sym
    // See whether cur_sym stores EOF
    // If cur_sym stores EOF then:
    // - fgetc failed
    // - fgetc has reaches the end of the file
    // See 'man fgetc'
    while((cur_sym = fgetc(f)) != EOF) {
        // Print current symbol
        printf("%c", cur_sym);
    }

    fclose(f);
    return 0;
}

// ./a.out FILE_NAME