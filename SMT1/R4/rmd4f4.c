#include <stdio.h>
#include <string.h>

#define STRLEN_NAME 32
#define STRLEN_CMD 16
#define MAX_ISLAND 50
#define MAX_FARM 5

struct Farm {
    char farmName[STRLEN_NAME];
    int farmRate;
};

struct Island {
    char islandName[STRLEN_NAME];
    int islandX, islandZ;
};



int main() {
    char command[1e9][STRLEN_CMD];

    
}