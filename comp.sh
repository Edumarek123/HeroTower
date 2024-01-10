#!/bin/bash

clear

g++ -o model client.cpp src/Base/Vector2D/Vector2D.cpp src/Client/Sprite/Sprite.cpp src/Base/Entity/Entity.cpp src/Hero/Hero.cpp src/Client/PlayerController/PlayerController.cpp -m64 -g -I "include" -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_image

./model
# valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./model
