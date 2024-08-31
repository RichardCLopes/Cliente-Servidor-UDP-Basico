# Descrição da Atividade
Esta atividade tem como objetivo introduzir conceitos básicos de desenvolvimento de software para ambientes TCP/IP, com foco na implementação de clientes e servidores utilizando o protocolo UDP.


## Objetivos
* Estudo dos textos sobre Projeto de Software de Clientes e Projeto e Implementação de Servidores.
* Compilação e teste de programas exemplo para cliente e servidor UDP.
* Implementação de uma aplicação que permite a execução remota de comandos via UDP.
* Elaboração de um relatório detalhado sobre o trabalho realizado.

## Implementação
Nesta atividade serão desenvolvidos um cliente UDP e um servidor UDP que permitirão a execução remota
de comandos.

O servidor UDP ao ser executado deve receber como parâmetro a porta UDP que será utilizada para
aguardar o envio de comandos, como no exemplo a seguir: 

```./servidor 5000```

O servidor UDP ao ser iniciado deve ficar aguardando o envio de um comando na porta UDP fornecida
como parâmetro. Ao receber um comando, deve exibir na tela o endereço IP e a porta UDP utilizadas pela
cliente, além do comando enviado.

Em seguida deve executar o comando solicitado, enviar ao cliente uma mensagem de no máximo 2000
caracteres contendo o resultado da execução do comando e aguardar o envio de um novo comando.

O cliente UDP ao ser executado deve receber como parâmetros o endereço IP do computador onde está
sendo executado o servidor UDP e o número da porta UDP onde o servidor está aguardando, como no
exemplo a seguir:

```./cliente 192.168.1.2 5000```

Ao iniciar sua execução, o cliente UDP exibirá um prompt de comando (caracter ">") e aguardará o usuário
digitar um comando de no máximo 200 caracteres.

Após a leitura do comando fornecido pelo usuário, o cliente enviará este comando ao servidor UDP para
que o comando seja executado remotamente pelo servidor.

Em seguida, o cliente aguardará uma resposta do servidor contendo o resultado da execução do comando
no servidor, que deve ser exibido na tela do cliente.

O programa cliente deve então exibir novamente o prompt de comando (caracter ">") e aguardar por um
novo comando, sendo finalizado apenas quando o usuário digitar o comando "exit".
