#!/bin/bash

# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Script to execute test suites for CIA library implemented in C

BUILD=".build"
echo "Global build path: ${BUILD}"

echo "Enumerating data structures..."
DS=(`cd ${BUILD}/structure && ls -d */ | cut -f1 -d'/'`)
for ds in "${DS[@]}"
do
  echo "> Checking for quality suites for ${ds}..."
  if [ ! -d "${BUILD}/structure/${ds}/quality/c/" ]; then
    echo "> > No quality suites found for ${ds}"
    continue
  fi

  echo "> > Enumerating quality suites for ${ds}..."
  QS=(`cd ${BUILD}/structure/${ds}/quality/c/ && ls *.out`)
  for qs in "${QS[@]}"
  do
    echo "> > > Running quality suite ${qs}..."
    chmod +x ${BUILD}/structure/${ds}/quality/c/${qs}
    ./${BUILD}/structure/${ds}/quality/c/${qs}
  done

  echo "> Finished running quality suites for ${ds}"
  echo ""
done
