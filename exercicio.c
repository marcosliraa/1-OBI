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
  int r, i, j, xr, yr, Au, *a, *x0, *xf, *y0, *yf;
  printf("Digite o numero de redes: \n");
  scanf("%d", &r);                          //recebe o numero de redes que foram jogadas ao mar
  
  if(r<1 || r>100)                         //avalia se o resultado esta compativel com as restrições  
  {
    printf("Error, try again.\n");
    return EXIT_FAILURE;
  }
 
  x0=calloc(r,sizeof(int));
  xf=calloc(r,sizeof(int));
  y0=calloc(r,sizeof(int));              //aloca memórias
  yf=calloc(r,sizeof(int));
  a=calloc(r,sizeof(int));
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
    if((x0<1 || x0>100) || (xf<1 || xf>100) || (y0<1 || y0>100) || (yf<1 || yf>100))    //restrições do problema
    {
        printf("Error, try again.\n");                               //se estiver fora das restrições imprime a mensagem
        return EXIT_FAILURE;
    }
    a[i] = (xf[i]-x0[i]) * (yf[i]-y0[i]);       //área que respresentará cada rede
    i++;
  }
   
  if(r == 1)                     //se possui apenas 1 rede a resposta será a área daquela rede
 {
   a[0] = (xf[0]-x0[0]) * (yf[0]-y0[0]);
   return a[0];
 }
   
  i=0;
  Au=0;
  while(i<r)
  {
    Au = Au + a[i];          //area total ocupada por todas as redes sem estar calculada as interseções
    i++;
  }
  i=j=0;
  for(i=0;i<r;i++)
  {
    for(j=0;j<r;j++)
    {
      if(x0[i]<x0[j]<xf[i])
      {
        if((x0[j] - x0[i]) < (xf[i] - x0[j]))
        xr = (xf[i] - x0[j]);                      //tamanho resultante de X se a condição acontecer
      }
      else{
        xr=();
      }
    }
  }
  
  for(i=0;i<r;i++)
  {
    for(j=0;j<r;j++)
    {
      if(y0[i]<y0[j]<yf[i])
      {
        if((y0[j] - y0[i]) < (yf[i] - y0[j]))
        yr = (yf[i] - y0[j]);                          //tamanho resultante de Y se a condição acontecer
      }
      else{
        yr=();
      }
    }
  }
   
   Au= Au - (xr * yr);                        //Área total utilizada
   
   return Au;
   
  
}
