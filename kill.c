// author darksec
//hook syscall kill :) easy!

#include <signal.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>

const int pids = 1337;

        ssize_t result;

int kill(pid_t pid, int sig){

int (*matar)(pid_t pid, int sig);

matar = dlsym(RTLD_NEXT, "kill");

if(pid == pids){

result = write(1, "Syscall Hook\n", strlen("Syscall Hook\n"));

} else {

return matar(pid, sig);

}

}
