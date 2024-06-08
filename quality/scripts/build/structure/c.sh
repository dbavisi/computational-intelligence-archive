#!/bin/bash

# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# @header Script for building libraries for data structures implemented in C.

INCLUDE="include/headers/c/"
echo "Global include path: ${INCLUDE}"

BUILD=".build/lib/c/"
echo "Global build path: ${BUILD}"

echo "Removing existing libraries inside build directory"
rm -rf "${BUILD}"
mkdir -p "${BUILD}"

echo "Enumerating list of data structures..."
structures=(`ls -d structure/* | cut -d'/' -f2`)
echo "Retrieved list of data structures: ${structures[@]}"

for structure in "${structures[@]}"
do
  echo "Enumerating implementations for ${structure}..."
  implementations=(`ls -d structure/${structure}/* | cut -d'/' -f3`)
  echo "Retrieved list of implementations: ${implementations[@]}"

  for implementation in "${implementations[@]}"
  do
    directory="structure/${structure}/${implementation}/c"
    echo "Checking for C implementation in ${directory}..."
    if [ -d "${directory}" ]; then
      echo "Building library for ${structure} with ${implementation} implementation in C..."

      echo "Command: gcc -c ${directory}/lib.c -I${INCLUDE} -o lib${structure}_${implementation}_c.o"
      gcc -c "${directory}/lib.c" -I"${INCLUDE}" -o "lib${structure}_${implementation}_c.o"

      if [ -f "lib${structure}_${implementation}_c.o" ]; then
        echo "Library built successfully for ${structure} with ${implementation} implementation in C."
      else
        echo "Failed to build library for ${structure} with ${implementation} implementation in C."
      fi

      echo "Moving library to build directory..."
      mv "lib${structure}_${implementation}_c.o" "${BUILD}"
    else
      echo "No C implementation found for ${structure} with ${implementation} implementation."
    fi
  done
done

echo "Finished building libraries for data structures implemented in C."
