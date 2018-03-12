#include "hachage.h"
#include "hachage.c"

int main()
{
    struct annuaire *an = creer();
    inserer(an, "Michel", "0660583737");
    afficher(an);

}
