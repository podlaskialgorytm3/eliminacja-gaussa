@echo off
rem Tworzenie folderu 'bin', jeśli nie istnieje
if not exist bin (
    mkdir bin
)

rem Tworzenie listy plików .c
setlocal EnableDelayedExpansion
set "sources="
for %%f in (src\*.c) do (
    set "sources=!sources! %%f"
)
endlocal & set "sources=%sources%"

rem Kompilacja programu
gcc -Wall --pedantic %sources% -o bin\gauss

if %ERRORLEVEL% neq 0 (
    echo Kompilacja nie powiodła się.
    exit /b %ERRORLEVEL%
)

echo Kompilacja zakończona sukcesem.

rem Uruchamianie programu z argumentami
bin\gauss dane\A dane\b

if %ERRORLEVEL% neq 0 (
    echo Wystąpił błąd podczas uruchamiania programu.
    exit /b %ERRORLEVEL%
)

echo Program zakończył działanie.
