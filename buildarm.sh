#!/bin/sh
source /opt/FriendlyARM/arm-qtopia/qtopia-2.2.0-FriendlyARM/setQpeEnv
qmake -spec qws/linux-arm-g++ -o Makefile.target *.pro 
make -f Makefile.target clean
make -f Makefile.target
