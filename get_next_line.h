#include "get_next_line.h"

size_t ft_strlen(const char *s) {
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

char *ft_strdup(const char *s) {
    int i = 0;
    char *dup = (char *)malloc(ft_strlen(s) + 1);
    if (!dup)
        return NULL;
    while (s[i]) {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}

char *ft_strjoin(char *s1, char *s2) {
    size_t i = 0, j = 0;
    char *new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_str)
        return NULL;
    while (s1 && s1[i]) {
        new_str[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        new_str[i + j] = s2[j];
        j++;
    }
    new_str[i + j] = '\0';
    free(s1);
    return new_str;
}

void ft_clean_buffer(char *buffer, int start) {
    int i = 0;
    while (buffer[start]) {
        buffer[i] = buffer[start];
        i++;
        start++;
    }
    buffer[i] = '\0';
}
