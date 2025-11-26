<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Triggers</title>
</head>
<body>

<h2>DDL and DML operations</h2>

<form action=main.php method="GET">
    <button type="submit" name="action" value="create">CREATE TABLE</button>
    <button type="submit" name="action" value="alter">ALTER TABLE</button>
    <button type="submit" name="action" value="drop">DROP TABLE</button>
    <button type="submit" name="action" value="insert">INSERT</button>
    <button type="submit" name="action" value="update">UPDATE</button>
    <button type="submit" name="action" value="delete">DELETE</button>
    <button type="submit" name="action" value="select">SELECT</button>
    
</form>

<h2>Trigger actions</h2>

<form action=main.php method="GET">
    <button type="submit" name="action" value="trigger_table_create">TRIGGER TABLE CREATE</button>
    <button type="submit" name="action" value="trigger">TRIGGER TABLE SHOW</button>
        <button type="submit" name="action" value="trigger_insert">TRIGGER INSERT</button>
    <button type="submit" name="action" value="trigger_update">TRIGGER UPDATE</button>
    <button type="submit" name="action" value="trigger_delete">TRIGGER DELETE</button>
    <button type="submit" name="action" value="trigger_drop">ALL TRIGGERS DROP</button>
    <button type="submit" name="action" value="trigger_table_drop">TRIGGER TABLE DROP</button>
</form>

</body>
</html>
