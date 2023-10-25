#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    bool b = false;
    BinTree<bool> hi,hd;
    if (t.left().empty() and t.right().empty()) {
        if (t.value() == "false") b =  false;
        else b = true;
    }
    else {
        if (t.value() == "and") {
            hi = treeOfEvaluations(t.left());
            hd = treeOfEvaluations(t.right());
            b = treeOfEvaluations(hi.value()) and treeOfEvaluations(hd.value());
        }
        else if (t.value() == "or") {
            hi = treeOfEvaluations(t.left());
            hd = treeOfEvaluations(t.right());
            b = treeOfEvaluations(hi.value()) or treeOfEvaluations(hd.value());
        }
        else {
            hi = treeOfEvaluations(t.left());
            b = not hi.value();
        }
    }
    return BinTree<bool>(b,hi,hd);
}