#include <config.h>
#include <string.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
int x;
void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout ,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_button5wg_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *fenetre_ajout ,*fenetre_afficher;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);

}

void
on_button6wg_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
capteur c1;

GtkWidget *input1, *input2,*input3;
GtkWidget *fenetre_ajout;
GtkWidget *combobox1 ,*combobox2 ,*combobox3;
GtkWidget *spinbutton1wg ,*spinbutton2wg ,*spinbutton3wg ,*spinbutton4wg;
GtkWidget *radiobutton1 ,*radiobutton2;
GtkWidget *checkbutton1 ,*checkbutton2;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
combobox1=lookup_widget(objet, "combobox1") ;
combobox2=lookup_widget(objet, "combobox2") ;
combobox3=lookup_widget(objet, "combobox3") ;

spinbutton1wg=lookup_widget(objet, "spinbutton1wg") ;
spinbutton2wg=lookup_widget(objet, "spinbutton2wg") ;
spinbutton3wg=lookup_widget(objet, "spinbutton3wg") ;
spinbutton4wg=lookup_widget(objet, "spinbutton4wg") ;

input1=lookup_widget(objet, "entry3wg") ;
input2=lookup_widget(objet, "entry5wg") ;
input3=lookup_widget(objet, "entry2") ;

radiobutton1=lookup_widget(objet, "radiobutton1") ;
radiobutton2=lookup_widget(objet, "radiobutton2") ;

checkbutton1=lookup_widget(objet, "checkbutton1") ;
checkbutton2=lookup_widget(objet, "checkbutton2") ;


strcpy(c1.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c1.id,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c1.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c1.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(c1.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(c1.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

c1.seuilmax1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton1wg));
c1.seuilmax2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton2wg));
c1.seuilmin1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton3wg));
c1.seuilmin2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton4wg));

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton1)))
{

strcpy(c1.type,"Temperature");
}
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton2)))
{

strcpy(c1.type,"Humidite");
}

if (gtk_toggle_button_get_active(checkbutton1))

{
strcpy(c1.etat,"En_marche");
}
else{
if (gtk_toggle_button_get_active(checkbutton2))

{
strcpy(c1.etat,"En_panne");
}}
ajouter(c1);
}



void on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}
void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supp_wael_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
    char id1[20];
capteur c1;
GtkWidget *input1;
GtkWidget *treeview1;
GtkWidget *fenetre_afficher;
input1=lookup_widget(objet,"entry1") ;

strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer1(id1);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{



}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonmodifwg_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

char id1[20];

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


capteur c2;

GtkWidget *input1, *input2,*input3;
GtkWidget *fenetre_ajout ,*fenetre_afficher;
GtkWidget *combobox1 ,*combobox2 ,*combobox3;
GtkWidget *spinbutton1wg ,*spinbutton2wg ,*spinbutton3wg ,*spinbutton4wg;
GtkWidget *radiobutton1 ,*radiobutton2;
GtkWidget *checkbutton1 ,*checkbutton2;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
GtkWidget *input4;
input4=lookup_widget(objet,"identrywg") ;

strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input4)));

combobox1=lookup_widget(objet, "combobox1") ;
combobox2=lookup_widget(objet, "combobox2") ;
combobox3=lookup_widget(objet, "combobox3") ;

spinbutton1wg=lookup_widget(objet, "spinbutton1wg") ;
spinbutton2wg=lookup_widget(objet, "spinbutton2wg") ;
spinbutton3wg=lookup_widget(objet, "spinbutton3wg") ;
spinbutton4wg=lookup_widget(objet, "spinbutton4wg") ;

input1=lookup_widget(objet, "entry3wg") ;
input2=lookup_widget(objet, "entry5wg") ;
input3=lookup_widget(objet, "entry2") ;

radiobutton1=lookup_widget(objet, "radiobutton1") ;
radiobutton2=lookup_widget(objet, "radiobutton2") ;

checkbutton1=lookup_widget(objet, "checkbutton1") ;
checkbutton2=lookup_widget(objet, "checkbutton2") ;


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

seuilmax1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton1wg));
seuilmax2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton2wg));
seuilmin1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton3wg));
seuilmin2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spinbutton4wg));

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton1)))
{

strcpy(type,"Temperature");
}
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton2)))
{

strcpy(type,"Humidite");
}

if (gtk_toggle_button_get_active(checkbutton1))

{
strcpy(etat,"En_marche");
}
else{
if (gtk_toggle_button_get_active(checkbutton2))

{
strcpy(etat,"En_panne");
}}
modifier(id1,marque,nom,id,type,etat,jour,mois,annee,seuilmax1,seuilmax2,seuilmin1,seuilmin2);

}
void
on_button2mowg_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_ajout ,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
//gtk_widget_destroy(fenetre_afficher);//
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);





}


void
on_buttonrechwg_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_recherche_wg ,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_recherche_wg=create_fenetre_recherche_wg();
gtk_widget_show(fenetre_recherche_wg);



}


void
on_buttonrecherchwg_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_recherche_wg;
GtkWidget *treeview2;
char id1[20];
GtkWidget *input8;
input8=lookup_widget(objet,"entryrechwg") ;
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input8)));
FILE *f,*g;
capteur c1;
capteur c2;
f=fopen("user.txt","r"); 
g=fopen("rr.txt","a+");


while(fscanf(f,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,&c1.seuilmax1,&c1.seuilmax2,&c1.seuilmin1,&c1.seuilmin2,c1.type,c1.etat)!=EOF)
{
if(strcmp(id1,c1.id)==0)
{
fprintf(g,"%s %s %s %s %s %s %f %f %f %f %s %s \n",c1.marque,c1.nom,c1.id,c1.jour,c1.mois,c1.annee,c1.seuilmax1,c1.seuilmax2,c1.seuilmin1,c1.seuilmin2,c1.type,c1.etat);
}
}


fclose(f);
fclose(g);



fenetre_recherche_wg=create_fenetre_recherche_wg();
gtk_widget_show(fenetre_recherche_wg);

treeview2=lookup_widget(fenetre_recherche_wg,"treeview2");
recherche_capwg(treeview2);
remove("rr.txt");

fenetre_recherche_wg=lookup_widget(objet,"fenetre_recherche_wg");
gtk_widget_destroy(fenetre_recherche_wg);


}


void
on_buttonretourrechwg_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *fenetre_recherche_wg ,*fenetre_afficher;
fenetre_recherche_wg=lookup_widget(objet,"fenetre_recherche_wg");
gtk_widget_destroy(fenetre_recherche_wg);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);


}


void
on_capteurtemps_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
// temperature
char texte [200]="";


int min1 ,min2,max1 ,max2 ;
int id ,n=0 ,i, j , a,mo,nt;
char ct[10];
int val;
GtkWidget *mn1, *mx1,*mn2, *mx2, *output ;

mn1=lookup_widget(button, "spinbuttonmin1wg");
mn2=lookup_widget(button, "spinbuttonmin2wg");
mx1=lookup_widget(button, "spinbuttonmax1wg");
mx2=lookup_widget(button, "spinbuttonmax2wg");

min1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn1));
min2= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn2));
max1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx1));
max2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx2));
FILE *f; 
f= fopen ("temperature.txt","r");

if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %d",&id,&j,&mo,&a,&val)!=EOF){
	if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
		i =0;
while ((i<n) && (ct[i]!=id ))
i++;
if (i==id) {ct[i]=id ; n++ ;}} }
}

sprintf (texte,"il y a : %d capteurs de temperature alarmentes ",n);
output=lookup_widget(button,("label45wg"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);

return (n);

}


void
on_capteurhumdwg_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char texte [200]="";


int min1 ,min2,max1 ,max2 ;
int id ,n=0 ,i, j , a,mo,nh;
char ch[10];
int val;
GtkWidget *mn1, *mx1,*mn2, *mx2, *output ;

mn1=lookup_widget(button, "spinbuttonhummin1wg");
mn2=lookup_widget(button, "spinbuttonhummin2wg");
mx1=lookup_widget(button, "spinbuttonhummax1wg");
mx2=lookup_widget(button, "spinbuttonhummax2wg");

min1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn1));
min2= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mn2));
max1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx1));
max2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mx2));
FILE *f; 
f= fopen ("humidite.txt","r");
if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %d",&id,&j,&mo ,&a, &val)!=EOF){
	if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
			 i=0;
while ((i <n) && (ch[i]!=id) )
i++;
if (i==n) {ch[i]=id ; n++ ;}} }
}
sprintf (texte,"il y a : %d capteurs de temperature alarmentes ",n);
output=lookup_widget(button,("label49wg"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (n);

}


void
on_button_capteurs_alarmats_wg_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_capteurwg ,*fenetre_afficher;
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_capteurwg=create_fenetre_capteurwg();
gtk_widget_show(fenetre_capteurwg);


}


void
on_button_retour_capteur_wg_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *fenetre_capteurwg ,*fenetre_afficher;
fenetre_capteurwg=lookup_widget(button,"fenetre_capteurwg");
gtk_widget_destroy(fenetre_capteurwg);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
affichage_cap(treeview1);


}

