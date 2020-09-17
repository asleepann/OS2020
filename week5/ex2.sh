x=0
while [[ $x -lt 100 ]] # 100 iterations
do
    x=$( tail -n1 ex2.txt ) # read the last number in ex2.txt
    x=$(( $x + 1 )) # increase this number by 1
    echo "$x" >> ex2.txt # write new number in file
done

# A race condition manifested itself in the second run of the script.
# Critical region in our case is ex2.txt.