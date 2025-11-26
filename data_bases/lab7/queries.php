<?php

return [
    'view_phones_create' => [
        'sql' => "
            CREATE OR REPLACE VIEW view_employees_phones AS
            SELECT full_name, phone, salary
            FROM employees;
        ",
        'message' => "View 'view_employees_phones' created successfully."
    ],

    'view_addresses_create' => [
        'sql' => "
            CREATE OR REPLACE VIEW view_employees_addresses AS
            SELECT full_name, address
            FROM employees;
        ",
        'message' => "View 'view_employees_addresses' created successfully."
    ],

    'view_experience_create' => [
        'sql' => "
            CREATE OR REPLACE VIEW view_employees_experience AS
            SELECT full_name,
                   hire_date,
                   TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) AS years_worked
            FROM employees
            WHERE TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) > 4;
        ",
        'message' => "View 'view_employees_experience' created successfully."
    ],

    'phones' => [
        'sql' => "SELECT * FROM view_employees_phones",
        'message' => "Employees, phones, salary"
    ],

    'addresses' => [
        'sql' => "SELECT * FROM view_employees_addresses",
        'message' => "Employees and addresses (sorted)"
    ],

    'experience' => [
        'sql' => "SELECT * FROM view_employees_experience",
        'message' => "Employees with experience > 4 years"
    ],

];
