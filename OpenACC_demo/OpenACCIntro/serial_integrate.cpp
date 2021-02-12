#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
int main(int argc, char** argv){

  // OpenACC initialise 
  // #pragma acc init

  int N= 1000000000;  //Now 10^9 Was 10^11  bigger than max int. 1 215 752 192
  double lower = -100;
  double upper = 100;
  double interval = upper - lower;
  double increment = interval/N;  
  double sum = 0.0;
  clock_t time;
  time = -clock();
  
  //Integrate from -pi to pi.
  //#pragma acc parallel loop reduction(+:sum)
  //#pragma acc parallel loop 
  for(int dx=0; dx<N; dx++) {
    
    //The x-axis value
    double x = lower + increment*(dx + 1.0/2);
    sum += increment * exp(-x*x);
    
  }

  time += clock();
 
  printf("Time elapsed for in seconds for  Intergration %.16f \n", time/(double)CLOCKS_PER_SEC); 


  printf("integral of exp(-x*x) from x=%.2e to %.2e = %.16f, error = %e%%.\n", lower, upper, sum, 100*(sum - sqrt(M_PI))/sqrt(M_PI));
  
  return 0;
}
