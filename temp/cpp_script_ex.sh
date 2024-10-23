#!/bin/bash
mkdir "ex$1"
cd "ex$1"

echo -n \
'CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp' > Makefile

touch main.cpp
echo "#include <iostream>" >> main.cpp

skip=1
for i;
do
if [ $skip = 1 ]
then
	skip=0
else
	nn=$i
	un=$(echo -n $nn | tr '[a-z]' '[A-Z]')
	sed -e "s/Interface/$nn/g" -e "s/INTERFACE/$un/g" '/Users/ehammoud/Desktop/Templates/Interface.cpp' > "$nn.cpp"
	sed -e "s/Interface/$nn/g" -e "s/INTERFACE/$un/g" '/Users/ehammoud/Desktop/Templates/Interface.hpp' > "$nn.hpp"
	echo "#include \"$nn.hpp\"" >> main.cpp
	echo -n " $nn.cpp" >> Makefile
fi
done

echo \
'
OBJS = $(SRCS:.cpp=.o)
NAME = execute

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re' >> Makefile

echo \
'
int main()
{

	return (0);
}' >> main.cpp