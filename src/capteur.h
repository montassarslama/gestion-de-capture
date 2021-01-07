#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
char marque[20];
char nom[20];
char id[20];
char type[20];
char etat[20];
char jour[20];
char mois[20];
char annee[20];
float seuilmax1;
float seuilmax2;
float seuilmin1;
float seuilmin2;

}capteur;
char idrech[20];

void ajouter(capteur c1);
void affichage_cap(GtkWidget *liste);
void supprimer(capteur c1);


void modifier(char id1[],char marque[20],char nom[20],char id[20],char type[20],char etat[20],char jour[20],char mois[20],char annee[20],float seuilmax1,float seuilmax2,float seuilmin1,float seuilmin2);

void recherche(char donnescapt[]);
int rech(char idrech[]);
void afficher_alarmants(float seuilmax);

void supprimer1(char id[]);
