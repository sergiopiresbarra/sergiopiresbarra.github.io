function darPlay() {
			var playAudio = document.getElementById("playAudio");
			playAudio.play();
			}
			function darplay2() {
			var playAudio2 = document.getElementById("playAudio2");
			playAudio2.play();
			}
		
			function jogador(posX, posY) {
				this.posX = posX;
				this.posY = posY;
				this.score = 0;
				this.l = 100;
				this.a = 10;
			}
			
			function comida(p) {
				this.posX = 600;	//Math.floor(Math.random()*1000);
				this.posY = 100;	//Math.floor(Math.random()*640);
				this.pontos = p;
				this.l = 50;
				this.a = 50;
			}

			var jogador = new jogador(300, 510);
			
			var cenoura = new comida(10);
			
			var contador_de_cenouras = 0;
			var temporizador;
			var jogoIniciado = false;
			var temCenoura = false;

			cenoura.posY = Math.floor(Math.random() * 620);
			cenoura.posX = Math.floor(Math.random() * 1000);
			G = 5;
			H = 5;
			function colisao(obj1, obj2) {
				if(obj1.posX > obj2.posX + obj2.l)
					return false;
				if(obj1.posY > obj2.posY + obj2.a)
					return false;
				if(obj1.posX + obj1.l < obj2.posX)
					return false;
				if(obj1.posY + obj1.a < obj2.posY)
					return false;
				return true;
			}

			function jogar() {
				if(!temCenoura) {
					if(colisao(jogador, cenoura)) {
						//-- INVERTE SE COLIDIR --
						if(Math.floor(Math.random()*100)%2 == 0){H = -1*H;}
						G = -1*G;
						//if(H>0){H = Math.floor(Math.random() * 20) + H;}
						//else{H = H-(Math.floor(Math.random() * 20));}
						//if(G>0){G = Math.floor(Math.random() * 20) + G;}
						//else{G = G-(Math.floor(Math.random() * 20));}
						darPlay();
						jogador.score = jogador.score + cenoura.pontos;
						temCenoura = false;
						document.getElementById('score').innerHTML = "SCORE: " + jogador.score + " pts";
	
				    }
				    document.getElementById('explosao').style.visibility = "hidden";
					document.getElementById('pos').innerHTML = "Jogador: x:" + jogador.posX + " y:" + jogador.posY + "</br> Cenoura: x:" + cenoura.posX + " y:" + cenoura.posY;
					contador_de_cenouras = contador_de_cenouras + 1;
					document.getElementById('num_cenouras').innerHTML = contador_de_cenouras;
					if(cenoura.posY<620 && G>0){
						cenoura.posY = cenoura.posY + G;
					}
					else{
						if(G>0){G=-1*G}
						cenoura.posY = cenoura.posY + G;
					    if(cenoura.posY < 5){
					    	G = -1*G;
					    }
					}
					if(cenoura.posX<1000 && H>0){
						cenoura.posX = cenoura.posX + H;
					}
					else{
						if(H>0){H=-1*H}
						cenoura.posX = cenoura.posX + H;
					    if(cenoura.posX < 5){
					    	H = -1*H;
					    }
					}
					if(cenoura.posY > 580){
						cenoura.posY = 85;
						document.getElementById('explosao').style.left = cenoura.posX + "px";
						cenoura.posX = Math.floor(Math.random()*1000);
						H = -1*H;
						jogador.score = jogador.score - cenoura.pontos;
						document.getElementById('score').innerHTML = "SCORE: " + jogador.score + " pts";
						document.getElementById('explosao').style.visibility = "visible";
						darplay2();

					}

					document.getElementById("cenoura").style.top = cenoura.posY + "px";
					document.getElementById("cenoura").style.left = cenoura.posX + "px";
					//document.getElementById("cenoura").style.visibility = "visible";				
					temCenoura = true;
				} else {
					//document.getElementById("cenoura").style.visibility = "hidden";
					temCenoura = false;
				}
				temporizador = setTimeout("jogar()", 10);
			}
			
			
			function iniciarJogo() {
				if(!jogoIniciado) {
					jogoIniciado = true;
					jogar();
				}
			}

			function pararJogo() {
				clearTimeout(temporizador);
				jogoIniciado = false;
			}

			//funcao colisao estava aqui

			function teclaPressionada(e) {
				
				var carac = String.fromCharCode(e.which);
				if(carac == 'W') {
					//jogador.posY = jogador.posY - 10;
					//document.getElementById("jogador").style.top = jogador.posY + "px";
				} else {
					if(carac == 'S') {
						//jogador.posY = jogador.posY + 10;
						//document.getElementById("jogador").style.top = jogador.posY + "px";
					} else {
						if(carac == 'A' && jogador.posX > 0) {
							jogador.posX = jogador.posX - 30;
							document.getElementById("jogador").style.left = jogador.posX + "px";
						} else {
							if(carac == 'D' && jogador.posX < 950) {
								jogador.posX = jogador.posX + 30;
								document.getElementById("jogador").style.left = jogador.posX + "px";
							}
						}
					}
				}
				
			}
			document.onkeydown = teclaPressionada;
