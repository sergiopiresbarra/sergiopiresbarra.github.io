<?php include 'cabecalho.php';?>

  <h1>
    Logout
  </h1>
  <div>
    <?php
      // remove all session variables
      session_unset(); 

      // destroy the session 
      session_destroy(); 
       echo "Obrigado pela visita!";    
     ?>
  </div>


</body>
</html>