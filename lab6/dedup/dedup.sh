# TODO: Write your shell script (for question 7) in this file.

if [ $# -eq 0 ];then path="."; else path="$1"; fi;

find $path -maxdepth 1 -type f -exec md5sum {} \; | sort -k1,1 -k2,2  > ../allFiles.txt
find $path -maxdepth 1 -type f -exec md5sum {} \; | sort -k1,1 -k2,2 | sort -u -k1,1 > ../originals.txt


grep -Fvxf  ../originals.txt ../allFiles.txt > ../duplicates.txt


touch ../newDuplicates.csv
touch ../new.csv
while read a b ; do (echo $a , "$b")>> ../newDuplicates.csv; done < ../duplicates.txt |sort
while read a b ; do echo $a , "$(basename "$b")">> ../new.csv; done < ../originals.txt |sort

join ../newDuplicates.csv ../new.csv > ../joined.csv


while IFS=, read -r field1 field2 field3
do
    tempv1=$(echo -e "${field2}" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//');
    tempv2=$(echo -e "${field3}" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//');
    rm "$tempv1"
    ln -s "$tempv2" "$tempv1"
    echo "$tempv1 soft-link refers to $tempv2 file"
    
done < ../joined.csv


rm ../allFiles.txt
rm ../originals.txt
rm ../duplicates.txt
rm ../new.csv
rm ../newDuplicates.csv
rm ../joined.csv

