read N

sum=0
for i in $(seq $N)
do
    read val
    let "sum+=val"
done

printf "%.3f" $(echo "scale=4;$sum / $N" | bc)
