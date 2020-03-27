function noturna(){
    var x = window.document.getElementById('corpodoc');
    var y = window.document.getElementById('rodapedoc');
    var z = window.document.getElementById('caixascentro');
    var a = window.document.getElementById('coisasgit');
    var b = window.document.getElementById('coisasgit2');
    var c = window.document.getElementById('coisasgit3');
    var noite = window.document.getElementById('noite');
    if(noite.innerHTML == 'Modo Noturno'){    
        x.style.background = '#282a36';
        y.style.background = '#282a36';
        a.style.background = '#282a36';
        b.style.background = '#282a36';
        c.style.background = '#282a36';
        noite.innerHTML = 'Modo Diurno';
    }
    else{
        x.style = 'body {background-color: #f5f5f5;}';
        y.style = '.bg-gradient {background: linear-gradient(to right,#ce2e3c,#da6709);}';
        a.style.background = 'white';
        b.style.background = 'white';
        c.style.background = 'white';

        noite.innerHTML = 'Modo Noturno';

        
    }
}