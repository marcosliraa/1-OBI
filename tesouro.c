/*OBI 2011- Modalidade Programação Nível 2, Fase 1
 * Questão 2- Caça ao Tesouro
 * Autor: José Marcos de Lira Júnior*/

#include <stdio.h>

typedef struct
{
    int x,y;
} point_p;

typedef struct
{
    point_p p;
    int d;
}dis_p;

static int dist(point_p p,point_p q)
{
    int xr,yr;
    xr= p.x - q.x;
    if(xr<0)
        xr= -xr;
    yr= p.y - q.y;
    if(yr<0)
        yr = -yr;
    return xr + yr;
}

int main()
{
    point_p pt;
    processo();
    return 0;
}
int processo(void)
{
    int n,k,i;
    dis_p K[MAX];

    do
    {
        printf("Digite o a dimensao do quadriculado:\n");
        scanf("%d",&n);
        if(n<2 || n>100)
            printf("Erro, digite o valor correto da dimensao!\n\n");
    } while(n<2 || n>100);

    do
    {
        printf("Digite o numero de pistas:\n");
        scanf("%d",&k);
        if(k<1 || k>100)
            printf("Erro, digite o valor correto das pistas!\n");
    } while(k<1 || k>100);

    for(i=0;i<k;i++)
    {
        printf("Digite x da dica %d:\n",i+1);
        scanf("%d",&K[i].p.x);
        printf("Digite y da dica %d:\n",i+1);
        scanf("%d",&K[i].p.y);
        printf("Digite a distancia ao tesouro da dica %d:\n",i+1);
        scanf("%d",&K[i].d);

    }
    int x, y;
    bool test = false;
    point_p resposta;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            point_p pt = {x,y};
            for(i=0;i<k;i++)
            {
                if(dist(pt,K[i].p) != K[i].d)
                    break;
            }
            if(i==k)
            {
                if(test)
                    goto resp;
                test = true;
                resposta = pt;

            }
        }
    }
    printf("\n%d %d\n",resposta.x,resposta.y);
    return 0;
resp:
    printf("-1 -1\n");
    return 0;
}
