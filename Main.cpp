#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// Configurações do PS3
#define FTP_IP   "192.168.0.117"  // Troque para o IP do seu PS3
#define FTP_PORT 21               // Porta FTP padrão

int main() {
    int sock;
    struct sockaddr_in server;
    
    // Cria o socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Erro ao criar socket\n");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(FTP_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(FTP_PORT);

    // Tenta conectar ao PS3
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Falha ao conectar no PS3 FTP\n");
        close(sock);
        return 1;
    }

    printf("✅ CL B1N v0.0 conectado ao PS3 via FTP!\n");

    close(sock);
    return 0;
}
