<?php include 'cabecalho.php';?>

  <h1>
    Login
  </h1>
  <div>
    <?php
      if (!empty($_GET)) {
         $erro = $_GET["erro"]; 
         echo "<p style='color:red'>".$erro."</p>";
      }
        
    ?>
  </div>
<form action="logar.php">
 
  e-mail:<br>
  <input type="text" name="email">
  <br><br>
  senha:<br>
  <input type="password" name="senha">
  <br><br>
  <input type="submit" value="Entrar">
</form> 

</body>
</html>