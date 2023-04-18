#include "points.h"

typedef enum
{
    DISQUE
} ObstacleType;

typedef struct SObstacle
{
    ObstacleType type; //< Le type de l'obstacle. Ici on aura juste des DISQUEs.
    double x[DIM];     //< Les coordonnées du centre de l'obstacle.
    double r;          //< Le rayon de l'obstacle
    double att;        //< le facteur d'atténuation de l'obstacle (0.0 amortisseur parfait, 1.0 rebondisseur parfait, 3.0 "bumper" comme dans un flipper.)
    double cr, cg, cb; //< couleurs rgb de l'obstacle.
} Obstacle;

typedef struct STabObstacles
{
    int taille;          //< la taille de la liste d'obstacles
    int nb;              //< le nombre d'obstacles
    Obstacle *obstacles; //< la liste d'obstacles
} TabObstacles;

void Obstacle_init(Obstacle *p, double r, double x, double y, double att);

void TabObstacles_init(TabObstacles *tab);
void TabObstacles_ajoute(TabObstacles *tab, Obstacle p);
void TabObstacles_set(TabObstacles *tab, int i, Obstacle p);
Obstacle TabObstacles_get(TabObstacles *tab, int i);
int TabObstacles_nb(TabObstacles *tab);
void TabObstacles_termine(TabObstacles *tab);
Obstacle *TabObstacles_ref(TabObstacles *tab, int i);
void TabObstacles_agrandir(TabObstacles *tab);
void TabObstacles_affiche(TabObstacles *tab);
