#include <chrono>
#include <iostream>
#include <iterator>

#include "include/ExpenseReport.hpp"

void ExpenseReport::printReport(list<Expense> expenses, time_t now) {
    int total = 0;
    int mealExpenses = 0;

    cout << "Expenses " << ctime(&now) << '\n';

    for (auto & expense : expenses) {
        if (expense.type == BREAKFAST || expense.type == DINNER) {
            mealExpenses += expense.amount;
        }
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

        cout << expenseName << '\t' << expense.amount << '\t' << mealOverExpensesMarker << '\n';

        total += expense.amount;
    }

    cout << "Meal expenses: " << mealExpenses << '\n';
    cout << "Total expenses: " << total << '\n';
}
