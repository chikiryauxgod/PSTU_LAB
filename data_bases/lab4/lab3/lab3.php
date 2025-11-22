<?php
    header('Content-Type: text/html; charset=UTF-8');

    $host = "localhost";
    $user = "boss";
    $pass = "boss_password";
    $db   = "DB_EMPLOYEES";

    $conn = new mysqli($host, $user, $pass, $db);
    if ($conn->connect_error == TRUE) {
        die("Connection error: " . $conn->connect_error);
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Employee database queries</title>
</head>
<body>

<h2>Select a query</h2>

<form method="GET">
    <button type="submit" name="query" value="phones">Employees and phones</button>
    <button type="submit" name="query" value="addresses">Employees and addresses</button>
    <button type="submit" name="query" value="experience">Employees with experience &gt; 4 years</button>
</form>

<hr>

<?php
    if (isset($_GET['query'])) {
        $query_type = $_GET['query'];

        switch ($query_type) {
            case 'phones':
                echo "<h3>Employees, phones and salary</h3>";
                $sql = "SELECT full_name, phone, salary FROM employees";
                break;

            case 'addresses':
                echo "<h3>Employees and their addresses (sorted by address)</h3>";
                $sql = "SELECT full_name, address FROM employees ORDER BY address ASC";
                break;

            case 'experience':
                echo "<h3>Employees with experience more than 4 years</h3>";
                $sql = "SELECT full_name, hire_date, 
                            TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) AS years_worked 
                        FROM employees 
                        WHERE TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) > 4";
                break;

            default:
                echo "<p>Unknown query.</p>";
                exit;
        }

        $res = $conn->query($sql);
        if ($res && $res->num_rows > 0) {
            echo "<table border='1' cellpadding='3'>";
            echo "<tr>";

            while ($field = $res->fetch_field()) {
                echo "<th>{$field->name}</th>";
            }
            echo "</tr>";
            
            while ($row = $res->fetch_assoc()) {
                echo "<tr>";
                foreach ($row as $value) {
                    echo "<td>$value</td>";
                }
                echo "</tr>";
            }

            echo "</table>";
        } else {
            echo "<p>No data to display.</p>";
        }
    }

    $conn->close();
?>

</body>
</html>
