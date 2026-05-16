for ((i = 0; i < 10; i++)); do
    python3 test.py > "case$i"
    ./bike < "case$i" > "out$i"
done
