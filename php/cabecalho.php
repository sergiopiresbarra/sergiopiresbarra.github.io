<?php session_start(); ?>
<!DOCTYPE html>
<html lang="en">
<head>
  <title>Meu Sistema TOP</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
  <style>
  background-image: url(http://www.herbaexpress.com.br/cadastro/wp-content/uploads/2016/08/carregando2.gif);
  </style>
  <script>

  </script>
<body>

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="index.php">Sistemas Web</a>
    </div>
    
    <ul class="nav navbar-nav navbar-right">
      <li><a href="" onclick="listarUsuarios();"><span class="glyphicon glyphicon-user"></span> Listar</a></li>
      <li><a href="cadastro.php"><span class="glyphicon glyphicon-user"></span> Cadastro</a></li>
       <li><a href="login.php"><span class="glyphicon glyphicon-user"></span> Login</a></li>
      <?php 
        if(!empty($_SESSION["logado"]) && $_SESSION["logado"] == false) {
           echo "<li><a href='login.php'><span class='glyphicon glyphicon-log-in'></span> Login</a></li>";  
        } else {
           echo "<li><a href='logout.php'><span class='glyphicon glyphicon-log-in'></span> Sair</a></li>";  
        }
      ?>
    </ul>
  </div>
</nav>
 