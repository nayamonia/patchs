#!/bin/bash
# Install PHP 5.6 on Ubuntu 12.04 LTS - https://youtu.be/FJW75F9HFIM
# Author: Gabriel Fernandes - gabriel@cd2.com.br
if [ "$(whoami)" != "root" ]; then
   echo "Somente root pode executar esse script" 1>&2
   exit 1
fi
echo "Patch para instalar ModuloPHP Zanthus no PHP 5.6"
echo "Valido para versoes luPDV Universal ate a versao 1.2 rc4 - Ubuntu 12.04 LTS"
sleep 20
apt-get update -y && apt-get install -y libmcrypt-dev
wget http://br2.php.net/get/php-5.6.28.tar.gz/from/this/mirror -O php-5.6.28.tar.gz
tar zxvf php-5.6.28.tar.gz && cd php-5.6.28
./configure \
    --enable-mbstring \
    --with-zlib \
	--enable-zip \
	--with-gd \
	--enable-soap \
	--enable-sockets \
	--enable-pcntl \
	--enable-sigchild \
	--enable-bcmath \
	--enable-exif \
	--with-openssl \
	--with-curl=/usr \
	--disable-cgi \
	--enable-gd-native-ttf \
	--with-mcrypt \
    --without-sqlite3 \
    --without-pdo-sqlite \
    --with-jpeg-dir=/usr \
    --with-png-dir=/usr
make && make install
cd .. && rm -rf php-5.6.28 php-5.6.28.tar.gz

cd /Zanthus/Zeus/path_comum/moduloPHPPDV
rsync -ravzpt moduloPHPPDV.zip /Zanthus/Zeus/pdvJava/GERAL/SINCRO/WEB/moduloPHPPDV/
cd /Zanthus/Zeus/pdvJava/GERAL/SINCRO/WEB/moduloPHPPDV/
unzip -o moduloPHPPDV.zip
chmod -R 777 *
echo " "
echo "FIM do patch" 
echo "========= ATENCAO ========="
echo "Certifique-se de estar com o ModuloPHP Zanthus para PHP5.6 na pasta /Zanthus/Zeus/pdvJava/GERAL/SINCRO/WEB/"
echo "==========================="
