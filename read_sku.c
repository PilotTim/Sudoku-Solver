#include <stdio.h>
#include <math.h>

int read_sku(char *filename, unsigned int *data)
{
    int retval = 0;
    FILE *fp = fopen(filename, "r");

    if ( data != NULL )
    {
        if ( fp != NULL )
        {
            unsigned int line_no = 0;
            unsigned int count = 0;

            while ( !feof(fp) && (retval >= 0) )
            {
                int c = fgetc(fp);

                if ( c == '\n' || c == '\r' )
                {
                    line_no++;
                    printf("Line %d %d columns\n", line_no, count);
                    count = 0;
                }
                else if ( c != EOF )
                {
                    *data = (unsigned int)c;
                    data++;
                    count++;
                }
            }
            fclose(fp);
            if ( sqrt(count) * 2 != count )
            {
                retval = -1;
                printf("Non square grid\n");
            }
        }
    }
    return retval;
}

