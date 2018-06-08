<?php include 'cabecalho.php';?>

 <h1>
    Atualizar Usuario
  </h1>

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
 //recuperando valores do formulario de login   
 $id = $_GET["id"];
 
$sql = "DELETE FROM usuario WHERE id=".$id;
$result = $conn->query($sql);
if ($conn->query($sql) === TRUE) {
    echo "Usuario removido com sucesso!";
} else {
    echo "Error deleting record: " . $conn->error;
}

$conn->close();
?>


 
</body>
</html>