#!/bin/bash
# Patch para corrigir dependencias do ModuloPHP 5.6 Zanthus
if [ "$(whoami)" != "root" ]; then
   echo "Somente root pode executar esse script" 1>&2
   exit 1
fi
echo "Patch para corrigir dependencias do ModuloPHP Zanthus no PHP 5.6"
echo "Valido para versoes ate zeuspdvlinux-2.0.1805242312.iso"
sleep 20
pushd /tmp
wget http://www.zend.com/en/download/4718?start=true -O /tmp/zend-loader-php5.6-linux-i386_update1.tar.gz
tar zxvf /tmp/zend-loader-php5.6-linux-i386_update1.tar.gz -C /tmp zend-loader-php5.6-linux-i386/ZendGuardLoader.so
tar zxvf /tmp/zend-loader-php5.6-linux-i386_update1.tar.gz -C /tmp zend-loader-php5.6-linux-i386/opcache.so
rm -rfv /usr/lib/php/20131226/opcache.so 
mv -fv /tmp/zend-loader-php5.6-linux-i386/opcache.so /usr/lib/php/20131226/
mv -fv /tmp/zend-loader-php5.6-linux-i386/ZendGuardLoader.so /usr/lib/php/20131226/
rm -rfv /tmp/zend-loader-php5.6-linux-i386/
cat > /etc/php/5.6/mods-available/opcache.ini <<EOF
; configuration for php opcache module
; priority=10
zend_extension=opcache.so
; configuration for php zendguardloader
zend_extension=ZendGuardLoader.so
zend_loader.enable=1
EOF
cat > /etc/systemd/system/zanthus.service <<EOF
[Unit]
Description=Modulo PHP Zanthus
After=syslog.target
After=network.target

[Service]
Type=simple
PermissionsStartOnly=true
ExecStart=/usr/bin/php -S 0.0.0.0:9090 -t /Zanthus/Zeus/pdvJava/GERAL/SINCRO/WEB/ -c /etc/php/5.6/cli/php.ini
TimeoutSec=300
PrivateTmp=false
User=root
Group=root
WorkingDirectory=/usr/local/bin/

[Install]
WantedBy=multi-user.target
EOF
systemctl daemon-reload
systemctl enable zanthus
systemctl stop zanthus
systemctl start zanthus
popd
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

