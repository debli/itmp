#!/bin/sh
/usr/bin/autoreconf -i
./configure
make
sudo cp modules/tlsp.so /usr/lib/php5/20131226/
