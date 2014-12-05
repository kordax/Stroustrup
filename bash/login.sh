while read acc;
do
serv=$(beget user $acc | grep  Server | awk '{ print $4 }');
pass=$(beget info $acc | grep -a2 Login | grep $acc | awk '{ print $6 }');
beget ssh "$acc" --toggle-ssh=Y
echo $serv $acc $pass ;
expect -c "set acc $acc; set serv $serv; set pass $pass" -f expected.txt
done < accaunts
