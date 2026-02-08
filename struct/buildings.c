#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tip[50]; 
    char loc[50]; 
    int an; 
    float s; //(suprafata)
}CLADIRE; 


void citire(CLADIRE *a, int n){
    for(int i=0; i<n; i++)
    {
        printf("cladire %d: \n", i+1); 
        
        printf("tipul cladirii: "); 
        scanf("%s", a[i].tip); 
        
        printf("localizarea: "); 
        scanf("%s", a[i].loc); 
        
        printf("anul: "); 
        scanf("%d", &a[i].an); 
        
        printf("suprafata: "); 
        scanf("%f", &a[i].s); 
    }
}

int main(void)
{
    int n; 
    printf("introduceti nr de cladiri: "); 
    scanf("%d", &n); 
    
    CLADIRE *a= malloc(n*sizeof(CLADIRE)); 
    if(!a){
        printf("memorie insuf"); 
        exit(1); 
    }
    
    //a 
    citire(a, n); 
    
    //b 
    //ord cresc dup an 
    int sortat; 
    do{
        sortat =1; 
        for(int i=0; i<n-1; i++)
          if(a[i].an  >  a[i+1].an){
              CLADIRE aux; 
              aux = a[i]; 
              a[i] = a[i+1]; 
              a[i+1] = aux; 
              sortat =0; 
          }
    }while(sortat == 0); 
  
  printf("cladirile in ord cresc dupa an: \n"); 
  for(int i=0; i<n; i++)
    printf("%d. %s din anul %d\n", i+1, a[i].tip, a[i].an); 
    
   //c 
   //ord desc dp suprafata
   int gata; 
  do{
      gata =1; 
      for(int i=0; i<n-1; i++)
         if(a[i].s  <  a[i+1].s)
      {
          CLADIRE temp; 
          temp = a[i];
          a[i] = a[i+1]; 
          a[i+1] = temp; 
          gata=0; 
      }
  }while(gata ==0); 
  
  printf("introduceti anul curent: "); 
  int an_curent; 
  scanf("%d", &an_curent); 
  
  printf("cladirile din ult 3 ani cu suprafata mai mare de 400 mp: \n");
  for(int i=0; i<n; i++)
    if(a[i].an<=(an_curent-3) && a[i].s>400)
      printf("%s ", a[i].tip); 
  
  
  free(a); 
    return 0;
}