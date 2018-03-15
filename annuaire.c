#include "hachage.h"


int main()
{
    struct annuaire *an = creer();
    const char *res1 = inserer(an, "Brighton Muffat", "0660583737");
    printf("%s", res1);
    const char *res2 = inserer(an, "Anais Hilbert", "0645120484");
    printf("%s", res2);
    inserer(an, "Anais HA", "06454841480");
    supprimer(an, "Michel");
    const char *num = rechercher_numero(an, "Anais Hilbert");
    printf("%s", num);
    afficher(an);

}
