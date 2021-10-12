/* ----------------------- norme ----------------------- * /
/* Étant donné un tableau et sa longueur, cette fonction
    calcule la norme 2 du tableau.
    
    Variables d'entrée :
        x : pointeur vers le tableau pour lequel la norme 2 doit
                 être calculé.
        longueur : nombre d'entrées dans x.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

double norm (double * x, int length) {
    int i, length5;
    double a, sum = 0;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        sum += x[i] * x[i];
    }
    for(; i < length; i += 5) {
        sum += x[i] * x[i] + x[i + 1] * x[i + 1] + x[i + 2] * x[i + 2]
                           + x[i + 3] * x[i + 3] + x[i + 4] * x[i + 4];
    }

    return sqrt(sum);
}


/* ----------------------- vec_copy ----------------------- * /
/* Étant donné deux tableaux de même longueur et leur longueur,
    cette fonction stocke les valeurs du premier tableau
    dans le deuxième tableau.
    
    Variables d'entrée :
        x : pointeur vers le tableau dont les entrées doivent être
                 copié.
        y : pointeur vers le tableau dans lequel les composants
                 de x doivent être stockés.
        longueur : nombre d'entrées en x et en y.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

void vec_copy (double * x, double * y, int length) {
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i] = x[i];
    }
    for(; i < length; i += 5) {
        y[i] = x[i];
        y[i + 1] = x[i + 1];
        y[i + 2] = x[i + 2];
        y[i + 3] = x[i + 3];
        y[i + 4] = x[i + 4];
    }
}


/* ------------------- partialvec_copy ------------------- */
/* Étant donné deux tableaux, la longueur du deuxième tableau, et
    un index cette fonction stocke les valeurs du
    sous-tableau x[index : index + longueur] dans le tableau
    y[0 : longueur].
    
    Variables d'entrée :
        x : pointeur vers le tableau dont les entrées doivent être
                 copié.
        y : pointeur vers le tableau dans lequel les composants
                 de x doivent être stockés.
        longueur : nombre d'entrées dans y.
        index : index de départ du sous-tableau de x à être
                copié sur y.

    Exemple : supposons que x soit un pointeur vers le tableau
    {1, 2, 3, 4, 5}, y est un pointeur vers le tableau {0, 0, 0},
    longueur = 3 et index = 2. Puis après exécution
    partialvec_copy(x, y, 3, 2), le tableau pointé par
    y est maintenant {3, 4, 5}.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

void partialvec_copy (double * x, double * y, int length, int index) {
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i] = x[i + index];
    }
    for(; i < length; i += 5) {
        y[i] = x[i + index];
        y[i + 1] = x[i + index + 1];
        y[i + 2] = x[i + index + 2];
        y[i + 3] = x[i + index + 3];
        y[i + 4] = x[i + index + 4];
    }
}


/* ----------------------- scalar_div ----------------------- * /
/* Étant donné deux tableaux de même longueur, leur longueur et un
    valeur scalaire cette fonction divise les valeurs de la
    premier tableau par la valeur scalaire et stocke le calcul
    nombre dans le deuxième tableau.
    
    Variables d'entrée :
        x : pointeur vers le tableau dont les composants doivent être
                 divisé par r et stocké dans le deuxième tableau, y.
        r : scalaire utilisé en division.
        longueur : nombre d'entrées en x et en y.
        y : pointeur vers le tableau dans lequel les composants
                 de x doivent être stockés.


    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

void scalar_div (double * x, double r, int length, double * y) {
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i] = x[i]/r;
    }
    for(; i < length; i += 5) {
        y[i] = x[i]/r;
        y[i + 1] = x[i + 1]/r;
        y[i + 2] = x[i + 2]/r;
        y[i + 3] = x[i + 3]/r;
        y[i + 4] = x[i + 4]/r;
    }
}


/* ----------------------- scalar_sub ----------------------- * /
/* Étant donné deux tableaux de même longueur, leur longueur et un
    valeur scalaire cette fonction multiplie les valeurs de la
    premier tableau par la valeur scalaire, puis soustrait le
    composants calculés à partir des composants du deuxième tableau.
    
    Variables d'entrée :
        x : pointeur vers le tableau dont les composants doivent être
                 multiplié par r puis soustrait du
                 composants du deuxième tableau, y.
        r : scalaire utilisé dans la multiplication.
        longueur : nombre d'entrées en x et en y.
        y : pointeur vers le tableau dans lequel les composants
                 de x doivent être stockés.


    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

void scalar_sub (double * x, double r, int length, double * y) {
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i] -= r * x[i];
    }
    for(; i < length; i += 5) {
        y[i] -= r * x[i];
        y[i + 1] -= r * x[i + 1];
        y[i + 2] -= r * x[i + 2];
        y[i + 3] -= r * x[i + 3];
        y[i + 4] -= r * x[i + 4];
    }
}


/* --------------------- partialscalar_sub --------------------- */
/* Étant donné deux tableaux, la longueur du deuxième tableau, un scalaire
    valeur, et un indice, cette fonction multiplie les valeurs
    à partir de l'indice donné du premier tableau par le
    valeur scalaire, puis soustrait les composants calculés de
    les composants le deuxième tableau.
    
    Variables d'entrée :
        x : pointeur vers le tableau dont les composants doivent être
                 multiplié par r puis soustrait du
                 composants du deuxième tableau, y.
        r : scalaire utilisé dans la multiplication.
        longueur : nombre d'entrées dans y.
        indice :
        y : pointeur vers le tableau dans lequel les composants
                 de x doivent être stockés.

    Exemple : supposons que x soit un pointeur vers le tableau
    {1, 2, 3, 4, 5}, y est un pointeur vers le tableau {0, 0, 0},
    longueur = 3, r = -1 et index = 2. Puis après l'exécution
    partialscalar_sub(x, -1, 3, 2, y), le tableau pointé sur
    par y est maintenant {-3, -4, -5}.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

void partialscalar_sub (double * x, double r, int length, 
                                              int index, double * y) 
{
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i + index] -= r * x[i];
    }
    for(; i < length; i += 5) {
        y[i + index] -= r * x[i];
        y[i + index + 1] -= r * x[i + 1];
        y[i + index + 2] -= r * x[i + 2];
        y[i + index + 3] -= r * x[i + 3];
        y[i + index + 4] -= r * x[i + 4];
    }
}


/* --------------------- produit scalaire --------------------- */
/* Étant donné deux tableaux de même longueur et leur longueur,
    cette fonction renvoie le produit scalaire des deux
    tableaux.
    
    Variables d'entrée :
        x : pointeur vers le premier tableau.
        y : pointeur vers le deuxième tableau.
        longueur : nombre d'entrées en x et en y.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

double dot_product (double * x, double * y, int length) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        sum += x[i] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i] * y[i] + x[i + 1] * y[i + 1] + x[i + 2] * y[i + 2]
                           + x[i + 3] * y[i + 3] + x[i + 4] * y[i + 4];
    }

    return sum;
}


/* ------------------ partialdot_product ------------------ */
/* Étant donné deux tableaux de même longueur, leur longueur et
    un indice cette fonction renvoie le produit scalaire du
    deux sous-tableaux x[index : longueur] et y[index : longueur].
    
    Variables d'entrée :
        x : pointeur vers le premier tableau.
        y : pointeur vers le deuxième tableau.
        longueur : nombre d'entrées en x et en y.
        index : index de départ pour les sous-tableaux.

    Exemple : supposons que x soit un pointeur vers le tableau
    {1, 2, 3, 4}, y est un pointeur vers le tableau {5, 6, 7, 8},
    longueur = 4 et index = 2. Ensuite, la valeur renvoyée par
    l'exécution de partialdot_product(x, y, 4, 2) est 53, ce qui
    est calculé par
        x[2] * y[2] + x[3] * y[3] = 3 * 7 + 4 * 8
                                  = 21 + 32
                                  = 53.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

double partialdot_product (double * x, double * y, int length, int index) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = index; i < length5; i++) {
        sum += x[i] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i] * y[i] + x[i + 1] * y[i + 1] + x[i + 2] * y[i + 2]
                           + x[i + 3] * y[i + 3] + x[i + 4] * y[i + 4];
    }

    return sum;
}


/* -------------------- subdot_product -------------------- */
/* Étant donné deux tableaux, la longueur du deuxième tableau, et
    un indice cette fonction renvoie le produit scalaire du
    deux sous-tableaux x[index : index + longueur] et
    y[0 : longueur]. Il faut que indice + longueur soit
    au plus la longueur du premier tableau.
    
    Variables d'entrée :
        x : pointeur vers le premier tableau.
        y : pointeur vers le deuxième tableau.
        longueur : nombre d'entrées dans y.
        index : index de départ pour le sous-tableau de x.

    Exemple : supposons que x soit un pointeur vers le tableau
    {1, 2, 3, 4, 5}, y est un pointeur vers le tableau
    {-1, -2, -3}, longueur = 3 et index = 2. Ensuite, la valeur
    renvoyé en exécutant subdot_product(x, y, 3, 2) est 53,
    qui est calculé par
            x[2] * y[0] + x[3] * y[1] + x[4] * y[2]

          = 3 * -1 + 4 * -2 + 5 * -3

          = - 3 - 8 - 15

          = -26.

    Caractéristiques : Cette implémentation a une complexité temporelle
    O(longueur) et nécessite O(1) de mémoire supplémentaire. */

double subdot_product (double * x, double * y, int length, int index) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        sum += x[i + index] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i + index] * y[i] + x[i + index + 1] * y[i + 1] 
                                   + x[i + index + 2] * y[i + 2]
                                   + x[i + index + 3] * y[i + 3]
                                   + x[i + index + 4] * y[i + 4];
    }

    return sum;
}
