#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void split(char*, char*, int*);
long calc(int, char*, int);

int main(){

        char* str = malloc(256);
        char* op = malloc(8);
        int factor[10];

        fgets(str, 256, stdin);

        split(str, op, factor);

        //printf("%d %s %d\n", factor[0], op, factor[1]);

        long ans = calc(factor[0], op, factor[1]);
        printf("= %ld\n", ans);
        
        free(str);
        free(op);
        
        return 0;
}

void split(char* string, char* op, int* fac){

        int i = 0;
        int opIndex = 0;
        int facIndex = 1;
        fac[0] = atoi(string);
        
        while(string[i] != '\0' && string[i] != '\n'){

                if((string[i] < '0' || string[i] > '9') && string[i] != ' '){
                        //printf("debug : %c\n", string[i]);
                        op[opIndex] = string[i];
                        op[opIndex+1] = '\0';
                        opIndex++;

                        fac[facIndex] = atoi(&string[++i]);
                        facIndex++;
                }

                i++;
        }
         
}

long calc(int fac0, char* op, int fac1){

        long ans = 0;

        switch(op[0]){
              case '+':
                ans = fac0 + fac1;
                break;

              case '-':
                ans = fac0 - fac1;
                break;

              case '*':
                ans = fac0 * fac1;
                break;

              case '/':
                ans = fac0 / fac1;
                break;

              default:
                puts("invalid operator");
        }

        return ans;
}
