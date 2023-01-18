#! /bin/bash

echo " SDL2, SDL2_image, SDL2_ttf, g++ and make  will be installed"

sudo apt update && sudo apt upgrade

sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-ttf-dev

sudo apt install g++
sudo apt install make
