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

void heapify(TabPoints *tab, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && tab->points[l].y > tab->points[largest].y){
        largest = l;
    }

    if (r < n && tab->points[r].y > tab->points[largest].y){
        largest = r;
    }
        
    if (largest != i) {
        swap(&tab->points[i], &tab->points[largest]);
        heapify(tab, n, largest);
    }
}

void heapsort(TabPoints *tab, int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(tab, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&tab->points[0], &tab->points[i]);
        heapify(tab, i, 0);
    }
}

void TabPoints_triSelonT0(TabPoints* tab) {
    Point *min = &tab->points[TabPoints_indexBasGauche(tab)];
    swap(min, &tab->points[0]);
    heapsort(tab, tab->nb);
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