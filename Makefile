#all:
#	g++ -I src/include/SDL2 -L src/lib -o Rock_Paper_Scissors_Game Rock_Paper_Scissors_Game.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Build for local development
all: game # adjust 'game' to your executable name

# Package a Windows release ZIP
release: all
	mkdir -p dist
	cp game.exe SDL2.dll SDL2_image.dll SDL2_ttf.dll dist/
	cd dist && zip -r ../Rock_Paper_Scissors_Windows.zip .
