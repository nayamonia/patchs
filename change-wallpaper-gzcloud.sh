#!/bin/bash
# Arquivo https://github.com/nayamonia/gzplanodefundo/raw/master/fundo_desktop.png
cd /usr/share/xrdp
mv gz\ cloud\ -\ fundo\ azul.png gz\ cloud\ -\ fundo\ azul.bkp.png
rm -f fundo_desktop.png
wget https://github.com/nayamonia/gzplanodefundo/raw/master/fundo_desktop.png
mv fundo_desktop.png gz\ cloud\ -\ fundo\ azul.png


