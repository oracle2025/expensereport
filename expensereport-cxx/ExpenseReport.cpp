#include <chrono>
#include <sstream>
#include <iostream>
#include <iterator>

#include "ExpenseReport.hpp"

void ExpenseReport::printReport(list<Expense> expenses, time_t now) {
    ostringstream result;

    result << "Expenses " << ctime(&now) << '\n';

    int mealExpenses = 0;
    for (auto & expense : expenses) {
        if (expense.type == BREAKFAST || expense.type == DINNER) {
            mealExpenses += expense.amount;
        }
    }
    for (auto & expense : expenses) {

        string expenseName = "";
        switch (expense.type) {
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

        string mealOverExpensesMarker = (expense.type == DINNER && expense.amount > 5000) ||
                                        (expense.type == BREAKFAST && expense.amount > 1000) ? "X" : " ";

        result << expenseName << '\t' << expense.amount << '\t' << mealOverExpensesMarker << '\n';
    }
    int total = 0;
    for (auto & expense : expenses) {
        total += expense.amount;
    }

    result << "Meal expenses: " << mealExpenses << '\n';
    result << "Total expenses: " << total << '\n';
    cout << result.str();
}
