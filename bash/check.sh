#!/usr/bin/bash
while read line
do
if [ -f "$line" ]; then
echo -e "File $line exists! \n";
fi
done < files.txt

