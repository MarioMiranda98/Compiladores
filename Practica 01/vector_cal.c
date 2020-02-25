#include <stdio.h>
#include "vector_cal.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/*void init(){
   int i;
   for(i = 0;i < 26;i++)
      mem[i]=creaVector(3);
}*/

Vector *creaVector(int n){
   Vector *vec;
   int i;
   vec=(Vector *)malloc(sizeof(Vector));
   vec->n = n;	
   vec->vec = (double *)malloc(sizeof(double)*n);
   return vec;
}

void imprimeVector(Vector *v){
   int i; 

   printf("[");

   for(i=0; i< v->n; i++)
      printf("%f ", v->vec[i]);

   printf("]\n");
}

Vector *copiaVector(Vector *v){
   int i;
   Vector *copy=creaVector(v->n);
   for(i = 0; i< v->n; i++)
      copy->vec[i]=v->vec[i];	
   return copy;	
}

Vector *sumaVector(Vector *a, Vector *b){
Vector *c;
int i;
   c=creaVector(a->n);
   for(i=0; i< a->n;i++)
      c->vec[i]=a->vec[i]+b->vec[i];
   return c;
}

Vector *restaVector(Vector *a, Vector *b){
Vector *c;
int i;
   c=creaVector(a->n);
   for(i=0; i< a->n;i++)
      c->vec[i]=a->vec[i]-b->vec[i];
   return c;
}

Vector *escalarVector(double c, Vector *v){
  
    Vector *r_vector = creaVector(v -> n);
    int i;
                                                                                              
    for(i = 0; i < v -> n; i++){                                                                            
        r_vector -> vec[i] = c * v->vec[i];   
    }
  return r_vector;
}

Vector *productoCruz(Vector *a, Vector *b){
  Vector *r;
  r = creaVector(a -> n);

  if(a-> n == 2){
        r -> vec[0] = a -> vec[0] * b ->vec[1];
        r -> vec[1] -= a -> vec[1] * b -> vec[0]; 
    } 
    else if(a -> n == 3){
        r -> vec[0] = a -> vec[1] * b -> vec[2] 
            - a -> vec[2] * b -> vec[1];
            
        r -> vec[1] = a -> vec[2] * b -> vec[0]
            - a -> vec[0] * b -> vec[2];
        
        r -> vec[2] = a -> vec[0] * b -> vec[1] 
            - a->vec[1] * b -> vec[0];
    }
    return r;
}

double productoPunto(Vector *a, Vector *b){
    double resultado = 0.0f;
    int i; 
    for(i = 0; i < a->n; i++){
        resultado += ( a -> vec[i] * b->vec[i] );
    }
    return resultado;
}

double vectorMagnitud(Vector *a){
    double resultado = 0.0f;
    int i;
    for(i = 0; i < a->n; i++){
        resultado += ( a -> vec[i] * a -> vec[i] );
    }
    resultado = sqrt(resultado);
    return resultado;
}

/*
Vector *multiVector(Vector *a, Vector *b){
Vector *c;
int i,j, k; 
double acu;
        c=creaVector(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++){
			acu=0;
			for(k=0; k < a->n;k++){
                         
				acu=acu+a->mat[i][k]*b->mat[k][j];
				//printf("<%f,%f,%f> ",a->mat[i][k],b->mat[k][j],acu);
                        }             
                        //printf("\n");
			c->mat[i][j]=acu;
		}
	return c;
}*/
