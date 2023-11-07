
client
#include<stdio.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                  
#include<netinet/in.h>                                                                                                                                                 
#include<sys/socket.h>                                                                                                                                                 
#include<string.h>                                                                                                                                                     
#include<unistd.h>                                                                                                                                                     
int main()                                                                                                                                                             
{                                                                                                                                                                      
        int sockdesc;                                                                                                                                                  
        struct sockaddr_in servaddr;                                                                                                                                   
        sockdesc=socket(AF_INET,SOCK_STREAM,0);                                                                                                                        
        if(sockdesc==-1)                                                                                                                                               
        {                                                                                                                                                              
                printf("Socket not created");                                                                                                                          
                return -1;                                                                                                                                             
        }                                                                                                                                                              
                                                                                                                                                                       
        servaddr.sin_family=AF_INET;                                                                                                                                   
        servaddr.sin_port=htons(49151);                                                                                                                                
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);                                                                                                                    
                                                                                                                                                                       
        if (connect(sockdesc,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)                                                                                        
        {                                                                                                                                                              
                printf("Connect Failed");                                                                                                                              
                return -1;                                                                                                                                             
        }                                                                                                                                                              
                                                                                                                                                                       
        char buffer[22];                                                                                                                                               
        char ans[30];                                                                                                                                                  
        fgets(buffer,sizeof(buffer),stdin);                                                                                                                            
        write(sockdesc,buffer,sizeof(buffer));                                                                                                                         
                                                                                                                                                                       
        read(sockdesc,ans,30);                                                                                                                                         
        printf("Message from server: %s", ans);                                                                                                                        
                                                                                                                                                                       
        close(sockdesc);                                                                                                                                               
        return 0;                                                                                                                                                      
                                                                                                                                                                       
}                     


server
#include<stdio.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                  
#include<netinet/in.h>                                                                                                                                                 
#include<sys/socket.h>                                                                                                                                                 
#include<string.h>                                                                                                                                                     
#include<unistd.h>                                                                                                                                                     
int main()                                                                                                                                                             
{                                                                                                                                                                      
        int sockdesc;                                                                                                                                                  
        struct sockaddr_in servaddr,cliaddr;                                                                                                                           
                                                                                                                                                                       
        sockdesc=socket(AF_INET,SOCK_STREAM,0);                                                                                                                        
        if(sockdesc==-1)                                                                                                                                               
        {                                                                                                                                                              
                printf("Socket not created");                                                                                                                          
                return -1;                                                                                                                                             
        }                                                                                                                                                              
                                                                                                                                                                       
        servaddr.sin_family=AF_INET;                                                                                                                                   
        servaddr.sin_port=htons(49151);                  // PORT number ranges from 1024 to 49151                                                                      
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);                                                                                                                    
        if(bind(sockdesc,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)                                                                                           
        {                                                                                                                                                              
                printf("Bind Failed");                                                                                                                                 
                return -1;                                                                                                                                             
        }                                                                                                                                                              
                                                                                                                                                                       
        if(listen(sockdesc,5)<0)                                                                                                                                       
        {                                                                                                                                                              
                printf("Listen Failed");                                                                                                                               
                return -1;                                                                                                                                             
        }                                                                                                                                                              
                                                                                                                                                                       
                                                                                                                                                                       
                                                                                                                                                                       
        while(1)                                                                                                                                                       
                                                                                                                                                                       
        {                                                                                                                                                              
                int len=sizeof(cliaddr);                                                                                                                               
                int connfd=accept(sockdesc,(struct sockaddr*)&cliaddr,&len);                                                                                           
                if (connfd<0)                                                                                                                                          
                {                                                                                                                                                      
                        printf("Accept failed");                                                                                                                       
                        return -1;                                                                                                                                     
                }                                                                                                                                                      
                                                                                                                                                                       
                                                                                                                                                                       
                char buffer[22];                                                                                                                                       
                strcpy(buffer," ");                                                                                                                                    
                read(connfd,buffer,22);                                                                                                                                
                printf("%s",buffer);                                                                                                                                   
                                                                                                                                                                       
                                                                                                                                                                       
                int j=0;                                                                                                                                               
                char ans[30];                                                                                                                                          
                int counter=0;                                                                                                                                         
                int i=0;                                                                                                                                               
                while(buffer[i] !='\n'){                                                                                                                               
                        if(counter == 5){                                                                                                                              
                                ans[j]='0';                                                                                                                            
                                j++;                                                                                                                                   
                                counter = 0;                                                                                                                           
                                continue;                                                                                                                              
                        }else {                                                                                                                                        
                                                                                                                                                                       
                                if(buffer[i] == '0'){                                                                                                                  
                                        ans[j]='0';                                                                                                                    
                                        printf("%c",ans[j]);                                                                                                           
                                        j++;                                                                                                                           
                                        i++;                                                                                                                           
                                        counter=0;
                                }                                                                                                                                      
                                else{                                                                                                                                  
                                        ans[j]='1';                                                                                                                    
                                        counter++;                                                                                                                     
                                        j++;                                                                                                                           
                                        i++;                                                                                                                           
                                }                                                                                                                                      
                        }                                                                                                                                              
                                                                                                                                                                       
                }                                                                                                                                                      
                ans[j]='\0';                                                                                                                                           
                printf("The ans is : %s",ans);                                                                                                                         
                write(connfd,ans,sizeof(ans));                                                                                                                         
                                                                                                                                                                       
                                                                                                                                                                       
        }                                                                                                                                                              
                                                                                                                                                                       
        close(sockdesc);                                                                                                                                               
                                                                                                                                                                       
        return 0;                                                                                                                                                      
}