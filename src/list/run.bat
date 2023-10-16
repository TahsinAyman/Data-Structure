if exist ".\bin\main" (
    del ".\bin\main"
)
g++ .\main\main.cpp -o .\bin\main
if %ERRORLEVEL% == 0 (
    .\bin\main
)