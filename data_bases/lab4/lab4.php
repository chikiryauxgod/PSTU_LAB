<?php
header('Content-Type: text/html; charset=UTF-8');

$host = "localhost";
$user = "boss";
$pass = "boss_password";
$db   = "DB_EMPLOYEES";

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    die("Connection error: " . $conn->connect_error);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>DDL and DML commands demo</title>
</head>
<body>

<h2>DDL and DML operations</h2>

<form method="GET">
    <button type="submit" name="action" value="create">CREATE TABLE</button>
    <button type="submit" name="action" value="alter">ALTER TABLE</button>
    <button type="submit" name="action" value="drop">DROP TABLE</button>
    <button type="submit" name="action" value="insert">INSERT</button>
    <button type="submit" name="action" value="update">UPDATE</button>
    <button type="submit" name="action" value="delete">DELETE</button>
    <button type="submit" name="action" value="select">SELECT</button>
</form>

<hr>

<?php
if (isset($_GET['action'])) {
    $action = $_GET['action'];
    $result_message = "";

    switch ($action) {
        case 'create':
            $sql = "CREATE TABLE IF NOT EXISTS test_table (
                        id INT AUTO_INCREMENT PRIMARY KEY,
                        name VARCHAR(50),
                        age INT
                    )";
            $result_message = "Table 'test_table' created (if it didn’t exist).";
            break;

        case 'alter':
            $sql = "ALTER TABLE test_table ADD COLUMN city VARCHAR(50)";
            $result_message = "Column 'city' added to 'test_table'.";
            break;

        case 'drop':
            $sql = "DROP TABLE IF EXISTS test_table";
            $result_message = "Table 'test_table' deleted.";
            break;

        case 'insert':
            $sql = "INSERT INTO test_table (name, age, city)
                    VALUES ('Lev', 21, 'Perm')";
            $result_message = "New record inserted into 'test_table'.";
            break;

        case 'update':
            $sql = "UPDATE test_table SET age = 30 WHERE name = 'Lev'";
            $result_message = "Record updated in 'test_table'.";
            break;

        case 'delete':
            $sql = "DELETE FROM test_table WHERE name = 'Lev'";
            $result_message = "Record deleted from 'test_table'.";
            break;

        case 'select':
            $sql = "SELECT * FROM test_table";
            $result_message = "Selected all records from 'test_table'.";
            break;

        default:
            echo "<p>Unknown action.</p>";
            exit;
    }

    if ($action == 'select') {
        $res = $conn->query($sql);
        if ($res && $res->num_rows > 0) {
            echo "<table border='1'>";
            while ($row = $res->fetch_assoc()) {
                echo "<tr>";
                foreach ($row as $value) {
                    echo "<td>$value</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>No data to show.</p>";
        }
    } else {
        if ($conn->query($sql) === TRUE) {
            echo "<p>$result_message</p>";
        } else {
            echo "<p>Error: " . $conn->error . "</p>";
        }
    }
}
$conn->close();
?>

</body>
</html>
