#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>

#include "ExpenseReport.hpp"

void ExpenseReport::printReport(list<Expense> expenses, time_t now)
{
    ostringstream result;
    int total = 0;
    int mealExpenses = 0;

    result << "Expenses " << ctime(&now) << '\n';

    for (list<Expense>::iterator expense = expenses.begin(); expense != expenses.end(); ++expense) {
        if (expense->type == BREAKFAST || expense->type == DINNER) {
            mealExpenses += expense->amount;
        }

        string expenseName = "";
        switch (expense->type) {
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

        string mealOverExpensesMarker = (expense->type == DINNER && expense->amount > 5000) || (expense->type == BREAKFAST && expense->amount > 1000) ? "X" : " ";

        result << expenseName << '\t' << expense->amount << '\t' << mealOverExpensesMarker << '\n';

        total += expense->amount;
    }

    result << "Meal expenses: " << mealExpenses << '\n';
    result << "Total expenses: " << total << '\n';
    cout << result.str();
}

void ExpenseReport::printReport(list<Expense> expenses) {
    printReport(expenses, chrono::system_clock::to_time_t(chrono::system_clock::now()));
}
