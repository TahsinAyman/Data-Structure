if [ -e "./bin/main.out" ]; then
  rm ./bin/main.out
fi
g++ ./main/main.cpp -o ./bin/main.out
if [ $? -eq 0 ]; then
  ./bin/main.out
fi 
  