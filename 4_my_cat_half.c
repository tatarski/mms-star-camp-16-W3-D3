#include<stdio.h>
int main(int argc, char *argp[]) {
    FILE* f = fopen(argp[1], "r");
    if(f == NULL) {
        perror("Could not open file\n");
        return 0;
    }
    // Set stream position at end of file
    fseek(f, 0, SEEK_END);

    // Get current stream position with ftell
    // Stream position is at end of file
    // So this gives us number of symbols in file
    int symbol_count = ftell(f);
    int cur_sym;

    // Set stream position at middle of file
    fseek(f, symbol_count/2, SEEK_SET);
    
    // Read symbols while end of file is reached
    while((cur_sym = fgetc(f)) != EOF) {
        printf("%c", cur_sym);
    }

    // Dont forget to close file
    fclose(f);
    return 0;
}

// ./a.out FILE_NAME