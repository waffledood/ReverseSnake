// Alogtherim Outline
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int xMovement (int diffX, int snakeX, int snakeY, int xCood[], int num) {
    if (diffX > 0) {
        // Means the mouse is on the left of the snake
        for (int i=1; i<=diffX; ++i) {
            snakeX -= 1;
            printf("Snake pose: %i , %i\n", snakeX, snakeY);
            //arrayX(xCood, num);
        }

    } else if (diffX < 0) {
        // Means the mouse is on the right of the snake 
        for (int i=1; i<=(-diffX); ++i) {
            snakeX += 1;
            printf("Snake pose: %i , %i\n", snakeX, snakeY);
        }
    } else {
        //means X match
        printf("X match!");
    }

    return snakeX;
}

int yMovement(int diffY, int snakeX, int snakeY,int yCood[], int num) {
    if (diffY > 0) {
        // Means the mouse is on the top of the snake 
        for (int i=1; i<=diffY; ++i) {
            snakeY -= 1;
            printf("Snake pose: %i , %i\n", snakeX, snakeY);
        }
    } else if (diffY < 0){
        // Means the mouse is on the right of the snake 
        for (int i=1; i<=(-diffY); ++i) {
            snakeY += 1;
            printf("Snake pose: %i , %i\n", snakeX, snakeY);
        }
    } else {
        // means Y match 
        printf("Y match!");
    }

    return snakeY;
}

// To generate the random starting position of the mouse and end goal of the mouse
void randLimit(int lowerLimitX, int lowerLimitY, int upperLimitX, int upperLimitY,  int* goalX, int* goalY) {
    
    srand (time(NULL));
    
    *goalX = rand()%(upperLimitX + 1 - lowerLimitX) + lowerLimitX;
    *goalY = rand()%(upperLimitY + 1 - lowerLimitY) + lowerLimitY;  
}

/*
int arrayX(int x, int xCood[], int num) {
    
    
    int temp = xCood[num-1];
    xCood[num-1] = x;

    int temp2;
    for (int i=num-2; i>=0; ++i) {
        temp2 = xCood[i];
    }

}

*/
int dist(int snakePose,int mousePose) {
    
    int diff = snakePose - mousePose;
    
    return diff;
}

int main() {
    
    int goalX, goalY;
    int mouseXPose, mouseYPose;

    // Genereation of the start & end pt
    randLimit(0,6,4,10,&goalX, &goalY);
    randLimit(7,0,10,4,&mouseXPose, &mouseYPose);

    int num = 5;

    int snakeX = 5;
    int snakeY = 5;

    printf("Starting pose; X: %i , Y: %i\n", mouseXPose, mouseYPose);
    printf("End goal; X: %i , Y: %i\n", goalX, goalY);

    int diffX = dist(snakeX, mouseXPose);
    int diffY = dist(snakeY, mouseYPose);

    printf("diffX: %i, diffY: %i\n", diffX, diffY); 

    //Array implementation 
    int xCood[3] = {7,6,5};
    int yCood[3] = {5,5,5};

    if ((diffX > diffY) || (diffX == diffY)) {
       snakeX = xMovement(diffX, snakeX, snakeY, xCood, num);
       snakeY = yMovement(diffY, snakeX, snakeY, yCood, num);
       printf("Final Snake Pose; X: %i, Y: %i\n" , snakeX, snakeY );

    } else if (diffX < diffY) {
       snakeY = yMovement(diffY, snakeX, snakeY, yCood, num);
       snakeX = xMovement(diffX, snakeX, snakeY, xCood, num);
       printf("Final Snake Pose; X: %i, Y: %i\n" , snakeX, snakeY );       
    }

    return 0;

}

