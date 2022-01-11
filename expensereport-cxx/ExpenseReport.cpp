#include <chrono>
#include <sstream>
#include <iostream>
#include <iterator>

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
    int total = 0;
    for (auto & expense : expenses) {
        total += expense.amount;
    }
    return total;
}

int ExpenseReport::sumMeals(const list<Expense> &expenses) const {
    int mealExpenses = 0;
    for (auto & expense : expenses) {
        if (expense.type == BREAKFAST || expense.type == DINNER) {
            mealExpenses += expense.amount;
        }
    }
    return mealExpenses;
}

void ExpenseReport::header(time_t &now, ostringstream &result) const {
    result << "Expenses " << ctime(&now) << '\n';
}

string Expense::getName() const {
    string expenseName = "";
    switch (type) {
        case DINNER:
            expenseName = "Dinner";
            break;
        case BREAKFAST:
            expenseName = "Breakfast";
            break;
        case CAR_RENTAL:
            expenseName = "Car Rental";
            break;
    }
    return expenseName;
}

string Expense::getOverLimitMarker() const {
    string mealOverExpensesMarker = (type == DINNER && amount > 5000) ||
                                    (type == BREAKFAST && amount > 1000) ? "X" : " ";
    return mealOverExpensesMarker;
}