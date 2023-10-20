#include <iostream>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846
namespace Physics {
    const double GRAVITY = 9.81;
    const double TIME_INTERVAL = 0.1;

    // Calculate the projectile's position at a given time
    void calculateProjectilePosition(double initialVelocity, double angleInDegrees, double &x, double &y, double time) {
        double angleInRadians = angleInDegrees * M_PI / 180.0;
        x = initialVelocity * cos(angleInRadians) * time;
        y = initialVelocity * sin(angleInRadians) * time - (0.5 * GRAVITY * pow(time, 2));
    }
}

int main() {
    using namespace Physics;
    double initialVelocity, angleInDegrees, distance;

    cout << "Enter the initial velocity (m/s): ";
    cin >> initialVelocity;
    cout << "Enter the launch angle (degrees): ";
    cin >> angleInDegrees;
    cout << "Enter the desired distance (m): ";
    cin >> distance;

    double x, y;
    double time = 0.0;

    cout << "\nProjectile motion for given inputs:\n";
    cout << "Time (s)\tX Position (m)\tY Position (m)\n";

    while (x < distance) {
        calculateProjectilePosition(initialVelocity, angleInDegrees, x, y, time);
        cout << time << "\t\t" << x << "\t\t" << y << "\n";
        time += TIME_INTERVAL;
    }

    cout << "\nProjectile reached the desired distance of " << distance << " meters.\n";

    return 0;
}

