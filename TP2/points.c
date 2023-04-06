#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "points.h"

/* changer le point a avec b */
void swap(Point *a, Point *b);

void TabPoints_init( TabPoints* tab )
{
  tab->taille = 100;
  tab->nb = 0;
  tab->points = (Point*) malloc( tab->taille * sizeof( Point ) );
}

void TabPoints_double(TabPoints *tab)
{
  tab->points = (Point *)realloc(tab->points, tab->taille * 2 * sizeof(Point));
  tab->taille *= 2;
}

void TabPoints_ajoute(TabPoints *tab, Point p)
{
  if (tab->nb >= tab->taille)
    TabPoints_double(tab);
  tab->points[tab->nb++] = p;
}

void TabPoints_set( TabPoints* tab, int i, Point p )
{
  assert ( i < tab->nb );
  tab->points[ i ] = p;
}

Point TabPoints_get( TabPoints* tab, int i )
{
  assert ( i < tab->nb );
  return tab->points[ i ];
}

int TabPoints_nb( TabPoints* tab )
{
  return tab->nb;
}

void TabPoints_termine( TabPoints* tab )
{
  if ( tab->points != NULL ) free( tab->points );
  tab->taille = 0;
  tab->nb = 0;
  tab->points = NULL;
}

int TabPoints_indexBasGauche( TabPoints* tab ){

  Point *pMin = tab->points;
  int min = 0;

  for (int i = 0; i < tab->nb; i++)
  {
    if (tab->points[i].y < pMin->y){
      pMin = &tab->points[i];
      min = i;
    }
  }
  return min;
}

int cmp(Point origine, Point a, Point b)
{
    return TabPoint_orientation(origine, a, b) > 0;
}

void quicksort(TabPoints *tab, int first, int last)
{
    int pivot, i, j;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (cmp(tab->points[0], tab->points[i], tab->points[pivot]) && i < last)
                i++;
            while (!cmp(tab->points[0], tab->points[j], tab->points[pivot]) && j > first)
                j--;
            if (i < j)
            {
                swap(&tab->points[i], &tab->points[j]);
            }
        }
        swap(&tab->points[pivot], &tab->points[j]);
        quicksort(tab, first, j - 1);
        quicksort(tab, j + 1, last);
    }
}

void TabPoints_triSelonT0(TabPoints* tab) {
    Point *min = &tab->points[TabPoints_indexBasGauche(tab)];
    swap(min, &tab->points[0]);
    quicksort(tab, 1, tab->nb - 1);
}


double TabPoint_orientation(Point pMoins2, Point pMoins1, Point p)
{
  return (pMoins1.x - pMoins2.x) * (p.y - pMoins2.y) - (pMoins1.y - pMoins2.y) * (p.x - pMoins2.x);
}

void swap(Point *a, Point *b){
    Point tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

Point *TabPoints_min(TabPoints *tab)
{
  Point *min = tab->points;
  for (int i = 0; i < tab->nb; i++)
  {
    if (tab->points[i].y < min->y)
      min = &tab->points[i];
  }
  return min;
}