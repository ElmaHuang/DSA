//https://segmentfault.com/a/1190000018046286

#define MAX 1000
int g_boss[MAX];
int g_result = 0;

void init_proc(int p_num)
{
    int i;
    for(i = 0; i < p_num * p_num - 1; i++) {
        g_boss[i] = i; //0..7
    }

    for(i = 0; i < p_num; i++) { //p_num = 3
        g_boss[i] = 0; //0,1,2
        g_boss[i * p_num] = 0; //0,3,6
        g_boss[(i + 1) * p_num - 1] = 0; //2,4
        g_boss[p_num * (p_num - 1) + i] = 0; //2,3,4
    }
    g_result = 1;
}

int find(int p)
{
    if (p == g_boss[p]) {
        return p;
    } else {
        g_boss[p] = find(g_boss[p]);
        return g_boss[p];
    }
}
void join(int a, int b)
{
    int boss_a = find(a);
    int boss_b = find(b);

    if (boss_a == boss_b) {
            g_result++;    
    } else {
        g_boss[boss_a] = boss_b; 
    }
    //printf("a=%d, b=%d\n", a, b); 
    //printf("boss_a=%d, boss_b=%d\n", boss_a, boss_b);
}

int regionsBySlashes(char ** grid, int gridSize){
    int i, j, p;
    int p_num = gridSize + 1;
    init_proc(p_num);

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (grid[i][j] == ' ') {
                continue;
            } else if (grid[i][j] == '\\') {
                join(p_num * i + j, p_num * (i + 1) + j + 1);
            } else if (grid[i][j] == '/') {
                join(p_num * i + j + 1, p_num * (i + 1) + j);
            }
        }
    }
    return g_result;
}

/*
int **initGrid(char ** grid, int gridSize) {
    int **newGrid = (int **)malloc(sizeof(int *) * (gridSize * 3));
    int i;
    int j;
    for (i = 0 ; i < gridSize * 3; i++) {
        int *gridcol = (int *)malloc(sizeof(int) * (gridSize * 3));
        memset(gridcol, 0 ,sizeof(int) * (gridSize * 3));
        newGrid[i] = gridcol;
    }

    for (i = 0 ; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (grid[i][j] == '/') {
                newGrid[3 * i][3 * j + 2] = 1;
                newGrid[3 * i + 1][3 * j + 1] = 1;
                newGrid[3 * i + 2][3 * j] = 1;
            }
            if (grid[i][j] == '\\') {
                newGrid[3 * i][3 * j] = 1;
                newGrid[3 * i + 1][3 * j + 1] = 1;
                newGrid[3 * i + 2][3 * j + 2] = 1;
            }
        }
    }
    return newGrid;
}
void findRrgions(int **newGrid, int gridSize, int i ,int j){
    if (i == gridSize || i < 0)
        return;
    if (j == gridSize || j < 0)
        return;
    if (newGrid[i][j] == 0) {
        newGrid[i][j] = 1;
        findRrgions(newGrid,gridSize, i + 1,j);
        findRrgions(newGrid, gridSize, i - 1,j);
        findRrgions(newGrid, gridSize, i, j + 1);
        findRrgions(newGrid, gridSize, i, j - 1);
    }
}
int regionsBySlashes(char ** grid, int gridSize){

    int **newGrid = initGrid(grid, gridSize);
    int regions =0;
    int i, j;
    for (i = 0; i < 3 * gridSize; i++) {
        for(j = 0; j < 3 * gridSize; j++) {
            if (newGrid[i][j] == 0) {
                findRrgions(newGrid, 3 * gridSize, i ,j);
                regions++;
            }
        }
    }
    //free;
    for (i=0; i < gridSize * 3; i+=) {
        free(newGrid[i]);
    }
    free(newGrid);
    return regions;
}

*/