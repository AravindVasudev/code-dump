# Export pin to userspace
echo "18" > /sys/class/gpio/export
echo "21" > /sys/class/gpio/export

# Set pin mode
echo "in" > /sys/class/gpio/gpio18/direction
echo "out" > /sys/class/gpio/gpio21/direction

while true
do
	# read pin
	read -r motion < /sys/class/gpio/gpio18/value
	echo $motion # print motion value

	# if motion is detected, buzzer on
	if [ $motion -eq 1 ]
	then
		echo "1" > /sys/class/gpio/gpio21/value
	else
		echo "0" > /sys/class/gpio/gpio21/value
	fi

	sleep 1
done
