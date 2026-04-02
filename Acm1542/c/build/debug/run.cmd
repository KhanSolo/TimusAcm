@echo off
setlocal

:: Путь к программе
set APP="acm1542.exe"

:: Файлы вход/выход/ожидаемый результат
set INPUT=input.txt
set OUTPUT=actual.txt

:: Запуск программы: вход из файла, вывод в файл
echo Start Time: %time%
%APP% < "%INPUT%" > "%OUTPUT%" 2>&1
echo End Time: %time%

endlocal