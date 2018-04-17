#include <iostream>
using namespace std;

struct Instr {
    int l;
    int r;
    char c;
};

int main() {
    int numInstr;
    cin >> numInstr;
    Instr* instrs = new Instr[numInstr];
    for (int i = 0; i < numInstr; i++) {
        cin >> instrs[i].l;
        cin >> instrs[i].r;
        cin.ignore(1, ' ');
        cin >> instrs[i].c;
    }
    int  i0, i1, i2, i3;
    char c0, c1, c2, c3;
    cin >> i0; c0 = 'a';
    cin >> i1; c1 = 'a';
    cin >> i2; c2 = 'a';
    cin >> i3; c3 = 'a';
    for (int i = 0; i < numInstr; i++) {
        if (instrs[i].l <= i0 && instrs[i].r >= i0)
            c0 = instrs[i].c;
    }
    for (int i = 0; i < numInstr; i++) {
        if (instrs[i].l <= i1 && instrs[i].r >= i1)
            c1 = instrs[i].c;
    }
    for (int i = 0; i < numInstr; i++) {
        if (instrs[i].l <= i2 && instrs[i].r >= i2)
            c2 = instrs[i].c;
    }
    for (int i = 0; i < numInstr; i++) {
        if (instrs[i].l <= i3 && instrs[i].r >= i3)
            c3 = instrs[i].c;
    }
    cout << c0 << " " << c1 << " " << c2 << " " << c3 << " " << endl;
    delete [] instrs;
}
