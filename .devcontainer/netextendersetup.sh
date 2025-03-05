# Download the NetExtender package to /temp and install it
# This script is for Ubuntu 22.04.1-Ubuntu SMP Thu Jul 11 22:33:04 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux
# This script is for SonicWall NetExtender 10.3.0-21
# This script is for NetExtender-linux-amd64-10.3.0-21.deb
mkdir /netextender
cd /netextender
wget https://software.sonicwall.com/NetExtender/NetExtender-linux-amd64-10.3.0-21.deb --no-check-certificate
dpkg -i ./NetExtender-linux-amd64-10.3.0-21.deb
rm ./NetExtender-linux-amd64-10.3.0-21.deb
