#define spriteData  ((unsigned short *) 0x6010000)

#define P 1  // Purple 
#define BY 2 // Bright Yellow
#define LG 3 // Light Green
#define DG 4 // Dark Green
#define MG 5 // Medium Green
#define W 6  // White
#define R 7  // Red

#define SPRITE_SNAKE_HEAD 0
#define SPRITE_SNAKE_BODY 1
#define SPRITE_PLAYER 2
#define SPRITE_END_GOAL 14
// defines the number of sprites 
#define SPRITE_NUMB 14

unsigned short sprites[] = {
    // 0 48 snake head 
     0, 0,DG,DG,DG,DG, 0, 0,
     0,DG,DG,LG,LG,DG,DG, 0,
    DG,MG, W,LG,LG, W,DG,DG,
    DG,BY, W,LG,LG, W,LG,LG,
    DG,LG,LG,LG,LG,LG,LG,DG,
    DG,DG,LG, R, R,LG,LG,DG,
     0,DG,DG, R, R,LG,DG, 0,
     0, 0,DG,DG,DG,DG, 0, 0,
     
    // 1 49 snake body 
     0, 0,DG,DG,DG,DG, 0, 0,
     0,DG,DG,BY,LG,DG,DG, 0,
    DG,MG,LG,LG,LG,BY,MG,DG,
    DG,BY,BY,MG,LG,MG,LG,LG,
    MG,LG,LG,LG,LG,LG,LG,DG,
    DG,DG,LG,DG,MG,LG,LG,DG,
     0,DG,DG,LG,MG,LG,DG, 0,
     0, 0,DG,DG,DG,DG, 0, 0, 

    // 2 50 player
    0,0,R,R,R,R,0,0,
    0,R,R,R,R,R,R,0,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    0,R,R,R,R,R,R,0,
    0,0,R,R,R,R,0,0,

    // Main Menu Font
    // 3 51 letter S
    0,R,R,R,R,R,R,0,
    R,R,R,R,R,R,R,R,
    R,R,R,0,0,0,0,0,
    R,R,R,R,R,R,R,0,
    0,R,R,R,R,R,R,R,
    0,0,0,0,0,R,R,R,
    R,R,R,R,R,R,R,R,
    0,R,R,R,R,R,R,0,

    // 4 52 letter N
    R,R,R,0,0,R,R,R,
    R,R,R,R,0,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,0,R,R,R,R,
    R,R,R,0,0,R,R,R,

    // 5 53 letter A
    0,R,R,R,R,R,R,0,
    R,R,R,R,R,R,R,R,
    R,R,R,0,0,R,R,R,
    R,R,R,0,0,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,0,0,R,R,R,
    R,R,R,0,0,R,R,R,

    // 6 54 letter K
    R,R,R,0,0,0,R,R,
    R,R,R,0,0,R,R,R,
    R,R,R,0,R,R,R,0,
    R,R,R,R,R,R,0,0,
    R,R,R,R,R,R,0,0,
    R,R,R,0,R,R,R,0,
    R,R,R,0,0,R,R,R,
    R,R,R,0,0,0,R,R,

    // 7 55 letter E
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,
    R,R,R,0,0,0,0,0,
    R,R,R,R,R,R,0,0,
    R,R,R,R,R,R,0,0,
    R,R,R,0,0,0,0,0,
    R,R,R,R,R,R,R,R,
    R,R,R,R,R,R,R,R,

    // Unicode Font 
    
    // 8 56 letter S (Unicode font)
    0,0,0,0,0,0,0,0,
    0,0,W,W,W,W,0,0,
    0,W,0,0,0,0,W,0,
    0,0,W,W,0,0,0,0,
    0,0,0,0,W,W,0,0,
    0,W,0,0,0,0,W,0,
    0,0,W,W,W,W,0,0,
    0,0,0,0,0,0,0,0,

    // 9 57 letter T (Unicode font)
    0,0,0,0,0,0,0,0,
    0,W,W,W,W,W,W,W,
    0,0,0,0,W,0,0,0,
    0,0,0,0,W,0,0,0,
    0,0,0,0,W,0,0,0,
    0,0,0,0,W,0,0,0,
    0,0,0,0,W,0,0,0,
    0,0,0,0,0,0,0,0,

    // 10 58 letter A (Unicode font)
    0,0,0,0,0,0,0,0,
    0,0,0,W,W,0,0,0,
    0,0,0,W,W,0,0,0,
    0,0,W,0,0,W,0,0,
    0,W,W,W,W,W,W,0,
    0,W,0,0,0,0,W,0,
    0,W,0,0,0,0,W,0,
    0,0,0,0,0,0,0,0,

    // 11 59 letter R (Unicode font)
    0,0,0,0,0,0,0,0,
    0,W,W,W,W,W,0,0,
    0,W,0,0,0,0,W,0,
    0,W,W,W,W,W,0,0,
    0,W,0,0,W,0,0,0,
    0,W,0,0,0,W,0,0,
    0,W,0,0,0,0,W,0,
    0,0,0,0,0,0,0,0,

    // 12 60 letter A (Button)
    R,R,R,R,R,R,R,R,
    R,0,0,W,W,0,0,R,
    R,0,0,W,W,0,0,R,
    R,0,W,0,0,W,0,R,
    R,0,W,W,W,W,0,R,
    R,0,W,0,0,W,0,R,
    R,0,W,0,0,W,0,R,
    R,R,R,R,R,R,R,R,

    // 13 61 letter L (Unicode font)
    0,0,0,0,0,0,0,0,
    0,W,0,0,0,0,0,0,
    0,W,0,0,0,0,0,0,
    0,W,0,0,0,0,0,0,
    0,W,0,0,0,0,0,0,
    0,W,0,0,0,0,0,0,
    0,W,W,W,W,W,W,0,
    0,0,0,0,0,0,0,0,
    

    // 14 62 endGoal for player
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,
    W,W,W,W,W,W,W,W,

};

/*

R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,
R,R,R,R,R,R,R,R,

*/
