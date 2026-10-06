#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // opening both file in read only mode
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    if (fp1 == NULL)
        exit(2);
    if (fp2 == NULL)
        exit(3);

    // fetching character of two file in two variable ch1 and ch2
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    // error keeps track of number of errors pos keeps track of position of errors
    // line keeps track of error line
    int mismatch = 0, pos = 0, line = 1;

    // iterate loop till end of file
    while (ch1 != EOF || ch2 != EOF)
    {

        pos++;

        // if both variable encounters new line then line variable is incremented
        // and pos variable is set to 0
        if (ch1 == '\n' && ch2 == '\n')
        {
            line++;
            pos = 0;
        }

        // if fetched data is not equal then error is incremented
        if (ch1 != ch2)
        {
            mismatch++;
        }

        // fetching character until end of file
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }

    //
    fclose(fp1);
    fclose(fp2);

    if (mismatch == 0)
        exit(0);
    else
        exit(1);

    return 0;
}