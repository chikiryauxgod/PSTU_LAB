<?php

return [
    "procedure_add_employee" => [
        "message" => "Create procedure: add employee",
        "sql" => "
            CREATE PROCEDURE add_employee(
                IN p_full_name VARCHAR(100),
                IN p_phone VARCHAR(30),
                IN p_salary DECIMAL(10,2),
                IN p_address VARCHAR(255),
                IN p_hire_date DATE
            )
            BEGIN
                INSERT INTO employees(full_name, phone, salary, address, hire_date)
                VALUES (p_full_name, p_phone, p_salary, p_address, p_hire_date);
            END
            "
    ],

    "procedure_delete_by_id" => [
        "message" => "Create procedure: delete employee by id",
        "sql" => "
            CREATE PROCEDURE delete_by_id(IN p_id INT)
            BEGIN
                DELETE FROM employees WHERE id = p_id;
            END
            "
    ],

    "procedure_summary_salary" => [
        "message" => "Create procedure: sum of all salaries",
        "sql" => "
            CREATE PROCEDURE summary_salary()
            BEGIN
                SELECT SUM(salary) AS total_salary FROM employees;
            END
            "
    ],

    "call_summary_salary" => [
        "message" => "Total salary of all employees",
        "sql" => "CALL summary_salary()"
    ],

    "call_all_employees" => [
        "message" => "All employees",
        "sql" => "SELECT * FROM employees"
    ],

    "call_add_employee" => [
        "message" => "Add employee (procedure call)",
        "sql" => "CALL add_employee('{full_name}', '{phone}', {salary}, '{address}', '{hire_date}')"
    ],

    "call_delete_by_id" => [
        "message" => "Delete employee by id (procedure call)",
        "sql" => "CALL delete_by_id({id})"
    ],

];
