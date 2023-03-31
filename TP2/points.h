#ifndef _POINTS_H_
#define _POINTS_H_

typedef struct SPoint {
  double x;
  double y;
} Point;

typedef struct STabPoint {
  int taille;
  int nb;
  Point* points;
} TabPoints;

/**
   Initialise le tableau de points \a tab. Il contient 0 points initialement, mais
   peut accueillir jusqu'à 100 points sans être agrandi.

   @param tab un pointeur vers une structure TabPoint.
*/
void TabPoints_init( TabPoints* tab );

/**
   Ajoute si possible le point \a p à la fin du tableau de points \a tab.
   
   @param tab  un pointeur vers une structure TabPoint valide.
   @param p un point.
*/
void TabPoints_ajoute( TabPoints* tab, Point p );

/**
   Modifie le \a i-ème point du tableau de points \a tab. Il devient
   le point \a p.
   
   @param tab  un pointeur vers une structure TabPoint valide.
   @param i un index valide (entre 0 et TabPoints_nb( tab ) )
   @param p un point.
*/
void TabPoints_set( TabPoints* tab, int i, Point p );

/**
   @param tab  un pointeur vers une structure TabPoint valide.
   @param i un index valide (entre 0 et TabPoints_nb( tab ) )
   @return le \a i-ème point du tableau de points \a tab.   
*/
Point TabPoints_get( TabPoints* tab, int i );

/**
   @param tab  un pointeur vers une structure TabPoint valide.
   @return le nombre de points utiles stockés dans le tableau de points \a tab.   
*/
int TabPoints_nb( TabPoints* tab );

/**
   Indique que le tableau de points \a tab n'est plus utilisé et
   libère la mémoire associée. Il passe à une taille 0.
  
   @param tab  un pointeur vers une structure TabPoint valide.
 */
void TabPoints_termine( TabPoints* tab );

int TabPoints_indexBasGauche( TabPoints* tab );

void TabPoints_triSelonT0( TabPoints* tab );

double TabPoint_orientation(Point pMoins2, Point pMoins1, Point p);

void swap(Point *a, Point *b);

#endif
