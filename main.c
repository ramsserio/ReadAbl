//
//  main.c
//  testsXOR
//
//  Created by yassir ramdani on 06/10/2017.
//  Copyright © 2017 ramsserio. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double sigmoid(double x){
    return(1/(1 + exp(-x)));
}

int getActivatedOutput(int x1,int x2, int w1, int w2 , int b){
    int z = w1*x1 + w2*x2 + b;
    
    if( z  >= 0){
        return  1;
    }
    
    return 0;
}

void Learn(int nbrValues,int *X1, int *X2,int *GroundTruth,float* w1,float* w2,float* b){
    

    int y;
    int lambda = 1;
    int m ;
    
    
    for(int p = 0 ; p<nbrValues ; p++){
        
        
        int x1 = * (X1 +p);
        int x2 = * (X2 +p);
        int Groundtruth = *(GroundTruth+p);
        
        y = getActivatedOutput(x1 ,x2 ,*w1,*w2,*b);

        int error = 0;
        
        for( m = 0 ; m <1000 ; m++){
            error = 0;
            y = getActivatedOutput(x1, x2,*w1,*w2,*b);
            
            error = Groundtruth - y;
            
            *w1 = *w1 + lambda*error*x1;
            *w2 = *w2 + lambda*error*x2;
            
            *b = *b + lambda*error;
        
            
        }

    }
    
}



int main (){

    // Je donne des w et b en random :
    float w1 = rand()%3 -1;
    float w2 = rand()%3 -1;
    float b  = rand()%3 -1;
    
    // le generateur de mimos XD hahah ca genere des random pour enseigner mon network
    int x1[1000]           ;
    int x2[1000]           ;
    int Groundtruth[1000]  ;
  

    for(int i =0 ; i<1000 ; i++){
        //1000 exemple generés auto par random
        x1[i] = rand()%2;
        x2[i] = rand()%2;
        
        //ici je choisis la loi que je veux appliquer
        Groundtruth[i] = x1[i] && x2[i];
    
        printf("%d and %d = %d\n",x1[i],x2[i],Groundtruth[i]);
    }
    
    
    int len = sizeof(x1)/sizeof(x1[0]);
    
    // je Learn les exemples a mon neural network via notre fonction learn
    Learn(len, x1, x2, Groundtruth, &w1, &w2, &b);
    // Ca marche a tous les coups !
    // grace aux 1000 exemples il apprend !
    // c'est un bon eleve c'est juste qu'il lui faut bcp d'exemples !!
    
    printf("1 : 1 => %d  \n",getActivatedOutput(1, 1, w1, w2, b));
    printf("0 : 1 => %d  \n",getActivatedOutput(0, 1, w1, w2, b));
    printf("1 : 0 => %d  \n",getActivatedOutput(1, 0, w1, w2, b));
    printf("0 : 0 => %d  \n",getActivatedOutput(0, 0, w1, w2, b));
    printf("w1 : %f   /   w2 : %f   /   b : %f    \n", w1, w2, b);

    
    printf("\n\n\n\n\n");
    return 0;
}
