#include "BinTree.hh"

int calc_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    if (a.empty()) {
        agd = BinTree<int>();
        return 0;
    }
    else {
        BinTree<int> left,right;
        int he = 0;
        int hd = 0;
        if (!a.left().empty()) {
            he = calc_desequilibri(a.left(),left) + 1;
        }
        else if (!a.right().empty()) {
            hd = calc_desequilibri(a.right(),right) + 1;
        }
        agd = BinTree<int>(he-hd,left,right);

        if (he > hd) return he;
        return hd;
    }
}

/* Pre: a=A */
/* Post: agd es un arbre amb la mateixa estructura que A on cada
   node conte el grau de desequilibri del subarbre d'A corresponent */
void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    calc_desequilibri(a,agd);
}