# Lab 10 - Animated Sprite Powers

This repository contains my Lab 10 project for CPSC 440 Game Programming.

## Description

This lab uses the animated alien sprite starter code. The program displays multiple animated sprites on the screen and gives each sprite a random specialty power when it is created. The sprites move around the screen, bounce off the edges, and check for collisions with each other.

When sprites collide, they teleport to a new random location. Depending on the sprite’s randomly assigned power, the sprite may change color, shrink, spin, or freeze after a collision.

## Features

- Displays five animated sprites on the screen
- Uses multiple alien bitmap frames for animation
- Uses a Sprite class with separate .h and .cpp files
- Each sprite starts at a random position
- Each sprite moves and bounces around the screen
- Each sprite is randomly assigned one specialty power
- Collision detection checks each sprite against the other sprites
- Collision code skips the sprite that is currently being checked
- Sprites teleport to a new random location after collision

## Specialty Powers

### ScaredSprite

A ScaredSprite changes to a random color when it collides with another sprite. It stays that color until it collides again and receives a new random color.

### BabySprite

A BabySprite shrinks when it collides with another sprite. It keeps shrinking after repeated collisions. When it becomes very small, the program prints a message saying that the baby sprite died.

### SpinningSprite

A SpinningSprite rotates around its center while it animates and moves around the screen.

### FreezeSprite

A FreezeSprite stops its x and y movement for a short time after a collision, then begins moving again.

## Controls

- Escape: Close the program
- Window X button: Close the program

## Project Files

- 'Source.cpp' - Main program loop, Allegro setup, event handling, sprite array, and collision calls
- 'Sprite.h' - Sprite class definition, variables, and function declarations
- 'Sprite.cpp' - Sprite animation, drawing, movement, collision, and specialty power behavior
- 'Alien0.bmp' through 'Alien8.bmp' - Animated sprite frames

## How to Run

1. Open the project in Visual Studio.
2. Make sure Allegro is installed.
3. Make sure the Allegro image add-on is available.
4. Make sure all alien bitmap files are in the project folder.
5. Build and run the project.
6. Watch the sprites move, animate, collide, and use their special powers.

## Author

Christian Toliver
