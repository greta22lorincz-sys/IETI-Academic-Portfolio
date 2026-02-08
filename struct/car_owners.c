#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[50]; 
    int casatorit; 
    char masina[50]; 
    int an; 
}DATE; 

int main()
{
      printf("introduceti elementele tabloului: "); 
      int n; 
      scanf("%d", &n); 
      getchar(); 
      
      DATE *v= malloc(n*sizeof(DATE)); 
      if(!v){
          printf("nu exista spatiu suficient"); 
          exit(1); 
      }
      
      //a 
      for(int i=0; i<n; i++)
      {
          printf("introduceti datele persoanei %d: \n", i+1); 
          printf("numele: "); 
          scanf("%s", v[i].nume); 
          getchar(); 
          
          printf("casatorit (0/1): "); 
          scanf("%d", &v[i].casatorit); 
          getchar(); 
          
          printf("marca masinii (majuscule): "); 
          scanf("%s", v[i].masina); 
          getchar(); 
          
          printf("anul de fabricatie al masinii: ");
          scanf("%d", &v[i].an); 
          getchar(); 
      }
      
      //b 
      int maxi=-1, poz=-1;  
      for(int i=0; i<n; i++)
      {
          if(strcmp(v[i].masina, "DACIA")==0 && v[i].casatorit==0  )
            if(v[i].an > maxi){
              maxi = v[i].an; 
              poz=i; 
            }
      }
      if(poz>=0)
        printf("proprietarul de dacia cea mai noua necasatorit este: %s\n", v[poz].nume); 
    else printf("nu exsita astfel de pers. "); 
      
      
      //c
      int sortat; 
      do{
          sortat = 1; 
          for(int i=0; i<n-1; i++)
            if(strcmp(v[i].nume, v[i+1].nume) > 0)
            {
                DATE aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = 0;
            }
      }while(sortat == 0); 
      
     printf("tabloul sortat dupa nume: \n"); 
     for(int i=0; i<n; i++)
       printf("%s ", v[i].nume); 


    free(v); 
    return 0;
}