#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100] = {0};
    const char *op = "+-*/";
    const char *num = "0123456789";

    while (fgets(str, 100, stdin))
    {
        char temp[100] = {0};
        const char *token = NULL;

        strcpy(temp, str);

        token = strtok(temp, op);

        while (token)
        {
            printf("%s\n", token);
            token = strtok(NULL, op);
        }

        strcpy(temp, str);

        token = strtok(temp, num);

        while (token)
        {
            printf("%s\n", token);
            token = strtok(NULL, num);
        }
    }

    return 0;
}