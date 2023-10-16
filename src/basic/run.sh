if [ -e "./bin/main" ]; then
  rm ./bin/main
fi
g++ ./main/main.cpp -o ./bin/main
if [ $? -eq 0 ]; then
  ./bin/main 
fi 
  