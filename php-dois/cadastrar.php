<html>
<body>

Bem vindo <?php echo $_GET["nome"]; ?><br>
Tome cuidado, agora sei seu e-mail: <?php echo $_GET["email"]; ?>
  <?php
  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "loja";

// Create connection
$conn = new mysqli($servername, $username, $password,$dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
echo "<br>Sistema conectado ao sgbd";
  $nome = $_POST["nome"];
  $senha = sha1($_POST["senha"]);
  $email = $_POST["email"];
  $endereco = $_POST["endereco"];
  
  $sql = "INSERT INTO usuario (nome, email, senha, endereco)
VALUES ('".$nome."', '".$email."', '".$senha."', '".$endereco."')";

if ($conn->query($sql) === TRUE) {
    echo "Cadastrado com sucesso!";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
  
  ?>

</body>
</html>