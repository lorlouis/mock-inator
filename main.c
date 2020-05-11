#include <stdio.h>

#define is_alpha_caps(x) (x >= 'A' && x <= 'Z')
#define is_alpha_lower(x) (x >= 'a' && x <= 'z')

int main(const int argc, char** argv) {
    if(argc < 2) {
        puts("usage: mock-inator <sentence>");
        return 0;
    }

    char c, last_was_modified;
    int i;
    for(i=1; i<argc; i++) {
        while((c = *(argv[i]++))) {
            if(is_alpha_lower(c) && !last_was_modified){
                putchar(c - 32);
                last_was_modified = 1;
            }
            else if(is_alpha_caps(c) && !last_was_modified){
                putchar(c + 32);
                last_was_modified = 1;
            }
            else{
                putchar(c);
                last_was_modified = 0;
            }
        }
        putchar(' ');
    }
    printf("\n");
    return 0;
}
