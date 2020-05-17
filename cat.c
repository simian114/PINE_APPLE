// 임시 테스트용 함수

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char a;

    while (scanf("%c", &a) > 0)
        printf("%c", a);
}
