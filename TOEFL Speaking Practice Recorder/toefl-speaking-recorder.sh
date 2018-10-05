#!/bin/sh
################################################################################
# TOEFL Speaking Recorder for Linux
################################################################################

# Global colors
red="\033[0;31m"
orange="\033[0;33m"
blue="\033[0;34m"

# takes seconds as input and counts down
function countdown() {
    for (( i = $1; i > 0; i-- )); do
        printf "${red}$i \r"
        sleep 1
    done
}

# Type picker
echo "1. 15 sec practice & 45 sec speaking \n2. 30 sec practice & 60 sec speaking"
read -n1 -p "Choose: " choice
if [ "$choice" = "1" ]; then
    practice=15
    speaking=45
else
    practice=30
    speaking=60
fi

echo ""
read -p "filename to output recording: " filename

# practice countdown
printf "${orange}PRACTICE:\n"
countdown $practice

# speaking countdown with recording
printf "${blue}\nSPEAK:\n"
arecord -d "${speaking}" -f cd "${filename}" &
countdown $speaking
wait
