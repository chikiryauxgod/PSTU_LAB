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
    echo "<p>No action selected.</p>";
    exit;
}

$action = $_GET['action'];
$sql = "";
$title = "";

switch ($action) {
  case 'view_phones_create':
  case 'view_addresses_create':
  case 'view_experience_create':
    $sql = $queries[$action]['sql'];
    $title = $queries[$action]['message'];

    echo "<h3>$title</h3>";

    try {
      $conn->query($sql);
    } catch (mysqli_sql_exception $e) {
        echo "<p style='color:red;'>Failed: {$e->getMessage()}</p>";
    }

    echo "<p><a href='index.php'>Back</a></p>";
    $conn->close();
    exit;

  case 'phones':
  case 'addresses':
  case 'experience':
    $sql = $queries[$action]['sql'];
    $title = $queries[$action]['message'];
    break;

  default:
      echo "<p>Unknown action.</p>";
      exit;
}

echo "<h3>$title</h3>";

try {
    $res = $conn->query($sql);
} catch (mysqli_sql_exception $e) {
    echo "<p style='color:red;'>Action failed: {$e->getMessage()}</p>";
    exit;
}

if ($res && $res->num_rows > 0) {
  echo "<table border='1' cellpadding='3'><tr>";

  while ($field = $res->fetch_field()) {
    echo "<th>{$field->name}</th>";
  }
  echo "</tr>";

  while ($row = $res->fetch_assoc()) {
    echo "<tr>";
    foreach ($row as $value) {
        echo "<td> $value </td>";
    }
    echo "</tr>";
  }
  echo "</table>";

} else {
    echo "<p>No data to display.</p>";
}

echo "<p><a href='index.php'>Back</a></p>";

$conn->close();
