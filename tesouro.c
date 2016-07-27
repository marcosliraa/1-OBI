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

