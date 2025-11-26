<?php
header('Content-Type: text/html; charset=UTF-8');

$config = require __DIR__ . '/config.php';
$queries = require __DIR__ . '/queries.php';
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
$sql = '';
$result_message = '';

switch ($action) {
	case 'create':
	case 'alter':
	case 'drop':
	case 'insert':
	case 'update':
	case 'delete':
	case 'select':
	case 'trigger':
	case 'trigger_table_create':
	case 'trigger_update':
	case 'trigger_delete':
	case 'trigger_insert':
	case 'trigger_table_drop'	:
		$sql = $queries[$action]['sql'];
		$result_message = $queries[$action]['message'];
		break;	

	case 'trigger_drop':
		$conn->query("DROP TRIGGER IF EXISTS test_table_after_insert");
    $conn->query("DROP TRIGGER IF EXISTS test_table_after_update");
    $conn->query("DROP TRIGGER IF EXISTS test_table_after_delete");
		$sql = $queries[$action]['sql'];
			$result_message = $queries[$action]['message'];
		break;	


	default:
			echo "<p>Unknown action.</p>";
			exit;
}

try {
	if ($action === 'select' || $action == 'trigger') {
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
			if($sql != null) {
				$conn->query($sql);
			} 
			echo "<p>$result_message</p>";
  }
} catch (mysqli_sql_exception $e) {
		echo "<p style='color:red'>SQL error: " . $e->getMessage() . "</p>";
}

$conn->close();
?>
