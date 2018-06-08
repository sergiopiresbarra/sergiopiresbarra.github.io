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
 
$sql = "SELECT * FROM usuario WHERE id=".$id;
$result = $conn->query($sql);
if ($result->num_rows > 0) {
  
  $row = $result->fetch_assoc();
?>
<form action="atualizar.php" method="post">
  Nome:<br>
  <input type="text" name="nome" value="<?php echo $row["nome"];?>">
  <br>
  e-mail:<br>
  <input type="text" name="email" value="<?php echo $row["email"];?>">
  <br><br>
  Endereco:<br>
  <input type="text" name="endereco" value="<?php echo $row["endereco"];?>">
  <br><br>
  <input type="hidden" name="id" value="<?php echo $id;?>">
  <input type="submit" value="Atualizar">
</form>  

<?php
} else {
    echo "0 results";
}
?>


 
</body>
</html>