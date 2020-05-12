#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define is_alpha_caps(x) (x >= 'A' && x <= 'Z')
#define is_alpha_lower(x) (x >= 'a' && x <= 'z')

struct {
    unsigned int use_random : 1;
    unsigned int change_next : 1;
} flags;

int main(const int argc, char** argv) {
    if(argc < 2) {
        puts("usage: mock-inator [-r] <sentence>");
        return 0;
    }

    int start = 1;
    int probability = RAND_MAX/2;
    /* TODO rewrite as while - is in [0] case on options */
    /* use random to be fancy */
    if(!strcmp("-r", argv[1])) {
        flags.use_random=1;
        /* skip option */
        start = 2;
    }


    /* lousy seed */
    srand(time(0));

    char c;
    int i;
    for(i=start; i<argc; i++) {
        while((c = *(argv[i]++))) {
            if(is_alpha_lower(c) && flags.change_next){
                putchar(c - 32);
                flags.change_next = 0;
            }
            else if(is_alpha_caps(c) && flags.change_next){
                putchar(c + 32);
               flags.change_next  = 0;
            }
            else{
                putchar(c);
                if(flags.use_random && rand() < probability) {
                    flags.change_next = 0;
                }
                else {
                    flags.change_next = 1;
                }
            }
        }
        putchar(' ');
    }
    printf("\n");
    return 0;
}
