<!DOCTYPE html>
<html>
<head>
    <title>Fibonacci Series</title>
</head>
<body>
    <form method="post">
        Enter how many terms: <input type="number" name="terms">
        <input type="submit" value="Generate">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $terms = $_POST['terms'];
        $num1 = 0;
        $num2 = 1;

        echo "Fibonacci Series up to $terms terms: <br>";

        for ($i = 1; $i <= $terms; $i++) {
            echo $num1 . " ";
            $next = $num1 + $num2;
            $num1 = $num2;
            $num2 = $next;
        }
    }
    ?>
</body>
</html>
