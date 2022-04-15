#ifndef KARAKTER_ISLEMLERI_H
#define KARAKTER_ISLEMLERI_H

int my_strlen(const char*);
char* my_strcat(char*,char*);
int my_strcmp(char*,char*);
int lexicographic_sort(const char* a, const char* b);
int lexicographic_sort_reverse(const char* a, const char* b);
int sort_by_number_of_distinct_characters(const char* a, const char* b);
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b));
int sort_by_length(const char* a, const char* b);

#endif