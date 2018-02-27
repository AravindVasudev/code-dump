read X
X=$(echo $X | awk '{print tolower($0)}')

if [ $X == 'y' ]
then
    echo "YES"
else
    echo "NO"
fi
