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

$action = "";
$mode = "";

if (isset($_GET['create'])) {
    $action = $_GET['create'];
    $mode = "create";
} else if (isset($_GET['select'])) {
    $action = $_GET['select'];
    $mode = "select";
} else {
    echo "<p>No action selected.</p>";
    exit;
}

if (!isset($queries[$action])) {
    echo "<p>Unknown action. </p>";
    exit;
}

$sql_template = $queries[$action]['sql'];

if ($queries[$action]['message'] !== null) {
    $title = $queries[$action]['message'];
} else {
    $title = $action;
}


echo "<h3>$title</h3>";

if ($mode === "create") {
  try {
    $conn->query($sql_template);
    echo "<p style='color:green'>Procedure created.</p>";
  } catch (mysqli_sql_exception $e) {
      echo "<p style='color:red;'>Failed to create action: {$e->getMessage()}</p>";
  }
  echo "<p><a href='index.php'>Back</a></p>";
  $conn->close();
  exit;
}

$sql = $sql_template;

foreach ($_GET as $key => $val) {
    if ($key === 'select') continue;
    $sql = str_replace("{" . $key . "}", $val, $sql);
}


try {
    $res = $conn->query($sql);
} catch (mysqli_sql_exception $e) {
    echo "<p style='color:red;'>Action failed: {$e->getMessage()}</p>";
    $conn->close();
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
