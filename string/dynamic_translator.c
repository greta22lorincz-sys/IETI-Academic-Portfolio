/*
 * Project: Dynamic Dictionary Translator (IETI Lab 6)
 * File: dynamic_translator.c
 * Aim: This program creates a dynamic dictionary by allocating memory for word pairs, 
 * allowing users to search for Romanian to English translations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocate(int n){
    char **a= malloc(n*sizeof(char*)); 
    if(!a){
        printf("error: insufficient memory.\n"); 
        exit(1); 
    }
    for(int i=0; i<n; i++){
      a[i] = malloc(40*sizeof(char));
      if(!a[i]){
          printf("insufficient memory.\n"); 
          exit(1); 
      }
    }
    return a; 
}

void release(char **a, int n){
    for(int i=0; i<n; i++)
      free(a[i]); 
      
    free(a); 
}

int main(void){
   printf("enter the number of words in the dictionary: "); 
   int n; 
   scanf("%d", &n); 
   getchar(); 
   
   char **rom= allocate(n); 
   char **eng= allocate(n); 
   
   printf("enter the %d words: \n", n); 
   
   for(int i=0; i<n; i++){
       printf("word in ROMANIAN: "); 
       scanf("%s", rom[i]); 
       
       printf("translation in ENGLISH: "); 
       scanf("%s", eng[i]); 
   }
   
   printf("enter the Romanian word for which you want the translation: "); 
   char word[30]=""; 
   scanf("%s", word); 
   
   int found=0; 
   for(int i=0; i<n; i++)
     if(strcmp(word, rom[i])==0){
         printf("the translation of %s in English is %s.\n", word, eng[i]);
         found=1; 
         break; 
     }
     if(found==0)
     printf("the word does not exist in the Romanian dictionary."); 
 
   release(rom, n); 
   release(eng, n); 
   return 0;     
}