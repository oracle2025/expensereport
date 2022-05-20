<?php


use PHPUnit\Framework\TestCase;
use ExpenseReport\ExpenseReport;
use ExpenseReport\Expense;
use ExpenseReport\ExpenseType;

class ExpenseReportTest extends TestCase
{
    public function test_characterization()
    {
        $timestamp = strtotime('2015-05-12 20:00:00');
        $expenses = array(
            new Expense(ExpenseType::BREAKFAST, 1),
            new Expense(ExpenseType::BREAKFAST, 1000),
            new Expense(ExpenseType::BREAKFAST, 1001),
            new Expense(ExpenseType::DINNER, 2),
            new Expense(ExpenseType::DINNER, 5000),
            new Expense(ExpenseType::DINNER, 5001),
            new Expense(ExpenseType::CAR_RENTAL, 4),
        );
        $expenseReport = new ExpenseReport();
        ob_start();
        $expenseReport->print_report($expenses, $timestamp);
        $actual = ob_get_contents();
        ob_end_clean();
        echo $actual;
        $expected = <<<OUTPUT
Expense Report 2015-05-12 08:00:00pm
Breakfast	1	 
Breakfast	1000	 
Breakfast	1001	X
Dinner	2	 
Dinner	5000	 
Dinner	5001	X
Car Rental	4	 
Meal Expenses: 12005
Total Expenses: 12009

OUTPUT;
        $this->assertEquals($expected, $actual);
    }
}
