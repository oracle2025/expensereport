#include <chrono>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "ExpenseReport.hpp"

void ExpenseReport::printReport(list<Expense> expenses, time_t now) {
    ostringstream result;
    header(now, result);
    body(expenses, result);
    summary(expenses, result);
    cout << result.str();
}

void ExpenseReport::body(const list<Expense> &expenses, ostringstream &result) const {
    for (auto &expense : expenses) {
        detail(expense, result);
    }
}

void ExpenseReport::detail(const Expense &expense, ostringstream &result) const {
    result << expense.getName() << '\t' << expense.amount << '\t' << expense.getOverLimitMarker() << '\n';
}

void ExpenseReport::summary(const list<Expense> &expenses, ostringstream &result) const {
    result << "Meal expenses: " << sumMeals(expenses) << '\n';
    result << "Total expenses: " << sumTotal(expenses) << '\n';
}

int ExpenseReport::sumTotal(const list<Expense> &expenses) const {
    return accumulate(begin(expenses), end(expenses), 0, [](int total, const Expense &expense) {
        return total + expense.amount;
    });
}

int ExpenseReport::sumMeals(const list<Expense> &expenses) const {
    return accumulate(begin(expenses), end(expenses), 0, [](int total, const Expense &expense) {
        if (expense.isMeal()) { return total + expense.amount; }
        return total;
    });
}

void ExpenseReport::header(time_t &now, ostringstream &result) const {
    result << "Expenses " << ctime(&now) << '\n';
}

string Expense::getName() const {
    return type.name;
}

string Expense::getOverLimitMarker() const {
    return isOverLimit() ? "X" : " ";
}

bool Expense::isOverLimit() const { return amount > type.limit; }

bool Expense::isMeal() const {
    return type.isMeal;
}

Expense::Expense(ExpenseType type, int amount) : type(type), amount(amount) {
}

ExpenseType::ExpenseType(const string &name, int limit, bool isMeal) :
        name(name), limit(limit), isMeal(isMeal) {
}
