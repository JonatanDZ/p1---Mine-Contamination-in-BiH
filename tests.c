#include "header.h"

void testMapWFile();
void testNumberToEnum();

int main() {
    testMapWFile();
    testNumberToEnum();

}

void testMapWFile(){
    // Arrange
    int maph[MAPSIZEROW][MAPSIZECOL];
    int mapf[MAPSIZEROW][MAPSIZECOL];

    // Act
    createMap(maph);
    createMapWFile(mapf);

    // Assert
    assert(
        for(int i = 0; i < MAPSIZEROW; i++) {
            for(int j = 0; j < MAPSIZECOL; j++) {
                maph[i][j] == mapf[i][j];
            }
        }
    );
}

void testNumberToEnum() {
    // Arrange
    int map[5][5] = {
        {167, 247, 223, 202, 173},
        {216, 133, 142, 00, 01},
        {69, 123, 100, 1828, 12},
        {58, 2910, 471, 849, 188},
        {93, 189, 5678, 9786, 37737}
    };

    // Act
    fromNumberToEnum(map);

    // Assert
    assert(map[0][0] == mine);
    assert(map[0][3] == city);
    assert(map[1][1] == mountain1);
    assert(map[4][4] == 150);
}