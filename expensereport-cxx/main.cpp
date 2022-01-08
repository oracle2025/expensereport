#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "ExpenseReport.hpp"

TEST_CASE ("ExpenseReport Characterization Test") {
    std::tm tm = {};
    std::stringstream ss("Jan 9 2014 12:35:34");
    ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));


    std::list<Expense> expenses = {
            {BREAKFAST,  1},
            {BREAKFAST,  1000},
            {BREAKFAST,  1001},
            {DINNER,     2},
            {DINNER,     5000},
            {DINNER,     5001},
            {CAR_RENTAL, 4}};
    /* {LUNCH, 8},
     {LUNCH, 2000},
     {LUNCH, 2001}};*/
    std::ostringstream out;
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to string stream!
    ExpenseReport report;
    report.printReport(expenses, chrono::system_clock::to_time_t(tp));
    std::cout.rdbuf(coutbuf); //reset to standard output again
    std::string actual = out.str();
    std::string expected = "Expenses Thu Jan  9 12:35:34 2014\n\nBreakfast\t1\t \nBreakfast\t1000\t \nBreakfast\t1001\tX\nDinner\t2\t \nDinner\t5000\t \nDinner\t5001\tX\nCar Rental\t4\t \nMeal expenses: 12005\nTotal expenses: 12009\n";
    CHECK(actual == expected);
}

TEST_CASE("How to redirect cout") {
    //Source: https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files
    std::ostringstream out;
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to string stream!
    std::cout << "Hello";
    std::cout.rdbuf(coutbuf); //reset to standard output again
    CHECK("Hello" == out.str());
}