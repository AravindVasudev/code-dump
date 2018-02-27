read expr
printf "%.3f" $(echo "scale=4;$expr" | bc)
