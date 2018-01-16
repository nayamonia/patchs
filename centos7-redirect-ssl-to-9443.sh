#!/bin/bash
# Permanent redirect 443 to 9443 on CentOS Linux release 7.3.1611 (Core)
# Author: Gabriel Fernandes - gabriel@cd2.com.br
iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 443 -j REDIRECT --to-port 9443
service iptables save
service iptables restart
