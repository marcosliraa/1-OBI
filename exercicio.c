/*Programa da OBI*/

#include <stdio.h>
#include <stdlib.h>

int processo(void);

int main(void)
{
  int resposta;
  resposta = processo();
  printf("%d\n",resposta);
}

int processo(void)
{
  int r, i, *x0, *xf, *y0, *yf;
  printf("Digite o numero de redes: \n");
  scanf("%d", &r);  
  if(r>100 && r<1)
  {
    prinf("Error, try again.");
    return EXIT_FAILURE;
  }
  else{
  x0=calloc(r,sizeof(int));
  xf=calloc(r,sizeof(int));
  y0=calloc(r,sizeof(int));
  xf=calloc(r,sizeof(int));
  }
  i=0;
  while(x0 != NULL)
  {
    printf("Digite a Variacao de X seguida da variacao de Y");
    scanf("%d,%d,%d,%d",x0[i],xf[i],y0[i],yf[i]);
    if(x0>100 && x0<1 || xf>100 || xf<1 || y0>100 || y0<1)
    {
      prinf("Error, try again.");
      return EXIT_FAILURE;
    }
  }

}
