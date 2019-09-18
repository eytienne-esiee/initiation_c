#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tailleNoms 20
#define tailleChampsAdresse 15
#define tailleTelephone 10
#define tailleAnnuaire 10

typedef struct t_Date
{
	int jour, mois, annee;
} Date;

typedef struct t_Identite
{
	char nom[tailleNoms], prenom[tailleNoms];
} Identite;

typedef struct t_Adresse
{
	int num;
	char rue[tailleChampsAdresse];
	int codePostal;
	char ville[tailleChampsAdresse];
	char pays[tailleChampsAdresse];
} Adresse;

typedef struct t_Contact
{
	char telephone[tailleTelephone], email[tailleChampsAdresse];
} Contact;

typedef struct t_Eleve
{
	Identite id;
	Date naiss;
	Adresse adr;
	Contact contact;
} Eleve;

typedef struct t_Annuaire
{
	Eleve eleves[tailleAnnuaire];
	int cmp;
} Annuaire;

int cmpDates(Date d1, Date d2);
int cmpIdentites(Identite id1, Identite id2);
int cmpAdresses(Adresse ad1, Adresse ad2);
void saisieEleve(Eleve e1);
void prompt(char *request, char *format, void *buffer);
void afficherEleve(Eleve e1);
int searchEleve(Eleve e1);

int main()
{
}

int searchEleve(Eleve e, Annuaire a)
{
	int i;
	for (i = 0; i < a.cmp && i < tailleAnnuaire; i++)
	{
		if (cmpEleves(e, a.eleves[i]))
			return 1;
	}
	return 0;
}

int cmpEleves(Eleve a, Eleve b)
{
	return cmpIdentites(a.id, b.id) && cmpDates(a.naiss, b.naiss) && cmpAdresses(a.adr, b.adr) && strcmp(a.contact.email, b.contact.email) == 0 && strcmp(a.contact.telephone, b.contact.telephone) == 0 ? 1 : 0;
}

void afficherEleve(Eleve e1)
{
	printf("%s %s, né le %d/%d/%d, domicilié au %d %s, %i %s, %s.\n",
		   e1.id.prenom, e1.id.nom, e1.naiss.jour, e1.naiss.mois, e1.naiss.annee,
		   e1.adr.num, e1.adr.rue, e1.adr.codePostal, e1.adr.ville, e1.adr.pays);
	printf("Adresse email puis téléphone : %s et %s\n ", e1.contact.email, e1.contact.telephone);
}

void saisieEleve(Eleve e1)
{
	prompt("Nom ?", "%.20s", &e1.id.nom);
	prompt("Prénom ?", "%.20s", &e1.id.prenom);
	char dateNaissance[10];
	while (1)
	{
		char *jour, *mois, *annee;
		prompt("Date de naissance ? (jj/mm/aaaa)", "%.10s", &dateNaissance);
		strncpy(jour, &dateNaissance[0], 2);
		strncpy(jour, &dateNaissance[3], 2);
		strncpy(jour, &dateNaissance[6], 4);
		int date[3] = {
			atoi(annee),
			atoi(mois),
			atoi(jour)};
		if (date[0] > 0 && date[1] > 0 && date[2] > 0)
			continue;
		e1.naiss.annee = date[0];
		e1.naiss.mois = date[1];
		e1.naiss.jour = date[2];
		break;
	}
	prompt("Email ?", "%.15s", &e1.contact.email);
	prompt("Telephone ?", "%10.10s", &e1.contact.telephone);
	prompt("Pays ?", "%.15s", &e1.adr.pays);
	prompt("Code postal ?", "%d", &e1.adr.codePostal);
	prompt("Ville ?", "%.15s", &e1.adr.ville);
	prompt("Rue ?", "%.15s", &e1.adr.rue);
	prompt("Numéro de rue ?", "%d", &e1.adr.num);
}

void prompt(char *request, char *format, void *buffer)
{
	printf("%s ", request);
	scanf(format, buffer);
	int c;
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

int cmpAdresses(Adresse ad1, Adresse ad2)
{
	return strcmp(ad1.pays, ad2.pays) == 0 && ad1.codePostal == ad2.codePostal && strcmp(ad1.ville, ad2.ville) == 0 && strcmp(ad1.rue, ad2.rue) == 0 && ad1.num == ad2.num ? 1 : 0;
}