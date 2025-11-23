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

if (!isset($_GET['query'])) {
  echo "<p>No query selected.</p>";
  exit;
}

$query_type = $_GET['query'];
$sql = "";
$title = "";

switch ($query_type) {
  case 'phones':
      $title = "Employees, phones and salary";
      $sql = "SELECT * FROM view_employees_phones";
      break;

  case 'addresses':
      $title = "Employees and their addresses (sorted by address)";
      $sql = "SELECT * FROM view_employees_addresses";
      break;

  case 'experience':
      $title = "Employees with experience more than 4 years";
      $sql = "SELECT * FROM view_employees_experience";
      break;

  default:
      echo "<p>Unknown query.</p>";
      exit;
}

try {
  $res = $conn->query($sql);
} catch (mysqli_sql_exception $e) {
  error_log("SQL error: " . $e->getMessage());
  echo "<p>Query failed. Please try again later.</p>";
  exit;
}

echo "<h3>$title</h3>";

if ($res && $res->num_rows > 0) {
  echo "<table border='1' cellpadding='3'><tr>";
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

$conn->close();
