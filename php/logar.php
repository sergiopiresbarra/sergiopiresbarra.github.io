<html>
  <head>   
  </head>
  <body>
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
 $senha = sha1($_GET["senha"]);
 $email = $_GET["email"];
    
$sql = "SELECT email, senha FROM usuario";
$result = $conn->query($sql);
$logado = false;
if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        if($email==$row["email"] && $senha==$row["senha"]) {
            $logado = true;       
        }
    }
} else {
    echo "0 results";
}
    
if($logado==true) {
   echo "Bem vindo ".$email;
   echo "<br><a href='listar.php'>Listar usuarios</a>";
} else {
  header("Location: index.php?erro=senha e usuarios nao encontrados");
}
    
$conn->close();
?>


    
  </body>
</html>

 