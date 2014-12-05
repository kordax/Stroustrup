#!/bin/bash

server=$(beget user $acc | grep Server | awk '{ print $4 }');
password=$(beget info $acc | grep -a2 Login | grep $acc | awk '{ print $6 }');
sitedir=$(beget info $acc | grep Y | grep $domain | awk '{ print $6 }');

if [$1==''];
then echo "No arguments" exit;
fi

sitedir="~/$1/public_html";
echo $sitedir;

file="$sitedir/wp-admin/includes/file.php"

if [ ! -d "$sitedir" ]; then
echo "Err: Directory $sitedir doesn't exist!";
fi
if [ ! -f "$file" ]; then
echo "Err: File $file doesn't exist!";
else sed -e "s#FS_CHMOD_FILE#0744#g" -i $file;
echo "$file was successfully seded! FS_CHMOD_FILE changed to 0744";
fi
