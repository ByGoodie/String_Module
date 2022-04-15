#include "karakter_islemleri.h"

void toStrLower(char* str1){
    for(int i=0;i<my_strlen(str1);i++){
        if((int)str1[i]>=65 && (int)str1[i]<=90){
            str1[i]=str1[i]+32;
        }
    }
}

void my_strcyp(char* str1,const char* str2){
    int len=my_strlen(str2);
    for(int i=0;i<len;i++){
        str1[i]=str2[i];
    }
}

int my_strlen(const char* str1){
    int i=0;
    while(*(str1+i)!='\0'){
        i++;
    }
    return i;
}

char* my_strcat(char* str1,char* str2){
    int i=0;
    while(*(str1+i)!='\0'){
        i++;
    }
    for(int j=0;*(str2+j)!='\0';j++,i++){
        *(str1+i)=*(str2+j);
    }
    *(str1+i)='\0';
    return str1;
}

int my_strcmp(char* str1,char* str2){
    int i=0;
    while(*(str1+i)!='\0'){
        i++;
    }

    int j=0;
    while(*(str2+j)!='\0'){
        j++;
    }

    if(i!=j){
        return 0;
    }

    for(int k=0;k<i;k++){
        if(*(str1+k)!=*(str2+k)){
            return 0;
        }
    }
    return 1;
}

int lexicographic_sort(const char* a, const char* b) {
    int len1=0,len2=0;
    while(*(a+len1)!='\0'){
        len1++;
    }

    while(*(b+len2)!='\0'){
        len2++;
    }

    if(len1<len2){
        len1=len2;
    }
    for(int i=0;i<len1;i++){
        if((int)a[i]>=65 && (int)a[i]<=90){

            if((int)b[i]>=65 && (int)b[i]<=90){

                if((int)a[i]>(int)b[i]){return 1;}

                else if((int)a[i]<(int)b[i]){return -1;}

                else{continue;}
            }

            if((int)a[i]+32 > (int)b[i]){return 1;}

            else if((int)a[i]+32 < (int)b[i]){return -1;}

            else{continue;}
        }

        if((int)b[i]>=65 && (int)b[i]<=90){

            if((int)a[i] > (int)b[i]+32){return 1;}

            else if((int)a[i] < (int)b[i]+32){return -1;}

            else{continue;}
        }

        if((int)a[i]>(int)b[i]){return 1;}

        else if((int)a[i]<(int)b[i]){return -1;}

        else{continue;}
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b){
    int len1=0,len2=0;
    while(*(a+len1)!='\0'){
        len1++;
    }

    while(*(b+len2)!='\0'){
        len2++;
    }

    if(len1<len2){
        len1=len2;
    }
    for(int i=0;i<len1;i++){
        if((int)a[i]>=65 && (int)a[i]<=90){

            if((int)b[i]>=65 && (int)b[i]<=90){

                if((int)a[i]<(int)b[i]){return 1;}

                else if((int)a[i]>(int)b[i]){return -1;}

                else{continue;}
            }

            if((int)a[i]+32 < (int)b[i]){return 1;}

            else if((int)a[i]+32 > (int)b[i]){return -1;}

            else{continue;}
        }

        if((int)b[i]>=65 && (int)b[i]<=90){

            if((int)a[i] < (int)b[i]+32){return 1;}

            else if((int)a[i] > (int)b[i]+32){return -1;}

            else{continue;}
        }

        if((int)a[i]<(int)b[i]){return 1;}

        else if((int)a[i]>(int)b[i]){return -1;}

        else{continue;}
    }
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    char aCopy[100],bCopy[100],transport;
    
    my_strcyp(aCopy,a);
    my_strcyp(bCopy,b);

    toStrLower(aCopy);
    toStrLower(bCopy);

    int len = my_strlen(aCopy);

    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i;j++){
            if(*(aCopy+j) > *(aCopy+j+1)){
                transport = *(aCopy+j);
                *(aCopy+j) = *(aCopy+j+1);
                *(aCopy+j+1) = transport;
            }
        }
    }

    len = my_strlen(bCopy);

    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i;j++){
            if(*(bCopy+j) > *(bCopy+j+1)){
                transport = *(bCopy+j);
                *(bCopy+j) = *(bCopy+j+1);
                *(bCopy+j+1) = transport;
            }
        }
    }
    
    len = my_strlen(aCopy);
    char chCurrent = *(aCopy);
    int aCounter=1;

    for(int i=0;i<len;i++){
        if(*(aCopy+i)!=chCurrent){
            chCurrent = *(aCopy+i);
            aCounter++;
        }
    }

    len = my_strlen(bCopy);
    chCurrent = *(bCopy);
    int bCounter=1;

    for(int i=0;i<len;i++){
        if(*(bCopy+i)!=chCurrent){
            chCurrent = *(bCopy+i);
            bCounter++;
        }
    }

    if(aCounter>bCounter){return 1;}
    else if(bCounter>aCounter){return -1;}
    return lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b){
    int len1=0,len2=0;
    while(*(a+len1)!='\0'){
        len1++;
    }

    while(*(b+len2)!='\0'){
        len2++;
    }

    if(len1>len2){return 1;}
    else if(len2>len1){return -1;}
    return lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char* transport;
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if((*cmp_func)(*(arr+j),*(arr+j+1))==1){
                transport = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = transport;
            }
        }
    }
}