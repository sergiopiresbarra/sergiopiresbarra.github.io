<html>
  <head>
  </head>
  <body>
    <?php
      $servername = "localhost";
      $username = "root";
      $password = "";
      $dbname = "loja";

      // criar con
      $conn = new mysqli($servername, $username, $password,$dbname);

      // verificar con
      if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
      } 

      $sql = "SELECT nome, email FROM usuario";
      $result = $conn->query($sql);

      if ($result->num_rows > 0) {
          // output data of each row
          while($row = $result->fetch_assoc()) {
              echo "Nome: " . $row["nome"]. " - E-mail: " . $row["email"]."<br>";
          }
      } else {
          echo "0 results";
      }
      $conn->close();
      ?>
  </body>
</html>
