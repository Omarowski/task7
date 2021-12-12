#include <iostream>

using namespace std;

enum Banks {
    PKO, BGZ, BRE, BPH
};

struct Account {
    Banks bank;
    int balance;
};
struct Person {
    char name[20];
    Account account;
};
struct Couple {
    Person he;
    Person she;
};

int coupleTotalSaves(const Couple *couple) {
    return couple->he.account.balance + couple->she.account.balance;
}

const Couple *bestClient(const Couple *couples, int size, Banks bank) {
    const Couple *container = nullptr;
    for (unsigned int i = 0; i < size; ++i) {
        const Couple *actual = couples + i;
        if (actual->he.account.bank == bank or actual->she.account.bank == bank) {
            if (container == nullptr or coupleTotalSaves(actual) > coupleTotalSaves(container)) {
                container = actual;
            }
        }
    }
    return container;
}


int main() {
    using std::cout; using std::endl;
    Couple cpls[] = {
            {{"John",  {PKO, 1200}}, {"Marry", {BGZ, 1400}}},
            {{"Peter", {BGZ, 1400}}, {"Suzy",  {BRE, -1500}}},
            {{"Kevin", {PKO, 1600}}, {"Katy",  {BPH, 1500}}},
            {{"Kenny", {BPH, 200}},  {"Lucy",  {BRE, -201}}},
    };
    const Couple *p = bestClient(cpls, 4, BRE);
    if (p)
        cout << p->he.name << " and " << p->she.name
             << ": " << p->he.account.balance +
                        p->she.account.balance << endl;
    else
        cout << "No such couple...\n";

}