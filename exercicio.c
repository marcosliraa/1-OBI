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
  
  if(r<1 || r>100)
  {
    printf("Error, try again.\n");
    return EXIT_FAILURE;
  }
 
  x0=calloc(r,sizeof(int));
  xf=calloc(r,sizeof(int));
  y0=calloc(r,sizeof(int));
  yf=calloc(r,sizeof(int));
  
  i=0;
  while(i<r)
  {
    printf("Digite o valo de x0 da rede %d\n",i+1);
    scanf("%d",&x0[i]);
    printf("Digite o valo de xf da rede %d\n",i+1);
    scanf("%d",&xf[i]);
    printf("Digite o valo de y0 da rede %d\n",i+1);
    scanf("%d",&y0[i]);
    printf("Digite o valo de yf da rede %d\n",i+1);
    scanf("%i",&yf[i]);
    if((x0<1 || x0>100) || (xf<1 || xf>100) || (y0<1 || y0>100) || (yf<1 || yf>100))
    {
        printf("Error, try again.\n");
        return EXIT_FAILURE;
    }
    i++;
  }
   

  }
