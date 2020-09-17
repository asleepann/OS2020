x=0
while [[ $x -lt 100 ]] # 100 iterations
do
    if ln ex2_modified.txt ex2_modified.txt.lock # check if critical region is occupied
    then
        x=$( tail -n1 ex2_modified.txt ) # read the last number in ex2.txt
        x=$(( $x + 1 )) # increase this number by 1
        echo "$x" >> ex2_modified.txt # write new number in file
        rm ex2_modified.txt.lock # free critical region
    fi
done