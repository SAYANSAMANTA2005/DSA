#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
///#include <unistd.h>  // for usleep (POSIX)

using namespace std;

// Container dimensions
const double WIDTH = 100.0;
const double HEIGHT = 10.0;

// Time step for simulation
const double dt = 0.1;
const double EPS = 1e-6;

struct Particle {
    double x, y;      // position
    double vx, vy;    // velocity
    double radius;    
    double mass;
    bool special;     // special particle flag
};

void updatePosition(Particle &p) {
    p.x += p.vx * dt;
    p.y += p.vy * dt;
}

void checkWallCollision(Particle &p) {
    // Left wall
    if (p.x - p.radius < 0) {
        p.x = p.radius;
        p.vx = -p.vx;
    }
    // Right wall
    if (p.x + p.radius > WIDTH) {
        p.x = WIDTH - p.radius;
        p.vx = -p.vx;
    }
    // Top wall
    if (p.y - p.radius < 0) {
        p.y = p.radius;
        p.vy = -p.vy;
    }
    // Bottom wall
    if (p.y + p.radius > HEIGHT) {
        p.y = HEIGHT - p.radius;
        p.vy = -p.vy;
    }
}

void resolveCollision(Particle &p1, Particle &p2) {
    // Compute distance between particle centers
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dist = sqrt(dx * dx + dy * dy);
    if(dist < EPS)
        return; // avoid division by zero

    // Normal vector
    double nx = dx / dist;
    double ny = dy / dist;

    // Relative velocity
    double dvx = p1.vx - p2.vx;
    double dvy = p1.vy - p2.vy;

    // Relative velocity in direction of normal
    double relVel = dvx * nx + dvy * ny;

    // If particles are moving apart, no collision
    if(relVel > 0)
        return;

    // Coefficient of restitution (1.0 for elastic collision)
    double e = 1.0;

    // Impulse scalar
    double j = -(1 + e) * relVel;
    j /= (1 / p1.mass + 1 / p2.mass);

    // Impulse vector
    double impulseX = j * nx;
    double impulseY = j * ny;

    // Update velocities
    p1.vx += impulseX / p1.mass;
    p1.vy += impulseY / p1.mass;
    p2.vx -= impulseX / p2.mass;
    p2.vy -= impulseY / p2.mass;

    // Adjust positions to resolve overlap
    double overlap = 0.5 * (p1.radius + p2.radius - dist + EPS);
    p1.x -= overlap * nx;
    p1.y -= overlap * ny;
    p2.x += overlap * nx;
    p2.y += overlap * ny;
}

// Draw the current frame in the console.
// The container boundaries are drawn as a box, and each particle is represented by "*" or "A" if special.
void drawFrame(const vector<Particle>& particles) {
    // Create a grid (vector of strings) representing the container.
    vector<string> grid(int(HEIGHT), string(int(WIDTH), ' '));

    // Draw top and bottom boundaries.
    for (int i = 0; i < int(WIDTH); i++) {
        grid[0][i] = '-';
        grid[int(HEIGHT)-1][i] = '-';
    }
    // Draw left and right boundaries.
    for (int i = 0; i < int(HEIGHT); i++) {
        grid[i][0] = '|';
        grid[i][int(WIDTH)-1] = '|';
    }
    // Draw corners.
    grid[0][0] = '+';
    grid[0][int(WIDTH)-1] = '+';
    grid[int(HEIGHT)-1][0] = '+';
    grid[int(HEIGHT)-1][int(WIDTH)-1] = '+';

    // Place particles into the grid.
    for (const auto &p : particles) {
        int col = int(round(p.x));
        int row = int(round(p.y));
        if (row > 0 && row < int(HEIGHT)-1 && col > 0 && col < int(WIDTH)-1) {
            // Use "A" if special, otherwise "*"
            grid[row][col] = p.special ? 'A' : '*';
        }
    }

    // Print the grid.
    for (const auto &line : grid)
        cout << line << "\n";
}

int main() {
    // Number of particles
    const int numParticles = 10;
    vector<Particle> particles(numParticles);

    srand(time(NULL));

    // Initialize particles with random positions and velocities.
    // Mark one particle (index 0) as special.
    for (int i = 0; i < numParticles; i++) {
        Particle p;
        // Use a small radius for text-based representation.
        p.radius = 1.0;
        p.mass = p.radius; // Mass proportional to radius.
        p.x = p.radius + rand() % (int(WIDTH - 2 * p.radius));
        p.y = p.radius + rand() % (int(HEIGHT - 2 * p.radius));
        p.vx = (rand() % 200 - 100) / 50.0;
        p.vy = (rand() % 200 - 100) / 50.0;
        // Mark particle 0 as special; others are ordinary.
        p.special = (i == 0);
        particles[i] = p;
    }

    // Run simulation for a fixed number of steps.
    const int steps = 1000;
    for (int step = 0; step < steps; step++) {
        // Clear the console (use "CLS" on Windows).
        ///system("clear");

        // Update each particle's position and handle wall collisions.
        for (auto &p : particles) {
            updatePosition(p);
            checkWallCollision(p);
        }

        // Check and resolve collisions between particles.
        for (size_t i = 0; i < particles.size(); i++) {
            for (size_t j = i + 1; j < particles.size(); j++) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double distance = sqrt(dx * dx + dy * dy);
                if (distance < particles[i].radius + particles[j].radius) {
                    resolveCollision(particles[i], particles[j]);
                }
            }
        }

        // Draw the current frame.
        ///if(step%10==0)
        drawFrame(particles);

        // Pause briefly so the frame is visible.
       /// usleep(100000); // 100 ms pause
    }
    return 0;
}