<?php

namespace ExpenseReport;

class Expense
{
    public $amount;
    public $type;

    function __construct($type, $amount)
    {
        $this->type = $type;
        $this->amount = $amount;
    }

    public function isMeal(): bool
    {
        return $this->type->isMeal;
    }

    public function getExpenseName(): string
    {
        return $this->type->name;
    }

    public function isOverLimit(): bool
    {
        return $this->amount > $this->type->limit;
    }
}