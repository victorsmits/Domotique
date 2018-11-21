#include <stdio.h>
# include <stdbool.h>

# define ALARM      1
# define HEATING    2
# define COOLING    4
# define LIGHTS     8
# define DOORLOCK   16
# define SPRINKLE   32

bool is_set ( unsigned char *, unsigned short );
void set ( unsigned char *, unsigned short );
void print_bits ( unsigned char n);

int main() {
    unsigned char config = 0;
    print_bits ( config ); printf ("\n");

    set (& config , HEATING | SPRINKLE );
    print_bits ( config ); printf ("\n");

    printf ("%d\n", is_set (& config , LIGHTS ));
    printf ("%d\n", is_set (& config , SPRINKLE ));

    return 0;
}

bool is_set ( unsigned char *config, unsigned short test ){
    return (bool) ((*config) & (1 << test));
}

void set ( unsigned char *config, unsigned short elem ){
    *config = elem;
}
void print_bits ( unsigned char n)
{
    char i;
    for (i = 8 * sizeof ( unsigned char ) - 1; i >= 0 ; i --)
    printf ("%d", (1 << i & n) >> i);
}
