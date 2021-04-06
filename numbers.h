#define spriteData  ((unsigned short *) 0x6010000)
#define P 1
#define BY 2 // Bright Yellow
#define LG 3 // Light Green
#define DG 4 // Dark Green
#define MG 5 // Medium Green
#define E 6 // White
#define R 7 // Red

unsigned short numbers[] = {
    // 0 48 snake head 
     0, 0,DG,DG,DG,DG, 0, 0,
     0,DG,DG,LG,LG,DG,DG, 0,
    DG,MG, E,LG,LG, E,DG,DG,
    DG,BY, E,LG,LG, E,LG,LG,
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
};
