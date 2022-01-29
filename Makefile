#
#   Makefile
#
#   Description
#       Make tool build for MaPWaR
#
#   Author
#       Kyle Yu
#

build:
	gcc -Wall -std=c11 ./src/*.c -lSDL2 -lSDL2_ttf -o MaPWaR -I ./include

run:
	./MaPWaR

clean:
	rm MaPWaR

