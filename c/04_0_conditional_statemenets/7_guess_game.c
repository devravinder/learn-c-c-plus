#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int range)
{
    int r = rand(); // rand() gives same number on very calls, if don't set: srand(time(NULL));
    int result = r % range + 1;
    return result;
}

void guessGame()
{

    int from = 1;
    int to = 5;
    int noOfTrials = 3;

    printf("Guess a number in %d trials from %d to %d\n", noOfTrials, from, to);

    int randomNo = getRandom(to);
    int guess;
    int trials = 0;

    while (trials < noOfTrials)
    {

        printf("Enter number: ");
        scanf("%d", &guess);

        if (guess == randomNo)
        {
            printf("🎉 You Won!\n");
            break; // ** to break / come out of loop
            // return; // we can use this
        }
        else
        {
            printf("Try again!\n");
        }

        trials++;
    }

    if (trials == noOfTrials)
        printf("Better luck next time! Number was %d\n", randomNo);
}

int main()
{

    srand(time(NULL)); // seed ONCE  per program: to get random number on every call

    guessGame();

    return 0;
}
