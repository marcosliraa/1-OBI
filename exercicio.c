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
 
  x0=calloc(r,sizeof(int));
  xf=calloc(r,sizeof(int));
  y0=calloc(r,sizeof(int));
  yf=calloc(r,sizeof(int));
  
  i=0;
  while(i<r)
  {
    printf("Digite o valo de xf da rede %d\n",i+1);
    scanf("%d",&xf[i]);
    printf("Digite o valo de y0 da rede %d\n",i+1);
    scanf("%d",&y0[i]);
    printf("Digite o valo de yf da rede %d\n",i+1);
    scanf("%i",&yf[i]);
   

}
