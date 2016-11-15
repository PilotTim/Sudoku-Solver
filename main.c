#include <stdio.h>
#include <string.h>

#define BIT(_X) ( 1 << (_X) )
#define ALL_SET ( \
        BIT(0) | BIT(1) | BIT(2) | BIT(3) | \
        BIT(4) | BIT(5) | BIT(6) | BIT(7) | BIT(8) )

// pointer to the grid
unsigned int grid[9][9];

int square_to_row_col(unsigned int sqr, unsigned int *row, unsigned int *col)
{
    *row = 3*(sqr%3);
    *col = 3*(sqr/3);
    return 0;
}

int check_sqr(unsigned int sqr)
{
    unsigned int i,j;
    unsigned int num_used = 0;
    unsigned int row, col;

    square_to_row_col(sqr, &row, &col);

    for ( i = col; i < col+3; i++ )
    {
        for ( j = row; j < row+3; j++ )
        {
            if ( num_used & BIT(grid[i][j]-1) )
            {
                return -1;
            }
            num_used |= BIT(grid[i][j]-1);
        }
    }
    if ( num_used == ALL_SET )
        return 0;
    else
        return 1;
}

int check_col(unsigned int col)
{
    unsigned int i;
    unsigned int num_used = 0;

    for ( i=0; i<9; i++ )
    {
        if ( num_used & BIT(grid[i][col]-1) )
            return -1;
        num_used |= BIT(grid[i][col]-1);
    }
    if ( num_used == ALL_SET )
        return 0;
    else
        return 1;
}

int check_row(unsigned int row)
{
    unsigned int i;
    unsigned int num_used = 0;

    for ( i=0; i<9; i++ )
    {
        // printf("0x%x %d\n", num_used, grid[row][i]);
        if ( num_used & BIT(grid[row][i]-1) )
            return -1;
        num_used |= BIT(grid[row][i]-1);
    }
    if ( num_used == ALL_SET )
        return 0;
    else
        return 1;
}

int displayGrid(unsigned int *inGrid)
{
    unsigned int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d", inGrid[i*9+j]);
            if ( j && ( 0 == ((1+j)%3)))
                printf(" ");
        }
        printf("\n");
        if ( i && ( 0 == ((1+i)%3)))
            printf("\n");
    }
    return 0;
}

int main(int argc, char **argv)
{
    unsigned int i;
    unsigned int mygrid[9][9] = {
        { 1,2,3,4,5,6,7,8,9},
        { 2,2,3,4,5,6,7,8,9},
        { 3,2,3,4,5,6,7,8,9},
        { 4,2,3,1,2,3,7,8,9},
        { 5,2,3,4,5,6,7,8,9},
        { 6,2,3,7,8,9,7,8,9},
        { 7,2,3,4,5,6,7,8,9},
        { 8,2,3,4,5,6,7,8,9},
        { 9,2,3,4,5,6,7,8,9},
    };
    memcpy(grid, mygrid, sizeof(unsigned int) * 9*9);
    for ( i=0; i<9; i++ )
    {
        if ( check_row(i) == 0 )
            printf("Row %d checks out\n", i);
        if ( check_col(i) == 0 )
            printf("Col %d checks out\n", i);
        if ( check_sqr(i) == 0 )
            printf("Square %d checks out\n", i);
    }
    displayGrid((unsigned int *)mygrid);
    return 0;
}
