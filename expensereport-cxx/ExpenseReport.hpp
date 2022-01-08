#pragma once
#include <list>

using namespace std;

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL
};

class Expense
{
public:
    Type type;
    int amount;
};
class ExpenseReport {
public:
    void printReport(list<Expense> expenses);
    void printReport(list<Expense> expenses, time_t now);

    string generateReport(list<Expense> &expenses, time_t &now) const;

    string header(time_t &now) const;
};

