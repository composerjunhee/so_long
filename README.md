# so_long
## Overview
The aim of this project is to create a 2D game using the mlx library and UI in general. The executable "so_long" will take a map file as its only argument, which must be of the .ber filetype.
## Game Rules:
The map file must follow certain rules. 
The accepted characters for the map are P (player), 1 (wall), 0 (empty), C (collectible), and E (exit).
The map must be rectangular, with all rows having the same length. 
There must be at least one exit, one player, and one collectible on the map, and the map must be enclosed by walls. 
The player must be able to reach all collectibles and the exit using pathfinding algorithms. 
If any of these checks fail, the game must end with an "Error\n" message followed by a custom message.
## Objective:
The objective of the game is for the player(s) to collect all the collectibles on the map and then reach the exit in the least possible number of steps.
