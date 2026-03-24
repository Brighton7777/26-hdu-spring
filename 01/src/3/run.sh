g++ -O2 gen.cpp -o gen
g++ -O2 3.cpp -o brute
g++ -O2 std.cpp -o std

while true; do
    ./gen > input.txt
    ./brute < input.txt > out1.txt
    ./std < input.txt > out2.txt

    if diff out1.txt out2.txt; then
        echo "OK"
    else
        echo "WA!"
        cat input.txt
        cat out1.txt
        cat out2.txt
        break
    fi
done