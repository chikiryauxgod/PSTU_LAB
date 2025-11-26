<?php

return [
    'create' => [
        'sql' => "CREATE TABLE IF NOT EXISTS test_table (
                    id INT AUTO_INCREMENT PRIMARY KEY,
                    name VARCHAR(50),
                    age INT)",
        'message' => "Table 'test_table' created."
    ],

    'alter' => [
        'sql' => "ALTER TABLE test_table ADD COLUMN city VARCHAR(50)",
        'message' => "Column 'city' added."
    ],

    'drop' => [
        'sql' => "DROP TABLE IF EXISTS test_table",
        'message' => "Table dropped."
    ],

    'insert' => [
        'sql' => "INSERT INTO test_table (name, age, city)
                  VALUES ('Lev', 21, 'Perm')",
        'message' => "Record inserted."
    ],

    'update' => [
        'sql' => "UPDATE test_table SET age = 30 WHERE name = 'Lev'",
        'message' => "Record updated."
    ],

    'delete' => [
        'sql' => "DELETE FROM test_table WHERE name = 'Lev'",
        'message' => "Record deleted."
    ],

    'select' => [
        'sql' => "SELECT * FROM test_table",
        'message' => null
    ],

    'trigger_table_create' => [
        'sql' => "CREATE TABLE log (
                    id INT AUTO_INCREMENT PRIMARY KEY,
                    action_type VARCHAR(20),
                    table_name VARCHAR(50),
                    record_id INT,
                    old_value TEXT,
                    new_value TEXT,
                    action_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP)",
        'message' => "Trigger table created."
    ],

    'trigger_table_drop' => [
        'sql' => "DROP TABLE log",
        'message' => "Trigger table dropped."
    ],

    'trigger' => [
        'sql' => "SELECT * FROM log ORDER BY action_time DESC",
        'message' => null
    ],

    'trigger_insert' => [
        'sql' => "
            CREATE TRIGGER test_table_after_insert
            AFTER INSERT ON test_table
            FOR EACH ROW
            BEGIN
                INSERT INTO log(action_type, table_name, record_id, old_value, new_value)
                VALUES (
                    'INSERT',
                    'test_table',
                    NEW.id,
                    NULL,
                    CONCAT('name=', NEW.name, ', age=', NEW.age, ', city=', NEW.city));
            END
        ",
        'message' => "Trigger INSERT created."
    ],

    'trigger_update' => [
        'sql' => "
            CREATE TRIGGER test_table_after_update
            AFTER UPDATE ON test_table
            FOR EACH ROW
            BEGIN
                INSERT INTO log(action_type, table_name, record_id, old_value, new_value)
                VALUES (
                    'UPDATE',
                    'test_table',
                    NEW.id,
                    CONCAT('name=', OLD.name, ', age=', OLD.age, ', city=', OLD.city),
                    CONCAT('name=', NEW.name, ', age=', NEW.age, ', city=', NEW.city));
            END
        ",
        'message' => "Trigger UPDATE created."
    ],

    'trigger_delete' => [
        'sql' => "
            CREATE TRIGGER test_table_after_delete
            AFTER DELETE ON test_table
            FOR EACH ROW
            BEGIN
                INSERT INTO log(action_type, table_name, record_id, old_value, new_value)
                VALUES (
                    'DELETE',
                    'test_table',
                    OLD.id,
                    CONCAT('name=', OLD.name, ', age=', OLD.age, ', city=', OLD.city),
                    NULL);
            END
        ",
        'message' => "Trigger DELETE created."
    ],


    'trigger_drop' => [
        'sql' => null,
        'message' => "Triggers were deleted."
    ],

];
