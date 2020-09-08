
search_files=`ls /scratch/snyder/s/sferdou/try_1/mtxs/*.mtx`
b=10
nrun=1
out_prefix="/scratch/snyder/s/sferdou/try_1/sparse/b_10/"
for entry in $search_files
do
  ./exe/lazygreedy.out $entry $out_prefix $nrun $b
done


