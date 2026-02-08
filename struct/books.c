#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   char autor[50]; 
   char titlu[50]; 
   int an_ap; 
   char editura[30]; 
}CARTE; 

void citire(CARTE *v, int n){
    for(int i=0; i<n; i++)
    {
        printf("cartea %d: \n", i+1); 
        
        printf("autor= "); 
        scanf("%s", v[i].autor); 
        getchar(); 
        
        printf("titlu= "); 
        scanf("%s", v[i].titlu); 
        getchar(); 
        
        printf("editura= "); 
        scanf("%s", v[i].editura); 
        getchar(); 
        
        printf("an aparitie= "); 
        scanf("%d", &v[i].an_ap); 
    }
}


int main(void)
{
    printf("introduceti numarul de carti: "); 
    int n; 
    scanf("%d", &n); 
    
    CARTE *v= malloc(n*sizeof(CARTE)); 
    if(!v){
        printf("memorie insuficienta.\n"); 
        exit(1); 
    }
    
    //a 
    citire(v, n); 
    
    //b +c
    
    CARTE a[n]; 
    int j=0; 
    printf("cartile care au aparut intre 2004-2009: "); 
    for(int i=0; i<n; i++)
      if(v[i].an_ap >=2004 && v[i].an_ap<=2009){
        printf("%s ", v[i].titlu); 
        
        a[j++] = v[i]; 
      }
        
       int sortat; 
       do{
           sortat =1; 
           for(int i=0; i<j-1; i++)
             if(a[i].an_ap > a[i+1].an_ap){
                 CARTE aux; 
                 aux = a[i]; 
                 a[i] = a[i+1]; 
                 a[i+1] = aux; 
                 sortat =0; 
             }
       }while(sortat == 0); 
   
    
        
    printf("\ncartile (2004-2009) ordonate cresc dupa an: \n"); 
    for(int i=0; i<j; i++)
      printf("%s \n", a[i].titlu); 
    
   
   
    free(v); 
    return 0;
}