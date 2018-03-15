#include <string.h>
#include "hachage.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define TAILLE 10
unsigned int hachage(const char *str){
    unsigned int hash = 5381;
    char c = str[0];
    int i = 0;
    while (c != 0){
        i ++;
        hash = hash * 33 + c;
        c = str[i];
    }
    return hash;
}
struct annuaire *creer()
{
    struct annuaire* annuaire = malloc(sizeof(struct annuaire));
    annuaire->taille = TAILLE;
    annuaire->listes = calloc(annuaire->taille, sizeof(struct liste));
    return annuaire;
}



void liberer(struct annuaire *an) {

    for (int i = 0; i < TAILLE ; ++i) {
        if (an->listes[i].tete != NULL) {
            struct cellule *cour = an->listes[i].tete;
            struct cellule *supp;
            while (cour != NULL) {
                supp = cour;
                cour = cour->suiv;
                free(supp);
            }
        }
    }
    free(an->listes);
    free(an);

}

struct cellule *creer_cellule(const char *nom, const char *numero){
    struct cellule *cel = malloc(sizeof(struct cellule));
    cel->nom = nom;
    cel->numero = numero;
    cel->suiv = NULL;
    return cel;
}
const char *insererListe(struct liste *liste, struct cellule *cell){
    if (liste->tete == NULL){
        liste->tete = cell;
        return NULL;
    }
    struct cellule *cour = liste->tete;
    const char *ret = NULL;
    while(cour != NULL){
        if(cour->nom == cell->nom){
            ret = cour->numero;
            cour->numero = cell->numero;

        }
        cour = cour->suiv;
    }
    cour = cell;
    return ret;
}

const char *inserer(struct annuaire *an, const char *nom, const char *numero)
{
    struct cellule *nouv = creer_cellule(nom,numero);
    unsigned int hash = hachage(nom) % an->taille;
    const char *ret;
    ret = insererListe(&(an->listes[hash]), nouv);
    return ret;
}



const char *rechercher_numero(struct annuaire *an, const char *nom)
{
    unsigned int hash = hachage(nom) % an->taille;
    if (an->listes[hash].tete == NULL){
        return NULL;
    }
    struct cellule *cour = an->listes[hash].tete;
    while(cour->nom != nom && cour != NULL){
        cour = cour->suiv;
    }
    if(cour == NULL){
        return NULL;
    }
    else{
        const char *numero = cour->numero;
        return numero;
    }
}


void supprimer(struct annuaire *an, const char *nom)
{
    unsigned int hash = hachage(nom) % an->taille;
    if (an->listes[hash].tete != NULL){
        struct cellule *cour = an->listes[hash].tete;
        if(cour->nom == nom){
            an->listes[hash].tete = cour->suiv;
            free(cour);
        }
        else{
            while(cour->suiv->nom != nom && cour->suiv != NULL){
                cour = cour->suiv;
            }
           if (cour->suiv != NULL){
               struct cellule *supp = cour->suiv;
               cour->suiv = supp->suiv;
               free(supp);
           }
        }
    }
}

void afficherCell(struct cellule *cell){
    printf("<%s, %s>; ", cell->nom, cell->numero);
}

void afficherListe(struct liste *liste){
    struct cellule* cour = liste->tete;
    while( cour != NULL){
        afficherCell(cour);
        cour = cour->suiv;
    }
    printf("\n");
}

void afficher(struct annuaire *an){
    for(int i=0; i< an->taille; i++){
        afficherListe(&(an->listes[i]));
    }
    printf("FIN\n");
}

