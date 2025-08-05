all:
	g++ -I src/include/SDL2 -L src/lib -o Rock_Paper_Scissors_Game Rock_Paper_Scissors_Game.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer