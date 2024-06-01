g++ -o out.exe main.cpp -I include\SDL2 -LC:\SDL2\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2
pause
if %errorlevel% equ 0 (out.exe)
