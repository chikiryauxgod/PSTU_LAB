<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Procedure</title>
</head>
<body>

<h2>Create procedure (only create definitions)</h2>
<form action="main.php" method="GET">
    <button type="submit" name="create" value="procedure_add_employee">Create: Add employee</button>
    <button type="submit" name="create" value="procedure_delete_by_id">Create: Delete by ID</button>
    <button type="submit" name="create" value="procedure_summary_salary">Create: Summary salary</button>
</form>

<hr>

<h2>Run procedures</h2>

<form action="main.php" method="GET">
    <button type="submit" name="select" value="call_summary_salary">Show total salary</button>
    <button type="submit" name="select" value="call_all_employees">Show all employees</button>
</form>

<hr>

<h3>Add employee (calls procedure)</h3>
<form action="main.php" method="GET">
    <input type="hidden" name="select" value="call_add_employee">
    Full name: <input type="text" name="full_name" required><br>
    Phone: <input type="text" name="phone" required><br>
    Salary: <input type="number" name="salary" required><br>
    Address: <input type="text" name="address" required><br>
    Hire date: <input type="date" name="hire_date" required><br>
    <button type="submit">Add employee</button>
</form>

<hr>

<h3>Delete employee by id (calls procedure)</h3>
<form action="main.php" method="GET">
    <input type="hidden" name="select" value="call_delete_by_id">
    ID: <input type="number" name="id" required>
    <button type="submit">Delete</button>
</form>

</body>
</html>
