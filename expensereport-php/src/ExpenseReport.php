<?php

namespace ExpenseReport;

class ExpenseReport
{

    function print_report($expenses, $timestamp)
    {
        $this->header($timestamp);
        $this->body($expenses);
        $this->summary($expenses);
    }

    public function header($timestamp): void
    {
        $date = date("Y-m-d h:i:sa", $timestamp);
        print("Expense Report {$date}\n");
    }

    public function body($expenses)
    {
        foreach ($expenses as $expense) {
            $this->detail($expense);
        }
    }

    public function summary($expenses): void
    {
        print("Meal Expenses: " . $this->sumMeals($expenses) . "\n");
        print("Total Expenses: " . $this->sumTotal($expenses) . "\n");
    }

    public function detail($expense): void
    {
        print($expense->getExpenseName() . "\t" . $expense->amount . "\t" . $this->getOverExpensesMarker($expense) . "\n");
    }

    public function sumTotal($expenses)
    {
        $total = 0;
        foreach ($expenses as $expense) {
            $total += $expense->amount;
        }
        return $total;
    }

    public function sumMeals($expenses)
    {
        return $this->sumTotal(array_filter($expenses, function ($expense) {
            return $expense->isMeal();
        }));
    }

    public function getOverExpensesMarker($expense): string
    {
        $mealOverExpensesMarker = $expense->isOverLimit() ? "X" : " ";
        return $mealOverExpensesMarker;
    }

}
