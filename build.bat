@echo off

echo Copiado en curso

copy %1 %2 /Y

cd %2

mkdir res

cd res

mkdir assets

cd assets

xcopy %3res\assets %2res\assets /s /Y

echo Finalizando el copiado