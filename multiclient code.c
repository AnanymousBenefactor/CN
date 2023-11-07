multiclient code
#include <stdio.h>                                                                                                                                                     
#include <stdlib.h>                                                                                                                                                    
#include <string.h>                                                                                                                                                    
#include <arpa/inet.h>                                                                                                                                                 
#include <unistd.h>                                                                                                                                                    
                                                                                                                                                                       
#define SERVER_IP "127.0.0.1"                                                                                                                                          
#define PORT 49149                                                                                                                                                     
#define BUFFER_SIZE 1024                                                                                                                                               
                                                                                                                                                                       
int main() {                                                                                                                                                           
        int client_socket;                                                                                                                                             
        struct sockaddr_in server_addr;                                                                                                                                
        char buffer[BUFFER_SIZE];                                                                                                                                      
                                                                                                                                                                       
                                                                                                                                                                       
        client_socket = socket(AF_INET, SOCK_STREAM, 0);                                                                                                               
        if (client_socket == -1) {                                                                                                                                     
                perror("Socket creation failed");                                                                                                                      
                exit(EXIT_FAILURE);                                                                                                                                    
        }                                                                                                                                                              
                                                                                                                                                                       
                                                                                                                                                                       
        server_addr.sin_family = AF_INET;                                                                                                                              
        server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);                                                                                                            
        server_addr.sin_port = htons(PORT);                                                                                                                            
                                                                                                                                                                       
                                                                                                                                                                       
        if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {                                                                      
                perror("Connection failed");                                                                                                                           
                exit(EXIT_FAILURE);                                                                                                                                    
        }                                                                                                                                                              
                                                                                                                                                                       
                                                                                                                                                                       
        ssize_t id_received = recv(client_socket, buffer, BUFFER_SIZE, 0);                                                                                             
        if (id_received > 0) {                                                                                                                                         
                buffer[id_received] = '\0';                                                                                                                            
                printf("%s", buffer);                                                                                                                                  
        }                                                                                                                                                              
                                                                                                                                                                       
        while (1) {                                                                                                                                                    
                printf("Enter a message (or 'exit' to quit): ");                                                                                                       
                fgets(buffer, BUFFER_SIZE, stdin);                                                                                                                     
                buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character                                                                                      
                                                                                                                                                                       
                if (strcmp(buffer, "exit") == 0) {                                                                                                                     
                        send(client_socket, buffer, strlen(buffer), 0);                                                                                                
                        printf("Server disconnected.\n");                                                                                                              
                        break;                                                                                                                                         
                }                                                                                                                                                      
                                                                                                                                                                       
                send(client_socket, buffer, strlen(buffer), 0);                                                                                                        
                                                                                                                                                                       
                ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);                                                                                  
                if (bytes_received > 0) {                                                                                                                              
                        buffer[bytes_received] = '\0';                                                                                                                 
                        printf("Server response: %s\n", buffer);                                                                                                       
                }                                                                                                                                                      
        }                                                                                                                                                              
                                                                                                                                                                       
        close(client_socket);                                                                                                                                          
                                                                                                                                                                       
        return 0;                                                                                                                                                      
}               


multiserver code
#include <stdio.h>                                                                                                                                                     
#include <stdlib.h>                                                                                                                                                    
#include <string.h>                                                                                                                                                    
#include <arpa/inet.h>                                                                                                                                                 
#include <unistd.h>                                                                                                                                                    
#define Z 12                                                                                                                                                           
#define PORT 49149                                                                                                                                                     
#define MAX_CLIENTS 10                                                                                                                                                 
#define BUFFER_SIZE 1024                                                                                                                                               
                                                                                                                                                                       
void handle_client(int client_socket, int client_id) {                                                                                                                 
        char buffer[BUFFER_SIZE];                                                                                                                                      
        ssize_t bytes_received;                                                                                                                                        
                                                                                                                                                                       
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {                                                                                   
                buffer[bytes_received] = '\0';                                                                                                                         
                printf("Received from client %d: %s\n", client_id, buffer);                                                                                            
                                                                                                                                                                       
                                                                                                                                                                       
                if (strcmp(buffer, "exit") == 0) {                                                                                                                     
                        printf("Client %d requested to disconnect.\n", client_id);                                                                                     
                        break;                                                                                                                                         
                }                                                                                                                                                      
                                                                                                                                                                       
                                                                                                                                                                       
                send(client_socket, buffer, bytes_received, 0);                                                                                                        
        }                                                                                                                                                              
                                                                                                                                                                       
        close(client_socket);                                                                                                                                          
}                                                                                                                                                                      
                                                                                                                                                                       
int main() {                                                                                                                                                           
        int server_socket, client_socket;                                                                                                                              
        struct sockaddr_in server_addr, client_addr;                                                                                                                   
        socklen_t client_addr_len = sizeof(client_addr);                                                                                                               
                                                                                                                                                                       
                                                                                                                                                                       
        server_socket = socket(AF_INET, SOCK_STREAM, 0);                                                                                                               
        if (server_socket == -1) {                                                                                                                                     
                perror("Socket creation failed");                                                                                                                      
                exit(EXIT_FAILURE);                                                                                                                                    
        }                                                                                                                                                              
                                                                                                                                                                       
                                                                                                                                                                       
        server_addr.sin_family = AF_INET;                                                                                                                              
        server_addr.sin_addr.s_addr = INADDR_ANY;                                                                                                                      
        server_addr.sin_port = htons(PORT);                                                                                                                            
                                                                                                                                                                       
                                                                                                                                                                       
        if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {                                                                         
                perror("Binding failed");                                                                                                                              
                exit(EXIT_FAILURE);                                                                                                                                    
        }                                                                                                                                                              
                                                                                                                                                                       
                                                                                                                                                                       
        if (listen(server_socket, MAX_CLIENTS) == -1) {                                                                                                                
                perror("Listening failed");                                                                                                                            
                exit(EXIT_FAILURE);                                                                                                                                    
        }                                                                                                                                                              
                                                                                                                                                                       
        printf("Server listening on port %d...\n", PORT);                                                                                                              
                                                                                                                                                                       
        int client_id = 1; // Start assigning IDs from 1                                                                                                               
                                                                                                                                                                       
        while (1) {                                                                                                                                                    
                                                                                                                                                                       
                client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);                                                              
                if (client_socket == -1) {                                                                                                                             
                        perror("Acceptance failed");                                                                                                                   
                        continue;
                }                                                                                                                                                      
                                                                                                                                                                       
                printf("New client connected: %s (ID: %d)\n", inet_ntoa(client_addr.sin_addr), client_id);                                                             
                                                                                                                                                                       
                                                                                                                                                                       
                char id_message[BUFFER_SIZE];                                                                                                                          
                snprintf(id_message, BUFFER_SIZE, "You are connected with ID: %d\n", client_id);                                                                       
                send(client_socket, id_message, strlen(id_message), 0);                                                                                                
                                                                                                                                                                       
                                                                                                                                                                       
                if (fork() == 0) {                                                                                                                                     
                                                                                                                                                                       
                        handle_client(client_socket, client_id);                                                                                                       
                        close(client_socket);                                                                                                                          
                        exit(EXIT_SUCCESS);                                                                                                                            
                } else {                                                                                                                                               
                                                                                                                                                                       
                        close(client_socket);                                                                                                                          
                }                                                                                                                                                      
                                                                                                                                                                       
                client_id++;                                                                                                                                           
        }                                                                                                                                                              
                                                                                                                                                                       
        close(server_socket);                                                                                                                                          
                                                                                                                                                                       
        return 0;                                                                                                                                                      
} 