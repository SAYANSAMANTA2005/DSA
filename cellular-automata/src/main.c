#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for usleep

#define WIDTH 20
#define HEIGHT 10

#define ALIVE 'O'
#define DEAD  ' '

void initialize_grid(char grid[HEIGHT][WIDTH]) {
    // Initialize all cells to DEAD
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = DEAD;
        }
    }

    // Cgrid[1][2reate an initial pattern (e.g., a glider)
     grid[1] [2]= ALIVE;
    grid[2][3] = ALIVE;
    grid[3][1] = ALIVE;
    grid[3][2] = ALIVE;
    grid[3][3] = ALIVE;
    
}

void display_grid(char grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c",grid[y][x]);
        }
            printf("\n");
    }
}

int count_alive_neighbors(char grid[HEIGHT][WIDTH], int y, int x) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) continue; // Skip the cell itself
            int ny = y + dy;
            int nx = x + dx;
            if (ny >= 0 && ny < HEIGHT && nx >= 0 && nx < WIDTH && grid[ny][nx] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void update_grid(char grid[HEIGHT][WIDTH]) {
    char new_grid[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int alive_neighbors = count_alive_neighbors(grid, y, x);

            if (grid[y][x] == ALIVE) {//if grid was alive in previous generation 
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    new_grid[y][x] = DEAD;
                } else {
                    new_grid[y][x] = ALIVE;
                }
            } else {// if the grid is not alive in previous generation 
                if (alive_neighbors == 3) {
                    new_grid[y][x] = ALIVE;
                } else {
                    new_grid[y][x] = DEAD;
                }
            }
        }
    }

    // Copy new_grid to grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

int main() {
    char grid[HEIGHT][WIDTH];
    initialize_grid(grid);

    while (1) {
        system("clear");
        update_grid(grid);
        display_grid(grid);
      //  update_grid(grid);
        usleep(200000); // Sleep for 200ms
    }

    return 0;
}