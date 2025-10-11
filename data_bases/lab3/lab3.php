<?php

$host = "localhost";
$user = "boss";             
$pass = "boss_password";    
$db   = "DB_EMPLOYEES";          

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("Connection error: " . $conn->connect_error);
}

echo "<h2>Employees, phones and salary</h2>";
$res1 = $conn->query("SELECT full_name, phone, salary FROM employees");
echo "<table border='1' cellpadding='5'><tr><th>Имя</th><th>Телефон</th><th>Зарплата</th></tr>";
while ($row = $res1->fetch_assoc()) {
    echo "<tr><td>{$row['full_name']}</td><td>{$row['phone']}</td><td>{$row['salary']}</td></tr>";
}
echo "</table>";

echo "<h2>Employees and(sort by address)</h2>";
$res2 = $conn->query("SELECT full_name, address FROM employees ORDER BY address ASC");
echo "<table border='1' cellpadding='5'><tr><th>Имя</th><th>Адрес</th></tr>";
while ($row = $res2->fetch_assoc()) {
    echo "<tr><td>{$row['full_name']}</td><td>{$row['address']}</td></tr>";
}
echo "</table>";

echo "<h2>Employees with self experience more than 4 years </h2>";
$res3 = $conn->query("SELECT full_name, hire_date, TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) AS years_worked 
                      FROM employees 
                      WHERE TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) > 4");
echo "<table border='1' cellpadding='5'><tr><th>Имя</th><th>Дата найма</th><th>Стаж (лет)</th></tr>";
while ($row = $res3->fetch_assoc()) {
    echo "<tr><td>{$row['full_name']}</td><td>{$row['hire_date']}</td><td>{$row['years_worked']}</td></tr>";
}
echo "</table>";

$conn->close();
?>
