#/bin/sh

case $SHELL in
	*bash)
		ECHO='echo -e'
		;;
	*)
		ECHO='echo'
		;;
esac

white="\033[1;37m"
red="\033[1;31m"
green="\033[1;32m"
yellow="\033[1;33m"
blue="\033[1;34m"
transparent="\e[0m"

clear; ${ECHO} ""

${ECHO} ""
sleep 0.2 && ${ECHO}" _____        _  _         _____  _            _                   _ "
sleep 0.2 && ${ECHO}"|  ___|_   _ | || |       |  ___|| |  ___   __| |  __ _   ___   __| |"
sleep 0.2 && ${ECHO}"| |_  | | | || || | _____ | |_   | | / _ \ / _` | / _` | / _ \ / _` |"
sleep 0.2 && ${ECHO}"|  _| | |_| || || ||_____||  _|  | ||  __/| (_| || (_| ||  __/| (_| |"
sleep 0.2 && ${ECHO}"|_|    \__,_||_||_|       |_|    |_| \___| \__,_| \__, | \___| \__,_|"
sleep 0.2 && ${ECHO}"                                                  |___/              "
sleep 0.2 && ${ECHO}" ____   _            _  _  "
sleep 0.2 && ${ECHO}"/ ___| | |__    ___ | || | "
sleep 0.2 && ${ECHO}"\___ \ | '_ \  / _ \| || | "
sleep 0.2 && ${ECHO}" ___) || | | ||  __/| || | "
sleep 0.2 && ${ECHO}"|____/ |_| |_| \___||_||_| "
sleep 0.2 && ${ECHO}"                           "
${ECHO} ""
sleep 0.1
sleep 0.1
${ECHO} $blue "           	      Made by:"$yellow" ("$red"Group 14"$yellow")"
sleep 0.1
${ECHO} ""
