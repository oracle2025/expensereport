#pragma once

#include <list>

using namespace std;

enum Type {
    BREAKFAST, DINNER, CAR_RENTAL
};
struct ExpenseType{
    ExpenseType(const string &name, int limit, bool isMeal);
    ExpenseType() = default;
    string name;
    int limit;
    bool isMeal;
};
class Expense {
public:
    Expense(Type type, int amount);
    Type type;
    int amount;
    ExpenseType type2;

     string getName() const;

     string getOverLimitMarker() const;

     bool isMeal() const;
};

struct ExpenseReport {
    void printReport(list<Expense> expenses, time_t now);

    void header(time_t &now, ostringstream &result) const;

    int sumMeals(const list<Expense> &expenses) const;

    int sumTotal(const list<Expense> &expenses) const;

    void summary(const list<Expense> &expenses, ostringstream &result) const;

    void body(const list<Expense> &expenses, ostringstream &result) const;

    void detail(const Expense &expense, ostringstream &result) const;

};

