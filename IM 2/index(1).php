<?php include("database.php"); ?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
</head>

<body>
    <table class="table">
        <thead>
            <tr>
                <th scope="col">martian_id</th>
                <th scope="col">first_name</th>
                <th scope="col">last_name</th>
                <th scope="col">base_id</th>
                <th scope="col">super_id</th>
                <th scope="col">base_id</th>
                <th scope="col">base_name</th>
                <th scope="col">founded</th>
            </tr>
        </thead>
        <tbody>
            <?php
                $sql = "SELECT * FROM martian INNER JOIN base ON martian.base_id = base.base_id;";
                $result = mysqli_query($conn, $sql);
                
                if (mysqli_num_rows($result) > 0) {
                  while($row = mysqli_fetch_assoc($result)) {
                    ?>
                    <tr>
                        <td><?php echo $row["martian_id"] ?></td>
                        <td><?php echo $row["first_name"] ?></td>
                        <td><?php echo $row["last_name"] ?></td>
                        <td><?php echo $row["base_id"] ?></td>
                        <td><?php echo $row["super_id"] ?></td>
                        <td><?php echo $row["base_id"] ?></td>
                        <td><?php echo $row["base_name"] ?></td>
                        <td><?php echo $row["founded"] ?></td>
                    </tr>
                    <?php
                  }
                } else {
                  echo "0 results";
                }
                
                mysqli_close($conn);
            ?>
        </tbody>
    </table>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
</body>

</html>