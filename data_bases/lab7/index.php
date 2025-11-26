<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>View</title>
</head>
<body>

<h2>Create view</h2>
<form action="main.php" method="GET">
    <button type="submit" name="action" value="view_phones_create">Create view employees and phones</button>
    <button type="submit" name="action" value="view_addresses_create">Create view employees and addresses</button>
    <button type="submit" name="action" value="view_experience_create">Create view employees with experience &gt; 4 years</button>
</form>


<h2>Select a query</h2>
<form action="main.php" method="GET">
    <button type="submit" name="action" value="phones">Employees and phones</button>
    <button type="submit" name="action" value="addresses">Employees and addresses</button>
    <button type="submit" name="action" value="experience">Employees with experience &gt; 4 years</button>
</form>

</body>
</html>
