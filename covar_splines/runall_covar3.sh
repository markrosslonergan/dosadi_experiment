#!/bin/bash

while read p; do
  mkdir -p data/$p
  sed "s/XXX/$p/g" build_uboone_covar_template.xml.xml > data/$p/build_uboone_covar_template_$p.xml
  cp build_uboone_covar data/$p/
  cd data/$p/
  ./build_uboone_covar --xml build_uboone_covar_template_$p.xml > log.log
  cd ../../
done < syst3.txt
