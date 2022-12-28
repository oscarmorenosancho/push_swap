ARGPS=$(cat $1);
#echo ${ARGPS};
./push_swap $(echo ${ARGPS}) | ./checker_Mac $(echo ${ARGPS})
