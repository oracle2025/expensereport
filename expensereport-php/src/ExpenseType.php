<?php

namespace ExpenseReport;

class ExpenseType
{
    static function DINNER()
    {
        return new ExpenseType("Dinner", 5000, true);
    }

    static function BREAKFAST()
    {
        return new ExpenseType("Breakfast", 1000, true);
    }

    static function CAR_RENTAL()
    {
        return new ExpenseType("Car Rental", PHP_INT_MAX, false);
    }

    var $name;
    var $limit;
    var $isMeal;

    function __construct($name, $limit, $isMeal)
    {
        $this->name = $name;
        $this->limit = $limit;
        $this->isMeal = $isMeal;
    }

}