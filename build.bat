@echo off
echo Building GradeCore...
g++ -std=c++17 -Wall -o gradecore.exe main.cpp Student.cpp Course.cpp
if %errorlevel% neq 0 (
    echo Build failed.
    pause
    exit /b 1
)
echo Build successful. Run gradecore.exe to start.
pause
