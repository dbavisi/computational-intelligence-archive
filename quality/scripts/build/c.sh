#!/bin/bash

# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Build script for CIA library implemented in C

GLOBAL_INCLUDE="-Iinclude/headers/c/ -I./"
echo "Global include path: ${GLOBAL_INCLUDE}"

BUILD=".build"
echo "Global build path: ${BUILD}"

echo "Removing old build artifacts..."
rm -rf ${BUILD}
mkdir -p ${BUILD}

DATA_STRUCTURE_LIB_SRC="structure/%s/implementations/%s/c/"
DATA_STRUCTURE_LIB_ARTIFACTS="${BUILD}/structure/%s/implementations/%s/c/"

DATA_STRUCTURE_QUALITY_SUITE_SRC="structure/%s/quality/c/"
DATA_STRUCTURE_QUALITY_SUITE_ARTIFACTS="${BUILD}/structure/%s/quality/c/"

echo "Building CIA library implemented in C..."
echo "Enumerating data structures..."
DS=(`cd structure && ls -d */ | cut -f1 -d'/'`)
for ds in "${DS[@]}"
do
  echo "> Enumerating implementations for ${ds}..."
  IMPL=(`cd structure/${ds}/implementations && ls -d */ | cut -f1 -d'/'`)
  for impl in "${IMPL[@]}"
  do
    echo "> > Checking for ${impl} implementation of ${ds} in C..."

    LIB_SRC_PATH=$(printf ${DATA_STRUCTURE_LIB_SRC} ${ds} ${impl})
    if [ -d "${LIB_SRC_PATH}" ]; then
      echo "> > > Building ${impl} implementation of ${ds} in C..."
      LIB_ARTIFACTS=$(printf ${DATA_STRUCTURE_LIB_ARTIFACTS} ${ds} ${impl})
      mkdir -p ${LIB_ARTIFACTS}

      echo "> > > Compiling ${impl} implementation of ${ds} in C..."
      LIB_SRC=${LIB_SRC_PATH}*.c
      gcc -c ${GLOBAL_INCLUDE} ${LIB_SRC} -o ${LIB_ARTIFACTS}${ds}_${impl}.o
    else
      echo "> > > No C implementation found for ${impl} implementation of ${ds}"
    fi

    echo "> > Checking for quality suite for ${ds} in C..."
    QUALITY_SUITE_SRC_PATH=$(printf ${DATA_STRUCTURE_QUALITY_SUITE_SRC} ${ds})
    if [ -d "${QUALITY_SUITE_SRC_PATH}" ]; then
      echo "> > > > Building quality suite for ${impl} implementation of ${ds} in C..."
      QUALITY_SUITE_ARTIFACTS=$(printf ${DATA_STRUCTURE_QUALITY_SUITE_ARTIFACTS} ${ds})
      mkdir -p ${QUALITY_SUITE_ARTIFACTS}

      echo "> > > > Compiling quality suite for ${ds} in C..."
      QUALITY_SUITE_SRC=${QUALITY_SUITE_SRC_PATH}*.c
      gcc ${GLOBAL_INCLUDE} ${QUALITY_SUITE_SRC} ${LIB_ARTIFACTS}${ds}_${impl}.o -o ${QUALITY_SUITE_ARTIFACTS}${ds}_${impl}_quality_suite.out
    else
      echo "> > > > No quality suite found for ${ds} in C"
    fi
  done
done
