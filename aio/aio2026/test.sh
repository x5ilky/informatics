for ((i = 0; i < 100000; i++)); do
    python3 ./gen.py > tc
    ./f < tc > o1
    ./f2 < tc > o2
    head -1 o1 > o1r
    head -1 o2 > o2r
    if diff o1r o2r; then
        printf "TEST CASE $i GOOD\n"
    else
        printf "TEST CASE $i BAD\n"
        exit 1
    fi
done
