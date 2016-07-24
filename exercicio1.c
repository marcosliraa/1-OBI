/*OBI 2011- Modalidade Programação Nível 2, Fase 1
 * Questão 1- O mar não esta para peixe
 * Autor: José Marcos de Lira Júnior
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
        if((x0[i]<1 || x0[i]>100) || (xf[i]<1 || xf[i]>100) || (y0[i]<1 || y0[i]>100) || (yf[i]<1 || yf[i]>100))    //restrições do problema
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

    i=0;
    for(i=0;i<r-1;i++)
    {
        for(j=i+1;j<r;j++)
        {
            if((x0[i]<=x0[j] && x0[j]<=xf[i]) && (x0[i]<=xf[j] && xf[j]<=xf[i]))
            {
                xr=(xf[j] - x0[j]);
                if((y0[i]<=y0[j] && y0[j]<=yf[i]) && (y0[i]<=yf[j] && yf[j]<=yf[i]))
                {
                    yr= yf[j] - y0[i];
                    Au= Au - (xr*yr);
                }
                if((y0[j]<y0[i]) && (y0[i]<yf[j] && yf[j]<=yf[i]))
                {
                    yr= yf[j] - y0[i];
                    Au = Au - (xr*yr);
                }

                if((y0[i]<=y0[j] && y0[j]<yf[i]) && (yf[j]>yf[i]))
                {
                    yr = (yf[i] - y0[j]);
                    Au = Au - (xr*yr);
                }

                if((y0[i]<=y0[j] && y0[j]<=yf[i]) && (y0[i]<=yf[j] && yf[j]<=yf[i]))
                {
                    yr = (yf[j] - y0[j]);
                    Au = Au - (xr*yr);
                }
                if((y0[j] < y0[i]) && (yf[j] > yf[i]))
                {
                    yr= yf[i]-y0[i];
                    Au= Au - (xr*yr);
                }

            }
            /*if((y0[i]<=y0[j]<=yf[i] && y0[i]<=yf[j]<=yf[i]))
             *{
             *if(x0[i]<=x0[j]<=xf[i] && x0[i]<=xf[j]<=xf[i])
             *Au = Au;
             *if(x0[j]<=x0[i] && x0[i]<=xf[j]<=xf[i])
             *Au = Au - (yf[j]-y0[j])*(x0[i]-x0[j]);
             *if(x0[i]<=x0[j]<=xf[i] && xf[j]>=xf[i])
             *Au = Au - (yf[j]-y0[j])*(xf[j]-xf[i]);
             *}*/
            if(x0[i]<=x0[j] && x0[j]<xf[i] && xf[j]>xf[i])
            {
                xr= (xf[i] - x0[j]);
                if(y0[i]<=y0[j] && y0[j]<yf[i] && yf[j]>yf[i])
                {
                    yr =(yf[i] - y0[j]);
                    Au = Au - (xr*yr);
                }
                if(y0[i]>y0[j] && y0[i]<yf[j] && yf[j]<=yf[i])
                {
                    yr=(yf[j] - y0[i]);
                    Au = Au - (xr*yr);
                }
                if(y0[i] > y0[j] && yf[j] > yf[i])
                {
                    yr =(yf[i] - y0[i]);
                    Au = Au - (xr*yr);
                }

            }
            if(x0[i]<xf[j] && xf[j]<=xf[i] && x0[i]>x0[j])
            {
                xr=(xf[j] - x0[i]);
                if(y0[i]<=y0[j] && y0[j]<yf[i] && yf[j]>yf[i])
                {
                    yr =(yf[i] - y0[j]);
                    Au = Au - (xr*yr);
                }
                if(y0[i]<yf[j] && yf[j]<=yf[i] && y0[i]>y0[j])
                {
                    yr=(yf[j] - y0[i]);
                    Au = Au - (xr*yr);
                }
                if(y0[i] > y0[j] && yf[j] > yf[i])
                {
                    yr =(yf[i] - y0[i]);
                    Au = Au - (xr*yr);
                }
            }
        }
    }


    return Au;


}

