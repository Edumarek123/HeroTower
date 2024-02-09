#!/bin/bash

target="../SERVER/"
src="src/Base/"
path=$target$src

#remove arquivos
rm -rf $path

#cria diretorio Base
if [ ! -d $path ]; then mkdir $path; fi

#cria diretorios dos modulos
for module in $(ls src/Base/)
do
if [ ! -d $path$module ]; then mkdir $path$module; fi
done

#copia modulos
for module in $(find -type f -regex "./src/Base/.*\.cpp")
do
cp $module "../SERVER/"$module
done

for module in $(find -type f -regex "./src/Base/.*\.hpp")
do
cp $module "../SERVER/"$module
done

for module in $(find -type f -regex "./src/Base/.*\.o")
do
cp $module "../SERVER/"$module
done

echo Files sent to SERVER directory
