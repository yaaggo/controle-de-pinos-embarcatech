<samp>
<h1 align="center"> Controlando pinos GPIO do microcontrolador RP2040 </h1>
<h2 align="center"> Sobre :pencil: </h2>

<p> &emsp;&emsp;&emsp;&emsp; Repositório colaborativo com o objetivo de desenvolver habilidades práticas com a placa BitDogLab e seus pinos, como parte de uma tarefa desenvolvida no Capítulo 2 da Unidade 4 da Embarcatech, residência de Sistemas Embarcados. 

<p> &emsp;&emsp;&emsp;&emsp; Essa tarefa foi desenvolvida pelo subgrupo 1 do grupo 5 do estado da Bahia (CEPEDI), pelos residentes Camila Miranda, Isabela Madureira, Matheus Nascimento e Yago Guirra.

<h3> Descrição da tarefa </h3>

<p> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar a porta serial UART, com o emprego da ferramenta educacional BitDogLab, para controlar determinados pinos GPIO do microcontrolador RP2040, presente na placa de desenvolvimento Raspberry Pi Pico W, onde foi realizado o acionamento do LED RGB (GPIOs 11, 12 e 13), juntamente com o controle de sinal sonoro de um buzzer, conectado à GPIO 21 - Botão A. Como forma de comunicação entre o usuário e o sistema embarcado, deve-se escrever comandos (conjuntos de caracteres) para serem interpretados pelo microcontrolador de modo a realizar o controle dos periféricos trabalhados. Nela, foi necessário utilizar os seguintes componentes:

  1. Ferramenta educacional BitDogLab (versão 6.3);
  2. Cabo tipo micro-usb para usb-a;
  3. Computador pessoal.

 &emsp;&emsp;&emsp;&emsp; O programa deve:

  1. Ligar LED verde (GPIO 11) – desligar as demais GPIOs;
  2. Ligar LED azul (GPIO 12) - desligar as demais GPIOs;
  3. Ligar LED vermelho (GPIO 13) - desligar as demais GPIOs;
  4. Ligar os três LEDs (luz branca);
  5. Desligar todos os LEDs;
  6. Acionar o buzzer por 2 segundos – emissão de sinal sonoro;
  7. Sair do modo de execução e habilitar o modo de gravação via software (reboot) – rotina opcional.

 &emsp;&emsp;&emsp;&emsp; Foi organizada uma equipe, dividida em 1 Líder (gerencia o repositório) e 3 desenvolvedores (cada um com tarefa específica). 

<p> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de um READ.ME (descrição do projeto), diagram.json e wokwi.toml (para a simulação no Wokwi) e uma pasta chamada 'inc', que possui 2 arquivos na extensão .c, que são: buzzer.c (que organiza as funções relacionadas ao buzzer) e led.c (que organiza as funções relacionadas ao leds), e 2 arquivos na extensão .h, que são: buzzer.h e led.h (em que ambos possuem o cabeçalho das funções).

<h2></h2>
<h2 align="center"> Vídeo :video_camera: </h2>
<p> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>
<p align="center"> https://www.youtube.com/watch?v=7KnGssMSDS8 </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão "Raspberry Pi Pico Project";
- Compilar e executar o projeto;
- Configurar e acionar o PuTTY;
- Escolher o que deseja fazer, de acordo com as opções do menu, e pressionar a tecla correspondente.
</samp>
