/* OBI 2011- Modalidade Programação Nível 2, Fase 1
* Questão 1- O mar não esta para peixe
* Autor: José Marcos de Lira Júnior
* Programa elaborado de forma simplificada
*/

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
    int r, i, j, Au, k, *x0, *xf, *y0, *yf;
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
        if((x0[i]<1 || x0[i]>100) || (xf[i]<1 || xf[i]>100) || (y0[i]<1 || y0[i]>100) || (yf[i]<1 || yf[i]>100))    //restrições do problema
        {
            printf("Error, try again.\n");                               //se estiver fora das restrições imprime a mensagem
            return EXIT_FAILURE;
        }
        i++;
    }
    Au = 0;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<100;j++)
        {
            int true = 0;
            for(k=0;k<r;k++)
            {
                if(x0[k]<=i && i<xf[k] && y0[k]<=j && j<yf[k])
                    true = 1;
            }
            if(true == 1)
                Au++;
        }
    }

    return Au;
}

