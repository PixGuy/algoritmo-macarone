<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    define("MIN", '0'); #33
    define("MAX", 'z'); #126

    $stop = 0;
    $try = 1;

    function break_loop($senha, $tentativa) {
        global $stop, $try;

        if ($tentativa === str_replace(' ', '', $senha)) {
            echo "A senha eh " . $tentativa . "!";
            $stop = 1;
            return;
        }

        if (strlen($tentativa) >= strlen($senha)) {
            return;
        }

        for ($i = MIN; $i <= MAX; $i++) {
            if ($stop === 1) {
                return;
            }
            echo "tentando: " . $tentativa . $i . " contra " . $senha . " " . $try .  "<br>";
            $try += 1;
            break_loop($senha, $tentativa . $i);
        }
    }

    echo 'Tentando quebrar: ' . "obara <br>"; 

    break_loop("1234", "");
    ?>
</body>
</html>