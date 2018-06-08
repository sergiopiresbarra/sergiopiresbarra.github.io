<?php
   include "config.php";

   //VOCÊ PRECISA INFORMAR QUE O POST VEM DE UM FORMOLÁRIO
   //ENTÃO, FICARIA ASSIM:
    /* aqui você informa o parâmetro passado no submit do formulário */
   if(isset($_POST[])){

   $email = $_POST['email'];

  $consulta =  "SELECT * FROM usuarios WHERE user_email = '$email'";

  $resposta = mysql_num_rows($consulta);


if($resposta > 0 ){

	while($linha = mysql_fetch_array($resposta)){
		  $emailRecuperado = $linha["user_email"];
}


  $msg = "
              <h2 style='font-family:Verdana;'>Recuperação de Senha</h2><br/>
              <div style='Verdana; font-size:10pt;'>
                       Sua senha é: <span style='font-weight: bold;' $emailRecuperado</span>
              </div>";

$mensagem = $msg;
$destinatario = $email;
$assunto = "Recupeação de senha";
$headers = "Bcc: [email]webmaster@jeantavares.co.cc[/email]";

ini_set('sendmail_from', 'postmaster@jeantavares.co.cc');
mail($destinatario, $assunto, $mensagem, $headers);

}else{
  echo "Não Consta na base de dados";

}
   }
?>