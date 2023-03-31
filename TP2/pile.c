#include <stdio.h>
#include <malloc.h>
#include "points.h"
#include "pile.h"

void PilePoints_init(PilePoints *pile)
{
    pile->nb = 0;
    pile->points = (Point *)malloc(pile->taille * sizeof(Point));
}

int PilePoints_estVide(PilePoints *pile)
{
    return pile->nb == 0;
}

/* empile : rajoute `nb` en haut de la pile `p` */
void PilePoints_empile(PilePoints *pile, Point p)
{
    if (pile->nb >= pile->taille)
        PilePoints_agrandir(pile);
    pile->points[pile->nb++] = p;
}

/* depile : enleve le nombre en haut de pile et le renvoie */
void PilePoints_depile(PilePoints *pile)
{
    pile->nb--;
}

Point PilePoints_sommet(PilePoints *pile)
{
    // n'arrive jamais
    Point point;
    point.x = 0;
    point.y = 0;
    if (pile->nb == 0) // n'arrive jamais
        return point;
    else
        return pile->points[pile->nb - 1];
}

Point PilePoints_deuxiemeSommet(PilePoints *pile)
{
    // n'arrive jamais
    Point point;
    point.x = 0;
    point.y = 0;
    if (pile->nb == 0) // arrive jamais
        return point;
    else
        return pile->points[pile->nb - 2];
}

void PilePoints_agrandir(PilePoints *pile)
{
    pile->points = (Point *)realloc(pile->points, pile->taille * 2 * sizeof(Point));
    pile->taille *= 2;
}

void PilePoints_termine(PilePoints *pile)
{
    free(pile->points);
    pile->nb = 0;
    pile->taille = 0;
}

int PilePoints_nb(PilePoints *pile)
{
    return pile->nb;
}

Point PilePoints_get(PilePoints *pile, int idx)
{
    return pile->points[idx];
}
