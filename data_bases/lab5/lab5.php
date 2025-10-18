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
    <title>WEB Interface MySQL</title>
</head>
<body>

<form method="POST">
    <textarea name="query" rows="5" cols="80" placeholder="Enter your SQL query..."></textarea><br>
    <button type="submit">Execute</button>
</form>

<hr>

<?php
if (isset($_POST['query'])) {
    $query = trim($_POST['query']);
    echo "<p>Executed query: <b>$query</b></p>";

    $result = $conn->query($query);

    if ($result === TRUE) {
        echo "<p>Query executed successfully (no result set).</p>";
    } elseif ($result && $result->num_rows > 0) {
        echo "<table border='1'>";
        while ($field = $result->fetch_field()) {
            echo "<th>{$field->name}</th>";
        }
        
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            foreach ($row as $val) echo "<td>$val</td>";
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "<p>Error: " . $conn->error . "</p>";
    }
}
$conn->close();
?>

</body>
</html>