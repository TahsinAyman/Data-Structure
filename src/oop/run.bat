if exist ".\bin\main.out" (
    del ".\bin\main.out"
)
g++ .\main\main.cpp -o .\bin\main.out
if %ERRORLEVEL% == 0 (
    .\bin\main.out
)