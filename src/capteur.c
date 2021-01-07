#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>

enum
{
    EMARQUE,
    ENOM,
    EID,
    EJOUR,
    EMOIS,
    EANNEE,
    ESEUILMAX1,
    ESEUILMAX2,
    ESEUILMIN1,
    ESEUILMIN2,
    ETYPE,
    EETAT,
    COLUMNS
};

void ajouter(capteur c1)
{
FILE* f;
f=fopen("user.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,c1.seuilmax1,c1.seuilmax2,c1.seuilmin1,c1.seuilmin2,c1.type,c1.etat);

fclose(f);
}
else printf("impossible d'ouvrir le fichier \n");
}

void affichage_cap(GtkWidget *liste)
{
     GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

    char marque[20];
    char nom[20];
    char id[20];
    char jour[20];
    char mois[20];
    char annee[20];
    float seuilmax1;
    float seuilmax2;
    float seuilmin1;
    float seuilmin2;
char type[20];
char etat[20];
    store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
 if(store==NULL)
{ 
renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",EMARQUE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmax1",renderer,"text",ESEUILMAX1,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmax2",renderer,"text",ESEUILMAX2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmin1",renderer,"text",ESEUILMIN1,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmin2",renderer,"text",ESEUILMIN2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",EETAT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 
 store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_STRING, G_TYPE_STRING);

   f=fopen("user.txt","r");

     if(f!=NULL)
        {
         f=fopen("user.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",marque,nom,id,jour,mois,annee,&seuilmax1,&seuilmax2,&seuilmin1,&seuilmin2,type,etat)!=EOF)
          {
           gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EMARQUE,marque,ENOM,nom,EID,id,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEUILMAX1,seuilmax1,ESEUILMAX2,seuilmax2,ESEUILMIN1,seuilmin1,ESEUILMIN2,seuilmin2,ETYPE,type,EETAT,etat, -1);
          }
        }
   fclose(f);

   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  

   }}

void supprimer1(char id[])
{
capteur c1;


FILE *f , *g;
    f=fopen("user.txt","r");
    g=fopen("dump.txt","w");
   if(f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,&c1.seuilmax1,&c1.seuilmax2,&c1.seuilmin1,&c1.seuilmin2,c1.type,c1.etat)!=EOF){
if(strcmp(c1.id,id)!=0)
fprintf(g,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,c1.seuilmax1,c1.seuilmax2,c1.seuilmin1,c1.seuilmin2,c1.type,c1.etat);
}
fclose(f);
fclose(g);
remove("user.txt");
rename("dump.txt","user.txt");
}
}
void modifier(char id1[],char marque[20],char nom[20],char id[20],char type[20],char etat[20],char jour[20],char mois[20],char annee[20],float seuilmax1,float seuilmax2,float seuilmin1,float seuilmin2)
{
capteur c2;
capteur c1;
FILE* f;
FILE* fich;
f=fopen("user.txt","r");
fich=fopen("tempcapt.txt","a");

if(f==NULL || fich==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,&c1.seuilmax1,&c1.seuilmax2,&c1.seuilmin1,&c1.seuilmin2,c1.type,c1.etat)!=EOF)
{
if(strcmp(c1.id,id1)==0)
{

fprintf(fich,"%s %s %s %s %s %s %f %f %f %f %s %s \n",marque,nom,id,jour,mois,annee,seuilmax1,seuilmax2,seuilmin1,seuilmin2,type,etat);}

else
fprintf(fich,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,c1.seuilmax1,c1.seuilmax2,c1.seuilmin1,c1.seuilmin2,c1.type,c1.etat);
}
fclose(f);
fclose(fich);
remove("user.txt");
rename("tempcapt.txt","user.txt");
}}

void recherche_capwg(GtkWidget *liste)
{
     GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

    char marque[20];
    char nom[20];
    char id[20];
    char jour[20];
    char mois[20];
    char annee[20];
    float seuilmax1;
    float seuilmax2;
    float seuilmin1;
    float seuilmin2;
char type[20];
char etat[20];
    store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
 if(store==NULL)
{ 
renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",EMARQUE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmax1",renderer,"text",ESEUILMAX1,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmax2",renderer,"text",ESEUILMAX2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmin1",renderer,"text",ESEUILMIN1,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Seuilmin2",renderer,"text",ESEUILMIN2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",EETAT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 
 store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_STRING, G_TYPE_STRING);

   f=fopen("rr.txt","r");

     if(f!=NULL)
        {
         f=fopen("rr.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",marque,nom,id,jour,mois,annee,&seuilmax1,&seuilmax2,&seuilmin1,&seuilmin2,type,etat)!=EOF)
          {
           gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EMARQUE,marque,ENOM,nom,EID,id,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEUILMAX1,seuilmax1,ESEUILMAX2,seuilmax2,ESEUILMIN1,seuilmin1,ESEUILMIN2,seuilmin2,ETYPE,type,EETAT,etat, -1);
          }
        }
   fclose(f);

   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  

   }}





