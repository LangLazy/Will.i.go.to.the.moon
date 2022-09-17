#ifndef SIMULATION
#define SIMULATION

#include <vector>
#include "company.h"

class quickSelect {
    std::vector<Company> companies;
    quickSelect(std::vector<Companies> companies);
    Company quickSelect(int k);

    private:
    int random(int end);
    void shuffle();
    void partition();
    Company randomizedQuickselect();
}

#endif