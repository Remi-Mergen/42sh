make all

# if [[ $? == "0" ]]
# then
    clear
    mv mysh tester
    cd tester
    ./tester.sh | grep KO
    echo "-----------------------------"
    ./tester.sh | grep OK
    cd ..
# fi
