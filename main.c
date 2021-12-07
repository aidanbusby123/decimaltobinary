#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int len_max = 1;
int current_size = 0;
char *dec;

unsigned int *decInt;
unsigned int *binInt;
unsigned int *temp;
int i, n, j, k;
int len;

void decToBin();
void charToInt();

int main(){
    
    
    dec = (char*)malloc(len_max);
    temp = (unsigned int*)malloc(sizeof(unsigned int));
    decInt = (unsigned int*)malloc(sizeof(unsigned int));
    binInt = (unsigned int*)malloc(sizeof(unsigned int));

    current_size = len_max;
    char c;

    
    printf("Enter Decimal Integer: \n");
    while ((c = getchar()) != '\n'){ //Allocate the correct amount of memory
        dec[i] = c;
        
        if (i == current_size){
            current_size = len_max + i;
            dec = (char*)realloc(dec, current_size * sizeof(char)+10);
            decInt = (unsigned int*)realloc(decInt, current_size * sizeof(unsigned int) + 10);
            temp = (unsigned int*)realloc(temp, current_size * sizeof(unsigned int) * 3); //Hard to predict size of binary output, so 3x size of input memory allocated
            binInt = (unsigned int*)realloc(binInt, current_size * sizeof(unsigned int) * 3);

        }
        i++;
       
    } 
    dec[i] = '\0'; //Terminate dec
    charToInt();
    decToBin();
}



void charToInt(){
    len = strlen(dec); 
    for (i = current_size-1; i >= 0; i--){
        decInt[i] = dec[len-i-1]-'0';
        
        
    }
} 
void decToBin(){
    j = 1;
    i = 0;
    while (j == 1){
       
        
        
        binInt[i] = decInt[0] % 2;
        
        for (n = 0; n <= len-1; n++){
            
            decInt[len-n-2] += 10*(decInt[len-n-1]%2);
            decInt[len-1-n] = decInt[len-1-n]/2;
            
        }
        i++;
        j = 0;
        for (k = 0; k <= len-1; k++){
            if (decInt[k] != 0){
                j = 1;
            } 
        }
    }
    
    for (n = 0; n <= i-1; n++){
        temp[n] = binInt[(i-1)-n];
    }
    for (n = 0; n <= i-1; n++){
        binInt[n] = temp[n];
        printf("%d",binInt[n]);
        printf("\n");
    }
        
}
