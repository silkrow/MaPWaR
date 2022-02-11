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
	gcc -Wall -std=c11 ./src/*.c -lSDL2 -lSDL2_ttf -lSDL2_image -o MaPWaR -I ./include -lm

run:
	./MaPWaR

clean:
	rm MaPWaR

