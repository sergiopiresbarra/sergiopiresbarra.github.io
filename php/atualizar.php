<?php include 'cabecalho.php';?>

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
  $id = $_POST["id"];
  $nome = $_POST["nome"];
  $email = $_POST["email"];
  $endereco = $_POST["endereco"];
  
  $sql = "UPDATE usuario SET nome='".$nome."', email='".$email."', endereco='".$endereco."'
 WHERE id=".$id;

if ($conn->query($sql) === TRUE) {
    echo "Atualizdo com sucesso!";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
  
  ?>

</body>
</html>