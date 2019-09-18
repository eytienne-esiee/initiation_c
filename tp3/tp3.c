#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tailleNoms 10
#define tailleAnnuaire 20

typedef struct t_Date
{
    int jour, mois, annee;
} Date;

typedef struct t_Identite
{
    char nom[tailleNoms], prenom[tailleNoms];
} Identite;

typedef struct t_Eleve
{
    Identite id;
    Date naiss;
} Eleve;

typedef struct t_Annuaire
{
    Eleve *eleves[tailleAnnuaire];
    int cpt;
} Annuaire;

int cmpDates(Date d1, Date d2);
int cmpIdentites(Identite id1, Identite id2);
void prompt(char *request, char *format, void *buffer);
Eleve *saisie_Eleve(Eleve *pE1);
void afficher_Eleve(Eleve *pE1);
int search_Eleve(Eleve pE1);

Annuaire globalA;

int main()
{
    globalA.cpt = 0;
    Eleve *myStudent;
    saisie_Eleve(myStudent);
    afficher_Eleve(globalA.eleves[0]);
    search_Eleve(*myStudent);
}

int search_Eleve(Eleve pE1)
{
    int i;
    for (i = 0; i < globalA.cpt && i < tailleAnnuaire; ++i)
    {
        if (cmpIdentites(pE1.id, globalA.eleves[i]->id) && cmpDates(pE1.naiss, globalA.eleves[i]->naiss))
            return i;
    }
    return -1;
}

void afficher_Eleve(Eleve *e1)
{
    printf("%s %s, né le %d/%d/%d.\n",
           e1->id.prenom, e1->id.nom, e1->naiss.jour, e1->naiss.mois, e1->naiss.annee);
}

Eleve *saisie_Eleve(Eleve *pE1)
{
    Eleve ee;
    prompt("Nom ?", "%.20s", ee.id.nom);
    // prompt("Prénom ?", "%.20s", ee.id.prenom);
    printf("test : '%c'\n", ee.id.nom[0]);
    char dateNaissance[10];
    while (1)
    {
        char *jour, *mois, *annee;
        prompt("Date de naissance ? (jj/mm/aaaa)", "%.10s", &dateNaissance);
        strncpy(jour, dateNaissance, 2);
        strncpy(jour, dateNaissance + 3 * sizeof(char), 2);
        strncpy(jour, dateNaissance + 3 * sizeof(char), 4);
        int date[3] = {
            atoi(annee),
            atoi(mois),
            atoi(jour)};
        if (date[0] > 0 && date[1] > 0 && date[2] > 0)
            continue;
        ee.naiss.annee = date[0];
        ee.naiss.mois = date[1];
        ee.naiss.jour = date[2];
        break;
    }
    if (globalA.cpt > tailleAnnuaire - 1)
        globalA.eleves[globalA.cpt++] = (Eleve *)malloc(sizeof(Eleve));
    else
        exit - 1;
    return pE1;
}

void prompt(char *request, char *format, void *buffer)
{
    printf("%s ", request);
    int c;
    printf("lecture : %d", scanf(format, buffer));
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
}

int cmpIdentites(Identite id1, Identite id2)
{
    return strcmp(id1.nom, id2.nom) == 0 && strcmp(id1.prenom, id2.prenom) == 0 ? 1 : 0;
}

int cmpDates(Date d1, Date d2)
{
    return d1.annee == d2.annee && d1.mois == d2.mois && d1.jour == d2.jour ? 1 : 0;
}