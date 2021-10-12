#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "./linearalgebra.h"


/* ----------------------- gramSchmidt ----------------------- */
/* Étant donné une matrice A de dimension m par n, cet algorithme
    calcule une décomposition QR de A, où Q est un unitaire
    matrice m par n et R est une matrice triangulaire supérieure n par n
    et A = QR.
    
    Variables d'entrée :
        a : pointeur vers un tableau de tableaux, le ième tableau de
                qui doit correspondre à la ième colonne du
                matrice A. Au cours de l'algorithme, les colonnes de Q
                remplacera les colonnes de A.
        r : pointeur vers un tableau de tableaux dans lequel le ième
                colonne de la matrice triangulaire supérieure R sera
                stocké dans le ième sous-tableau de r.
        m : nombre de colonnes dans A.
        n : nombre de rangs dans A.
        thin : TRUE => factorisation QR mince calculée
              FAUX => factorisation QR complète calculée

    Caractéristiques : Cette implémentation a une complexité temporelle O(m n^2)
    et nécessite O(1) mémoire supplémentaire.

    Remarques : En raison de la nature du problème, si A est presque 
    rank-deficient, les colonnes résultantes de Q peuvent ne pas
    présentent la propriété d'orthogonalité. */
    

void gramSchmidt (double ** a, double ** r, int m, int n, bool full) {
    int i, j;
    double anorm, tol = 10e-7;

    for(i = 0; i < n; i++) {
        r[i][i] = norm(a[i], m);                  // r_ii = ||a_i||

        if(r[i][i] > tol) {
            scalar_div(a[i], r[i][i], m, a[i]);   // a_i = a_i/r_ii
        }
        else if(i == 0) { // set a[0] = [1 0 0 ... 0]^T
            a[i][0] = 1;
            for(j = 1; j < m; j++) {
                a[i][j] = 0;
            }
        }
        else{ // il faut choisir a_i orthogonal à < a_1, ... a_{i-1} >
            for(j = 0; j < m; j++) {
                a[i][j] = -a[0][i] * a[0][j];
            }
            a[i][i] += 1;

            for(j = 1; j < i; j++) {
                scalar_sub(a[j], a[j][i], m, a[i]);
            }

            anorm = norm(a[i], m);
            scalar_div(a[i], anorm, m, a[i]);
        }

        for(j = i+1; j < n; j++) {
            r[j][i] = dot_product(a[i], a[j], m); // r_ij = a_i*a_j
            scalar_sub(a[i], r[j][i], m, a[j]);   // a_j -= r_ij a_i
        }
    }

    /* si factorisation QR complète demandée, on choisit restant
       colonnes de Q de sorte que les m colonnes de Q forment un
       ensemble orthonormé */
    if(full) {
        for(; i < m; i++) {
            for(j = 0; j < m; j++) {
                    a[i][j] = -a[0][i] * a[0][j];
                }
                a[i][i] += 1;
    
                for(j = 1; j < i; j++) {
                    scalar_sub(a[j], a[j][i], m, a[i]);
                }
    
                anorm = norm(a[i], m);
                scalar_div(a[i], anorm, m, a[i]);
        }
    }
}


int main () {
    int i, j, n, m, q_n, r_m;
    bool full;
    double x;

    /* permet à l'utilisateur de définir la dimension de la matrice A */
    std::cout << "Entrez la dimension m (où A est une matrice m par n): ";
    std::cin >> m;
    std::cout << "Entrez la dimension n (où A est une matrice m par n): ";
    std::cin >> n;

    if(m != n) {
       /* vérifie si m < n */
        if(m < n) {
            printf(" Pour une factorisation réussie, cette mise en œuvre "
                   "nécessite n <= m.\nFin du programme.\n");
            return 0;
        }
        /* permet à l'utilisateur de choisir une factorisation QR complète ou fine */
        std::cout << "Entrez soit 0 pour calculer une factorisation QR fine"
                  << std::endl;
        std::cout << " ou 1 pour calculer une factorisation QR complète : ";
        std::cin >> full;
    }
    else { // sinon m == n donc la factorisation QR complète et fine sont identiques */
        full = 1;
    }

  /* définir les dimensions des matrices Q et R sur la base d'un QR plein ou fin */
    if(full) { // Q est m par m et R est m par n
        q_n = m;
        r_m = m;
    }
    else { // Q est m par n et R est n par n
        q_n = n;
        r_m = n;
    }

   /* alloue de la mémoire pour les matrices A et R */
    double ** a = new double*[q_n];
    double ** r = new double*[n];
    for(i = 0; i < n; i++) {
        a[i] = new double[m];
        r[i] = new double[r_m];
    }
    for(; i < q_n; i++) {
        a[i] = new double[m];
    }

    
/* initialise les valeurs dans la matrice A (seulement n colonnes indépendamment de
       QR fin ou QR complet) */
    for(i = 0; i < n; i++) {
        for(j = i; j < m; j++) {
            a[i][j] = j - i + 1; // ce choix de valeurs était arbitraire
        }
    }

    
/* imprime la matrice A avant d'appeler gramSchmidt */
    std::cout << "A = " << std::endl;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%9.6lg ", a[j][i]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

   /* exécuter gramSchmidt pour calculer la factorisation QR */
    gramSchmidt(a, r, m, n, full);

    /* imprime la matrice Q issue de gramSchmidt */
    std::cout << "Q = " << std::endl;
    for(i = 0; i < m; i++) {
        for(j = 0; j < q_n; j++) {
            if(a[j][i] >= 0) {
                std::cout << " ";
            }
            printf("%9.6lg ", a[j][i]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /* imprime la matrice R issue de gramSchmidt */
    std::cout << "R = " << std::endl;
    for(i = 0; i < r_m; i++) {
        for(j = 0; j < n; j++) {
            printf("%9.6lg ", r[j][i]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

   /* affiche la preuve numérique que les colonnes de Q sont orthonormées */
    printf("Vérification numérique que {q_1, ..., q_%i} est un "
           "ensemble orthonormé:\n", q_n);
    for(i = 0; i < q_n; i++) {
        for(j = i; j < q_n; j++) {
            x = dot_product(a[i], a[j], m);
            printf("q_%i * q_%i = %lg\n", i + 1, j + 1, x);
        }
    }
    
    /* mémoire libre */
    for(i = 0; i < n; i++) {
        delete[] a[i];
        delete[] r[i];
    }
    for(; i < q_n; i++) {
        delete[] a[i];
    }
    delete[] a;  
    delete[] r;

    return 0;       // exit main
}
