#include <stdio.h>

int main(int args, char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        printf("[%s]\n", argv[i]);
        i++;
    }
}