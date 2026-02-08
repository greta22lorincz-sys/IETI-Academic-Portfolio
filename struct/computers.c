#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char procesor[30];
    int hard_disk;
    int memorie_ram;
    int an;
} CALC; 

void citire(CALC *v, int n){
    for(int i=0; i<n; i++)
    {
        printf("date calculator %d: \n", i+1); 
        
        printf("procesor= "); 
        scanf("%s", v[i].procesor); 
        
        printf("hard_disk= "); 
        scanf("%d", &v[i].hard_disk); 
        
        printf("memorie= "); 
        scanf("%d", &v[i].memorie_ram); 
        
        printf("an = "); 
        scanf("%d", &v[i].an); 
    }
}

void afisare(CALC *v, int n){
    printf("calculatoarele sunt: (dupa sortare)\n");
    for(int i=0; i<n; i++)
    {
        printf("%d. procesor: %s, hard disk: %d, ram: %d, anul: %d\n", i+1, v[i].procesor, v[i].hard_disk, v[i].memorie_ram, v[i].an); 
    }
}


int main(void)
{
    int n; 
    printf("numarul de calc: "); 
    scanf("%d", &n); 
    
    CALC *v= malloc(n*sizeof(CALC)); 
    if(!v){
        printf("memorie insuf"); 
        exit(1); 
    }
    
    //a 
    citire(v, n); 
    
    //b
    //ord desc dupa an 
    
    int sortat; 
    do{
        sortat =1; 
        for(int i=0; i<n-1; i++)
          if(v[i].an < v[i+1].an){
              CALC aux; 
              aux = v[i]; 
              v[i] = v[i+1]; 
              v[i+1] = aux;           
              sortat = 0; 
          }
    }while(sortat == 0); 
    
    afisare(v, n); 
    
    //c 
    printf("calc in ord cresc dupa an cu ram>1 si hard disk>=256 GB: \n"); 
    for(int i=n-1; i>=0; i--){
        if(v[i].hard_disk>=256 && v[i].memorie_ram>1)
          printf("procesor: %s, hard disk: %d, ram: %d, anul: %d\n", v[i].procesor, v[i].hard_disk, v[i].memorie_ram, v[i].an); 
    }
   
   
   free(v); 
    return 0;
}