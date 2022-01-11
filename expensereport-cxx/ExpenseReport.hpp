#pragma once

#include <list>

using namespace std;

enum Type {
    BREAKFAST, DINNER, CAR_RENTAL
};

class Expense {
public:
    Type type;
    int amount;
};

struct ExpenseReport {
    void printReport(list<Expense> expenses, time_t now);

};

