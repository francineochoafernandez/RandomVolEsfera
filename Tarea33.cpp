#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>


using namespace std;
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

typedef struct Ran0
{
  float ran0(long *idum)
  {
    long k;
    float ans;

    *idum ^= MASK;
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;

    if (*idum < 0) *idum += IM;
    ans=AM*(*idum);
    *idum ^= MASK;

    return ans;
  }

  void line()
  {
    for(int i=1;i<30;i++)
    cout<<"--";
    cout<<"\n";
  }
}R0;


int main (void)
{
  R0 var;
  long ss= 45629;
  long *seed=&ss;

  float pi=3.141592653589793238;
  int npoints=100000; // N
  int n,npointsinside;
  float x,y,r,sq,f,fsum,fmean,I;
  r=1.0; //RADIO
  fsum=0.0;
  npointsinside=0;
  for(n=0;n<npoints;n++)
  {
    x=r*(2.0*var.ran0(seed)-1.0);
    y=r*(2.0*var.ran0(seed)-1.0);
    // los random están entre –r y r
    sq=x*x+y*y;
    if (sq < r*r)
    {
      f=sqrt(r*r-sq);
      fsum+=f;
      npointsinside++;
    }
  }
// valida que este en el rango f=sqrt(r*r-sq);

  if (npointsinside==0)
  {
    printf("No points inside. Increase npoints\n");
    return 0;
  }
  fmean=fsum/npointsinside; // calcula el promedio de f
  I=2*pi*r*r*fmean; //Riemann
  printf("Sphere volume is %.6f hits %d\n",I,npointsinside);
  return 0;
}
