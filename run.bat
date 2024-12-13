@echo off
rem Tworzenie folderu 'bin', jesli nie istnieje
if not exist bin (
    mkdir bin
)

rem Tworzenie listy plikow .c
setlocal EnableDelayedExpansion
set "sources="
for %%f in (src\*.c) do (
    set "sources=!sources! %%f"
)
endlocal & set "sources=%sources%"

rem Kompilacja programu
gcc -Wall --pedantic %sources% -o bin\gauss

if %ERRORLEVEL% neq 0 (
    echo Kompilacja nie powiodla sie.
    exit /b %ERRORLEVEL%
)

echo Kompilacja zakonczona sukcesem.

rem Uruchamianie programu z argumentami
bin\gauss dane\A dane\b

if %ERRORLEVEL% neq 0 (
    echo Wystapil blad podczas uruchamiania programu.
    exit /b %ERRORLEVEL%
)

echo Program zakonczyl dzialanie.
