#ifndef GETFUN_H
#define GETFUN_H
#include <stdio.h>
#include <stdlib.h>

typedef char *string;

static inline int store_int(const char *quest)
{
    int val;
    printf("%s", quest);

    while (scanf("%d", &val) != 1)
    {
        while (getchar() != '\n');
        printf("%s", quest);
    }
    
    while (getchar() != '\n'); 
    return val;
}

static inline char *store_string(const char *quest)
{
    int capacity = 4;
    int i = 0;
    char c;
    char *text = malloc(capacity * sizeof(char));

    if (text == NULL)
    {
        return NULL;
    }

    printf("%s", quest);

    while ((c = getchar()) != '\n')
    {
        if (i == capacity - 1)
        {
            capacity *= 2;
            char *temp = realloc(text, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(text);
                return NULL;
            }
            text = temp;
        }
        text[i] = c;
        i++;
    }

    text[i] = '\0';
    return text;
}

static inline char store_char(const char *quest)
{
    char character;
    char extra;

    while (1)
    {
        printf("%s", quest);
        if (scanf(" %c%c", &character, &extra) == 2 && extra == '\n')
        {
            return character;
        }
        while (getchar() != '\n');
    }
}

static inline float store_float(const char *quest)
{
    float val;
    printf("%s", quest);

    while (scanf("%f", &val) != 1)
    {
        while (getchar() != '\n');
        printf("%s", quest);
    }

    while (getchar() != '\n');
    return val;
}

static inline long store_long(const char *quest)
{
    long val;
    printf("%s", quest);

    while (scanf("%ld", &val) != 1)
    {
        while (getchar() != '\n');
        printf("%s", quest);
    }

    while (getchar() != '\n');
    return val;
}

static inline double store_double(const char *quest)
{
    double val;
    printf("%s", quest);

    while (scanf("%lf", &val) != 1)
    {
        while (getchar() != '\n');
        printf("%s", quest);
    }

    while (getchar() != '\n');
    return val;
}

#endif
