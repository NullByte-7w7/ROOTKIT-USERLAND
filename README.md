# rookit userland

# Welcome to My Rootkit

## Introduction

Welcome to my rootkit! This toolkit offers some cool and interesting functionalities designed to enhance your digital security. Let's dive into what it can do.

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

## Disclaimer

Please note that the use of rootkits and similar tools may be illegal and unethical. This README serves solely as a fictional exploration of hypothetical functionality and should not be used for malicious purposes.











*Welcome to my rootkit user, some cool and interesting functions it will do, when the digital attacker: kill 1337 it will ask for a password if the password matches it will perform the next step, if the password is not the same the machine will shut down , ok, but what happens if the password is the same? The rootkit will hide port 1337, that is, netstat (in the future I think I'll add it to ss) so it will hide port 1337, and in addition it will run a bind shell on the local machine, yes the firewall can block it, so I'm going to do a choose for the user to want a reverse shell or bind shell, the tail command will have no effect, that is, the sysadmin will not see his suspicious logs and will not use another tool to check the logs, but in the future I think about, for the sysadmin Don't be suspicious, I will hide /etc/ld.so.preload.*


*Password is darksec*
