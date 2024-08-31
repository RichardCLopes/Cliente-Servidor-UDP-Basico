#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define TAMR 2000

/*
 * Servidor UDP
 */

int main(argc, argv)
int argc;
char **argv;
{

   int sockint, s, namelen, client_address_size, porta;
   struct sockaddr_in client, server;
   char comando[200];
   char aux[TAMR];
	FILE *resposta;
	porta=atoi(argv[1]);
   /*
    * Cria um socket UDP (dgram). 
    */
   if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
   {
       perror("socket()");
       exit(1);
   }
   /*
    * Define a qual endereço IP e porta o servidor estará ligado.
    * Porta = 0 -> faz com que seja utilizada uma porta qualquer livre.
    * IP = INADDDR_ANY -> faz com que o servidor se ligue em todos
    * os endereços IP
    */
   server.sin_family = AF_INET;   /* Tipo do endereço             */
   server.sin_port = htons(porta);        /* Escolhe uma porta disponível */
   server.sin_addr.s_addr = INADDR_ANY;/* Endereço IP do servidor      */

   /*
    * Liga o servidor à porta definida anteriormente.
    */ 
   if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0)
   {
       perror("bind()");
       exit(1);
   }

   /* Consulta qual porta foi utilizada. */
   namelen = sizeof(server);
   if (getsockname(s, (struct sockaddr *) &server, &namelen) < 0)
   {
       perror("getsockname()");
       exit(1);
   }

   /* Imprime qual porta foi utilizada. */
   printf("Porta utilizada é %d\n", ntohs(server.sin_port));

   /*
    * Recebe uma mensagem do cliente.
    * O endereço do cliente será armazenado em "client".
    */
char a[4]="exit";
while(strcmp(a, comando)!=0){
for(int i=0;i<2000;i++)
{
aux[i]='\0';
}
   client_address_size = sizeof(client);
   if(recvfrom(s, comando, sizeof(comando), 0, (struct sockaddr *) &client,
            &client_address_size) <0)
   {
       perror("recvfrom()");
       exit(1);
   }

 /*
    * Imprime a mensagem recebida, o endereço IP do cliente
    * e a porta do cliente 
    */
   printf("\n\nRecebida a mensagem %s do endereco IP %s da porta %d\n", comando,inet_ntoa(client.sin_addr),ntohs(client.sin_port));

    resposta=popen(comando, "r");
int cont=0;
    do
    { 
        // Taking input single character at a time 
        char c = fgetc(resposta); 
  
        // Checking for end of file 
        if (feof(resposta)) 
            break ; 
  	aux[cont]=c;
cont++;
if(cont==2000)
{
break;
} 
    }  while(1);
printf("%s", aux);

 if (sendto(s, aux, (strlen(aux)+1), 0, (struct sockaddr *)&client, sizeof(client)) < 0)
   {
       perror("sendto()");
       exit(2);
   }

}
   /*
    * Fecha o socket.
    */
   close(s);
}
