#include <stdio.h>
#include <math.h>
#include <time.h>

clock_t start,stop;
double duration, total_time, ticks;      //record the run time (seconds) of a function
double X = 1.0001;                       //base number

/**
 * Function: Algorithm_1
 * Params: N(int) The power 
 * Description: use N-1 multiplications
 * Returns: result(double) The result of X^N
 */
double Algorithm_1(int N) 
 {
 	int i;
 	double result = 1.0;       //store the result
 	for ( i=0 ; i<N ; i++){
 		result *= X;
	}
	return result;
 }
	
/**
 * Function: Algorithm_2rec
 * Params: N(int) The power 
           X(double) The base number 
 * Description: use recursion to compute the result
 * Returns: result(double) The result of X^N
 */
 double Algorithm_2rec(double X, int N)
 {
 	if( N == 0 )
 	    return 1;              //one end of the recursion
 	if( N == 1 )
 		return X;              //the other end of the recurtion
 	if( N % 2 == 0 )           //decide whether the number is even or odd  
 		return Algorithm_2rec( X * X , N / 2 );
    else 
    	return Algorithm_2rec( X * X , N / 2 ) * X;
 }
 
 /**
 * Function: Algorithm_2ite
 * Params: N(int) The power 
 * Description: use iteration version of algorithm 2 to compute the result
 * Returns: result(double) The result of X^N
 */
double Algorithm_2ite(int N)
 {
 	double a = X;              //use a to replace X, so X won't be changed
 	double result = 1.0;       //store the result 
 	while(N!=0){
 		if(N%2==1)             //decide whether N is an odd number
 			result *= a;
 		N /= 2;                //N halved 
 		a *= a;                //a squared
	}
	return result;
}

 /**
 * Function: main
 * Params: no params 
 * Description: input K and N 
                print time on the screen
 * Returns: no return
 */
int main()
{
	int N;                     //power
	int K , i;                 //repeat function calls for K times 
BEGIN:	scanf("%d %d",&N,&K);  //the begin of the proceture
	start = clock();
	
    //there are three algorithms below . 
    //each time we just use one and comment the other two  
    for(i = 0 ; i < K ; i++){
    	Algorithm_1(N);
	//	Algorithm_2rec(X,N);
	//	Algorithm_2ite(N);
	}
	
	stop = clock();
	ticks = (double)(stop-start);
	total_time = ((double)(stop-start))/CLK_TCK;
	duration = total_time/K;
	printf("ticks = %.6e    total_time = %.6e    duration = %.6e\n", ticks, total_time, duration);
	
	goto BEGIN;                //go to the begin
 }
 

