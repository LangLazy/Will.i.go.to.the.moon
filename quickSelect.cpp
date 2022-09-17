#include <vector>
#include <experimental/random>
#include "quickSelect.h"


quickSelect::quickSelect(std::vector<Companies> companies) : companies{companies} { }

~quickSelect::quickSelect() { }

int quickSelect::random(int end) {
    return std::experimental::randint(0, end);
}

void quickSelect::shuffle() {
    int len = companies.size();
    for (int i = 0; i < len; i++) {
        Company temp = companies[i];
        int random =  random(len - 1) + i;
        companies[i] = companies[random];
        companies[random] = temp;
    }
}

void quickSelect::partition() {
    //TO DO implement partition
}

Company quickSelect::randomizedQuickSelect(int k) {
    int len = companies.size();
    int p = random(len - 1);
    int i = partition(companies, p);
    if (i == k) return companies[i];
    //TO DO implemment partition not quite sure
}

Company quickSelect::quickSelect(int k) {
    //always want k to be the last element, so it will be the largest.
    int len = companies.size();
    shuffle(companies);
    return randomizedQuickSelect(k);
}