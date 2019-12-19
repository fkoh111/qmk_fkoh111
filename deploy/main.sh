#!/bin/bash
path_to_qmk_fkoh111=${PWD%/*}
path_to_scripts=`dirname $path_to_qmk_fkoh111`

echo $path_to_qmk_fkoh111
echo $path_to_scripts

src_dir=$path_to_scripts"/qmk_firmware/keyboards/ergodox_ez/keymaps/fkoh111_default"
src_ext="*.c"
src_dst="/home/frederik/Documents/scripts/qmk_fkoh111/src"

bin_dir="/home/frederik/Documents/scripts/qmk_firmware"
bin_ext="*.hex"
bin_dst="/home/frederik/Documents/scripts/qmk_fkoh111/bin"

git_dir="/home/frederik/Documents/scripts/qmk_fkoh111/deploy"


cd $src_dir
for file in $src_ext; do
  cp $src_ext $src_dst;
done

cd $bin_dir
for file in $bin_ext; do
  cp $bin_ext $bin_dst;
done



cd $git_dir
source push.sh