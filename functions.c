#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

double sigmoid(double x){
  return(1/(1 + exp(-x)))
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
