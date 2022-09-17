#include <vectors>
#include <iostream>
#include "simulation.h"
#include "quickSelect.h"

struct Company;

void simulation(std::vector<std::vector<Company>> stocks, 
    std::vector<int> normalized) {
        const int DAYS = 260;
        const DAILY_DEPOSIT = 1000;
        int cash = 0;
        for (int i = 0; i < DAYS; i++) {
            cash += DAILY_DEPOSIT;
            std::vector<Company> day = stocks[i];
            quickSelect qs = quickSelect{companies};

            // This is the company chosen
            int companyIdx = qs.quickSelect(normalized[i]);
            Company company = day[companyIdx];
            if (cash > Company.startingPrice) {
                // This implementation buys only one stock
                int buys = cash/Company.startingPrice;
                cash -= (buys * Company.startingPrice);
                std::string companyName = Company.code;
                //make api call to CockroachDB
            }
            // else is saving
        }

        std::cout << "remaining cash is: " << cash << std::endl;
}

