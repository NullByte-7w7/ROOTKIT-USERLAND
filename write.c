// hookando a syscall da write()

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

        ssize_t write(int fd, const void *buf, size_t count)
{


        ssize_t (*darksec)(int fd, const void *buf, size_t count);

        darksec = dlsym(RTLD_NEXT, "write");

if(strcmp(buf, "darksec") == 0){

        return write(1, "Hacked 1337", 12);

} else {

        return darksec(fd, buf, count);
}

}

int main(void){

        char nome[200];

        printf("What's your name? \n");
        scanf("%s", &nome);

        write(1, nome, strlen(nome));

}
