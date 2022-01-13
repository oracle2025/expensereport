#pragma once

#include <list>

using namespace std;

struct ExpenseType {
    ExpenseType(const string &name, int limit, bool isMeal);

    ExpenseType() = default;

    string name;
    int limit;
    bool isMeal;
};

const ExpenseType DINNER = ExpenseType("Dinner", 5000, true);
const ExpenseType BREAKFAST = ExpenseType("Breakfast", 1000, true);
const ExpenseType CAR_RENTAL = ExpenseType("Car Rental", numeric_limits<int>::max(), false);

class Expense {
public:
    Expense(ExpenseType type, int amount);

    int amount;
    ExpenseType type;

    string getName() const;

    string getOverLimitMarker() const;

    bool isMeal() const;

    bool isOverLimit() const;
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

