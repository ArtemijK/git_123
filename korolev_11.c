#include <stdio.h>
//#include <iostream>
#include <string.h>
#include <stdlib.h>

struct aeroflot{
    char destination[20];
    int number;
    char brand[10];
};

typedef struct aeroflot aeroflot;

//new code//


void sort(aeroflot *array){
    int j=0, i=0;
    int sortnumber;
    aeroflot sortir;
    printf("\nDestination\tnumber\t\tbrand\n");

    for(i=0; i<6; i++){
        for(j=0; j<6-i; j++){
            if(((*(array+j)).number) > ((*(array+j+1)).number)){

                sortir = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = sortir;

            }
        }
    }

    for(i=0; i<7; i++){
        printf("%s\t\t%d\t\t%s\n", ((*(array+i)).destination), ((*(array+i)).number), ((*(array+i)).brand));
    }
}
void name(aeroflot *array){
    int i = 0, g = 0;
    printf("Enter destination\n");
    char namedestination[20];
    scanf("%s", namedestination);
    printf("Departing to the destination\nNumber\tBrand\n");
    for (i; i<7; i++){
        if ( strcmp(namedestination, array[i].destination) == 0){
            printf("%d\t%s\n", ((*(array+i)).number), ((*(array+i)).brand));
            g++;
        } else printf("Error\n");

    }
    if (g==0) printf("There are no such flights\n");
}


int main(){
    int i=0;
    int num = 6;
    aeroflot *array = (aeroflot*) malloc ((num+1) * sizeof(aeroflot));
    //aeroflot array[num];
    /*char namedestination[99];
    scanf("%s", &namedestination);
    printf("%s\n", namedestination);*/
    for(i; i<=num; i++){
        printf("Input destination %d -", i+1);
        scanf("%s", array[i].destination);
        //printf("%s\n", array[i].destination);
        printf("Input number - ");
        scanf("%d", &array[i].number);
        //printf("%d\n", array[i].number);
        printf("Input brand - ");
        scanf("%s", array[i].brand);
        //printf("%s\n", array[i].brand);
    }

    sort(array);
    free(array);
    name(array);
    free(array);
    return 0;
}

