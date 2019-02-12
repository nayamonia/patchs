#!/bin/bash
# Requisitos: macchaner instalado e poder de root
# MACChanger Install Howto:
# Create the repository config file /etc/yum.repos.d/nux-misc.repo:
#  [nux-misc]
#  name=Nux Misc
#  baseurl=http://li.nux.ro/download/nux/misc/el6/i386/
#  enabled=0
#  gpgcheck=1
#  gpgkey=http://li.nux.ro/download/nux/RPM-GPG-KEY-nux.ro
# Install macchanger rpm package:
#  yum --enablerepo=nux-misc install macchanger
[ $(ifconfig | grep ham | grep HWaddr | cut -d "r" -f3) == "$1" ] && \
ifconfig ham0 down && macchanger -r ham0 && ifconfig ham0 up && ifconfig