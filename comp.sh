#!/bin/bash

clear

g++ -o model client.cpp src/Base/Vector2D/Vector2D.cpp src/Client/Sprite/Sprite.cpp src/Base/Hero/Hero.cpp src/Client/HeroSprite/HeroSprite.cpp src/Base/Entity/Entity.cpp src/Client/PlayerController/PlayerController.cpp  src/Client/HeroClient/HeroClient.cpp src/Base/StateMachine/StateMachine.cpp src/Base/State/State.cpp src/Base/IdleState/IdleState.cpp src/Base/RunState/RunState.cpp -m64 -g -I "include" -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_image

./model
# valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./model
