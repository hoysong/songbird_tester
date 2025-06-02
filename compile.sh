clear
clang -g -o push_swap *.c ./my_libft/libft.a
VALG="valgrind"

#./push_swap 4 3 2 1111111111 > hi.txt
#open .
arg="1 2 3 4 5"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 3 2 4 5"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 3 4 2 5"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 3 4 5 2"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 2 4 3 5"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 2 4 5 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 2 4 5 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 4 2 5 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 3 2 5 4"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 2 1 5 4"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 1 2 5 4"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 1 5 4 2"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 2 5 4 1"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 2 4 5 1"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 4 2 5 1"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="3 4 1 5 2"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="2 4 1 5 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="2 4 5 1 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="4 1 5 2 3"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="4 3 5 2 1"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 5 3 2 4"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

arg="1 5 3 2 4"
echo "num: $arg"
$VALG ./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg

