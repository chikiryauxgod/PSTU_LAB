<?php
header('Content-Type: text/html; charset=UTF-8');

$config = require __DIR__ . '/config.php';
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
	$conn = new mysqli(
			$config['host'],
			$config['user'],
			$config['pass'],
			$config['db']
	);
} catch (mysqli_sql_exception $e) {
	error_log("DB connection error: " . $e->getMessage());
	http_response_code(500);
	echo "<p style='color:red'>Database unavailable. Please try again later.</p>";
	exit;
}

if (!isset($_GET['action'])) {
	echo "<p>No query selected.</p>";
	exit;
}

$action = $_GET['action'];
$result_message = '';
$sql = '';

switch ($action) {
	case 'create':
			$sql = "CREATE TABLE IF NOT EXISTS test_table (
									id INT AUTO_INCREMENT PRIMARY KEY,
									name VARCHAR(50),
									age INT
							)";
			$result_message = "Table 'test_table' created.";
			break;

	case 'alter':
			$sql = "ALTER TABLE test_table ADD COLUMN city VARCHAR(50)";
			$result_message = "Column 'city' added.";
			break;

	case 'drop':
			$sql = "DROP TABLE IF EXISTS test_table";
			$result_message = "Table dropped.";
			break;

	case 'insert':
			$sql = "INSERT INTO test_table (name, age, city)
							VALUES ('Lev', 21, 'Perm')";
			$result_message = "Record inserted.";
			break;

	case 'update':
			$sql = "UPDATE test_table SET age = 30 WHERE name = 'Lev'";
			$result_message = "Record updated.";
			break;

	case 'delete':
			$sql = "DELETE FROM test_table WHERE name = 'Lev'";
			$result_message = "Record deleted.";
			break;

	case 'select':
			$sql = "SELECT * FROM test_table";
			break;

	default:
			echo "<p>Unknown action.</p>";
			exit;
}

try {
	if ($action === 'select') {
		$res = $conn->query($sql);
		if ($res->num_rows > 0) {
			echo "<table border='1'>";
			while ($row = $res->fetch_assoc()) {
					echo "<tr>";
					foreach ($row as $value) {
							echo "<td> $value </td>";
					}
					echo "</tr>";
			}
			echo "</table>";
			} else {
					echo "<p>No data to show.</p>";
			}
	} else {
			$conn->query($sql);
			echo "<p>$result_message</p>";
  }
} catch (mysqli_sql_exception $e) {
		echo "<p style='color:red'>SQL error: " . $e->getMessage() . "</p>";
}

$conn->close();
?>
