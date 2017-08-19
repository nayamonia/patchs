#!/bin/bash
# Install PHP 5.6 on Ubuntu 12.04 LTS
# Author: Gabriel Fernandes - gabriel@cd2.com.br

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
