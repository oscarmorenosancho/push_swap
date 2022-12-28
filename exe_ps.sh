ARGPS=$(cat $1);
#echo ${ARGPS};
#leaks -atExit -- 
./push_swap $(echo ${ARGPS})
