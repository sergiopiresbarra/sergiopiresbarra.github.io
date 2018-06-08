<?php include 'cabecalho.php';?>
<script>
//var myVar = setInterval(listarUsuarios, 2000);

    function listarUsuarios() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("listUserDiv").innerHTML =
          this.responseText;
        }
      };
      xhttp.open("GET", "listar.php", true);
      xhttp.send();
    }
  </script>
    <?php
  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "loja";

// Create connection
$conn = new mysqli($servername, $username, $password,$dbname);

if($_SESSION["logado"] == false) {
  echo "Usuario nao logado";
} else {

  // Check connection
  if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
  } 

  $sql = "SELECT * FROM usuario";
  $result = $conn->query($sql);

  echo "<div id='listUserDiv'><table class='table-condensed'>";

  if ($result->num_rows > 0) {
      echo "<tr>";
      echo "<th>id</th><th>Nome</th><th>e-mail</th><th>endereco</th><th>senha</th><th></th><th></th>";
      echo "</tr>";
      // output data of each row
      while($row = $result->fetch_assoc()) {
          echo "<tr>";
          echo "<td>".$row["id"]."</td><td>" . $row["nome"]. "</td><td>" . $row["email"]."</td><td>" . $row["endereco"]."</td><td>".$row["senha"]."</td><td><a href='editar.php?id=".$row["id"]."' class='btn btn-default'>Editar</a></td><td><a href='remover.php?id=".$row["id"]."' class='btn btn-sm btn-danger'>Remover</a></td>";
          echo "</tr>";
      }
  } else {
      echo "0 results";
  }
  echo "</table></div>";
  $conn->close();
}
?>


    
  </body>
</html>

 