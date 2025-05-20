@echo off
setlocal
set EXE=MergeSortParallel2.exe


set OMP_NUM_THREADS=8


echo > results.txt

for /L %%i in (1,1,10) do (
    echo Running data%%i.txt >> results.txt
    echo Running data%%i.txt
    set OMP_NUM_THREADS=8
    %EXE% data%%i.txt >> results.txt
    echo. >> results.txt
)

echo Toate rularile au fost salvate in results.txt
endlocal
pause
