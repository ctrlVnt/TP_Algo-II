#include <assert.h>
#include <stdlib.h>
#include "points.h"

void TabPoints_init( TabPoints* tab )
{
  tab->taille = 100;
  tab->nb = 0;
  tab->points = (Point*) malloc( tab->taille * sizeof( Point ) );
}

void TabPoints_ajoute( TabPoints* tab, Point p )
{
  if ( tab->nb < tab->taille )
    tab->points[ tab->nb++ ] = p;
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
