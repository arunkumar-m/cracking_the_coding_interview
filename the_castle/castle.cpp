/*
ID: frater1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int m, n; // input size m * n
int floorplan[50][50]; // floor plan
int group[50][50]; // to indicate the group it is in
int explored[50][50]; // to indicate whether it is explored or not
int areas[2500]; // keep track of room areas
int num_rooms = 0; // number of rooms
int area = 0; // to store current room area
int largest_area = 0; // largest area

void visit(int i, int j) {
    explored[i][j] = 1;
    group[i][j] = num_rooms;
    area++;
    if ((floorplan[i][j] & 1) == 0 && explored[i][j - 1] == 0) { // go west
            visit(i, j - 1);
    }
    if ((floorplan[i][j] & 2) == 0 && explored[i - 1][j] == 0) { // go north
        visit(i - 1, j);
    }
    if ((floorplan[i][j] & 4) == 0 && explored[i][j + 1] == 0) { // go east
        visit(i, j + 1);
    }
    if ((floorplan[i][j] & 8) == 0 && explored[i + 1][j] == 0) { // go south
        visit(i + 1, j);
    }
}

void find_rooms() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (explored[i][j] == 0) {
                area = 0;
                visit(i, j);
                areas[num_rooms] = area;
                num_rooms++;
                largest_area = max(largest_area, area);
            }
        }
    }
}

int main() {
    ofstream fout("castle.out");
    ifstream fin("castle.in");
    // load data
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            explored[i][j] = 0;
            group[i][j] = 0;
            fin >> floorplan[i][j];
        }
    }
    // find all rooms
    find_rooms();
    // results
    // the number of rooms the castle has
    fout << num_rooms << endl;
    // the size of the largest room
    fout << largest_area << endl;
    // the size of the largest room creatable by removing one wall
    largest_area = 0;
    int posx = 0, posy = 0;
    char direction;
    for (int j = 0; j < n; ++j) {
            for (int i = m - 1; i >= 0; --i) {
            if (j > 0 && (floorplan[i][j] & 1) && group[i][j] != group[i][j - 1]) { // break the wall to the west
                area = areas[group[i][j]] + areas[group[i][j - 1]];
                if (area > largest_area) {
                    largest_area = area;
                    posx = i;
                    posy = j;
                    direction = 'W';
                }
            }
            if (i > 0 && (floorplan[i][j] & 2) && group[i][j] != group[i - 1][j]) { // break the wall to the north
                area = areas[group[i][j]] + areas[group[i - 1][j]];
                if (area > largest_area) {
                    largest_area = area;
                    posx = i;
                    posy = j;
                    direction = 'N';
                }
            }
            if (j < n - 1 && (floorplan[i][j] & 4) && group[i][j] != group[i][j + 1]) { // break the wall to the east
                area = areas[group[i][j]] + areas[group[i][j + 1]];
                if (area > largest_area) {
                    largest_area = area;
                    posx = i;
                    posy = j;
                    direction = 'E';
                }
            }
            if (i < m - 1 && (floorplan[i][j] & 8) && group[i][j] != group[i + 1][j]) { // break the wall to the south
                area = areas[group[i][j]] + areas[group[i + 1][j]];
                if (area > largest_area) {
                    largest_area = area;
                    posx = i;
                    posy = j;
                    direction = 'S';
                }
            }
        }
    }
    fout << largest_area << endl;
    fout << posx + 1 << " " << posy + 1 << " " << direction << endl;
    return 0;
}
