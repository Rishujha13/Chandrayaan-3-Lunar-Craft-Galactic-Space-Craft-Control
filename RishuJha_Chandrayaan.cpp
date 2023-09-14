/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <tuple>
#include <string>

using namespace std;

class GalacticSpaceCraft {
private:
    int x, y, z;
    char direction;

public:
    GalacticSpaceCraft(int x, int y, int z, char direction) : x(x), y(y), z(z), direction(direction) {}

    void move_forward() {
        switch (direction) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
            case 'U': z++; break;
            case 'D': z--; break;
        }
    }

    void move_backward() {
        switch (direction) {
            case 'N': y--; break;
            case 'S': y++; break;
            case 'E': x--; break;
            case 'W': x++; break;
            case 'U': z--; break;
            case 'D': z++; break;
        }
    }

    void turn_left() {
        switch (direction) {
            case 'N': direction = 'W'; break;
            case 'S': direction = 'E'; break;
            case 'E': direction = 'N'; break;
            case 'W': direction = 'S'; break;
        }
    }

    void turn_right() {
        switch (direction) {
            case 'N': direction = 'E'; break;
            case 'S': direction = 'W'; break;
            case 'E': direction = 'S'; break;
            case 'W': direction = 'N'; break;
        }
    }

    void turn_up() {
        if (direction != 'U') direction = 'U';
    }

    void turn_down() {
        if (direction != 'D') direction = 'D';
    }

    void execute_commands(const string& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f': move_forward(); break;
                case 'b': move_backward(); break;
                case 'l': turn_left(); break;
                case 'r': turn_right(); break;
                case 'u': turn_up(); break;
                case 'd': turn_down(); break;
            }
        }
    }

    tuple<int, int, int> get_position() const {
        return make_tuple(x, y, z);
    }

    char get_direction() const {
        return direction;
    }
};

int main() {
    int starting_x, starting_y, starting_z;
    char initial_direction;
    string commands;

    cout << "Enter starting X coordinate: ";
    cin >> starting_x;
    cout << "Enter starting Y coordinate: ";
    cin >> starting_y;
    cout << "Enter starting Z coordinate: ";
    cin >> starting_z;
    cout << "Enter initial direction (N, S, E, W, U, D): ";
    cin >> initial_direction;
    cout << "Enter commands: ";
    cin >> commands;

    GalacticSpaceCraft spacecraft(starting_x, starting_y, starting_z, initial_direction);
    spacecraft.execute_commands(commands);

    auto final_position = spacecraft.get_position();
    char final_direction = spacecraft.get_direction();

    cout << "Final Position: (" << get<0>(final_position) << ", "
         << get<1>(final_position) << ", " << get<2>(final_position) << ")\n";
    cout << "Final Direction: " << final_direction << endl;

    return 0;
}
