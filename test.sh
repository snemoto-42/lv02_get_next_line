# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 09:39:02 by snemoto           #+#    #+#              #
#    Updated: 2023/03/15 01:42:41 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#stackoverflow
#INT_MAX
# for VAL in `seq 1 +1 6`
for VAL in 1 2 4 7 10 20 30 50 100 1000 10000 100000 1000000 9400001 10000000 2147483646 2147483647
# for VAL in 2147483648
do
echo ---MANDATORY------
echo ---BUFFER_SIZE=$VAL------
# gcc	-Wall -Wextra -Werror -D BUFFER_SIZE=$VAL \
gcc	-Wall -Wextra -Werror -D BUFFER_SIZE=$VAL -fsanitize=address \
			get_next_line.c \
			get_next_line_utils.c \
			main.c \
			-o gnl
echo ------------test00--------------
./gnl test00.txt > gnl.txt
diff -a --suppress-common-lines gnl.txt test00.txt
echo ------------test01--------------
./gnl test01.txt > gnl01.txt
diff -a --suppress-common-lines gnl01.txt test01.txt
echo ------------test02--------------
./gnl test02.txt > gnl02.txt
diff -a --suppress-common-lines gnl02.txt test02.txt
echo ------------test03--------------
./gnl test03.txt > gnl03.txt
diff -a --suppress-common-lines gnl03.txt test03.txt
done
make fclean
rm -f gnl.txt gnl01.txt gnl02.txt gnl03.txt

# for VAL in 1 2 4 7 10 20 30 50 100 1000 10000 100000 1000000 9400001 10000000 2147483647
# do
# echo ---BONUS------
# echo ---BUFFER_SIZE=$VAL------
# # gcc	-Wall -Wextra -Werror -D BUFFER_SIZE=$VAL -fsanitize=address \
# gcc	-Wall -Wextra -Werror -D BUFFER_SIZE=$VAL \
# 			get_next_line_bonus.c \
# 			get_next_line_utils_bonus.c \
# 			main.c \
# 			-o gnl
# echo ------------test00--------------
# ./gnl test00.txt > gnl.txt
# diff -a --suppress-common-lines gnl.txt test00.txt
# echo ------------test01--------------
# ./gnl test01.txt > gnl01.txt
# diff -a --suppress-common-lines gnl01.txt test01.txt
# echo ------------test02--------------
# ./gnl test02.txt > gnl02.txt
# diff -a --suppress-common-lines gnl02.txt test02.txt
# echo ------------test03--------------
# ./gnl test03.txt > gnl03.txt
# diff -a --suppress-common-lines gnl03.txt test03.txt
# done
# make fclean
# rm -f gnl.txt gnl01.txt gnl02.txt gnl03.txt
