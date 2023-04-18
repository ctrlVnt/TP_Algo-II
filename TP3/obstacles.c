#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "obstacles.h"
#include <time.h>

void Obstacle_init(Obstacle *p, double r, double x, double y, double att)
{
    p->type = DISQUE;
    p->x[0] = x;
    p->x[1] = y;
    p->r = r;
    p->att = att;
    p->cr = 0;
    p->cg = 0;
    p->cb = 0;
}

void TabObstacles_init(TabObstacles *tab)
{
    tab->taille = 10;
    tab->nb = 0;
    tab->obstacles = (Obstacle *)malloc(tab->taille * sizeof(Obstacle));
}

void TabObstacles_ajoute(TabObstacles *tab, Obstacle p)
{
    if (tab->nb == tab->taille)
    {
        TabObstacles_agrandir(tab);
    }
    tab->obstacles[tab->nb] = p;
    tab->nb++;
}

void TabObstacles_set(TabObstacles *tab, int i, Obstacle p)
{
    tab->obstacles[i] = p;
}

Obstacle TabObstacles_get(TabObstacles *tab, int i)
{
    return tab->obstacles[i];
}
int TabObstacles_nb(TabObstacles *tab)
{
    return tab->nb;
}

void TabObstacles_termine(TabObstacles *tab)
{
    free(tab->obstacles);
    tab->nb = 0;
    tab->taille = 0;
}

Obstacle *TabObstacles_ref(TabObstacles *tab, int i)
{
    return tab->obstacles + i;
}

void TabObstacles_agrandir(TabObstacles *tab)
{
    tab->taille = tab->taille * 2;
    tab->obstacles = (Obstacle *)realloc(tab->obstacles, tab->taille * sizeof(Obstacle));
}

void TabObstacles_affiche(TabObstacles *tab)
{
    int i;
    printf("================================================================================\n");
    printf("| %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s |\n", "Obstacle", "Type", "r", "x", "y", "att", "cr", "cb", "cg");
    printf("|----------|----------|----------|----------|----------|----------|----------|----------|\n");
    for (i = 0; i < tab->nb; i++)
    {
        printf("| %-8d | %-8d | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f |\n", i, tab->obstacles[i].type, tab->obstacles[i].r, tab->obstacles[i].x[0], tab->obstacles[i].x[1], tab->obstacles[i].att, tab->obstacles[i].cr, tab->obstacles[i].cb, tab->obstacles[i].cg);
    }
    printf("================================================================================\n");
}