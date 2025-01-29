#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_COUNTRIES 46

// STRUCT TO STORE COUNTRY AND ITS CAPITAL
typedef struct
{
    char country[50];
    char capital[50];
} CountryCapital;

// ARRAY OF COUNTRIES AND THEIR RESPECTIVE CAPITALS
CountryCapital capitals[NUM_COUNTRIES] = {
    {"Albania", "Tirana"},
    {"Andorra", "Andorra la Vella"},
    {"Austria", "Vienna"},
    {"Belarus", "Minsk"},
    {"Belgium", "Brussels"},
    {"Bosnia and Herzegovina", "Sarajevo"},
    {"Bulgaria", "Sofia"},
    {"Croatia", "Zagreb"},
    {"Cyprus", "Nicosia"},
    {"Czech Republic", "Prague"},
    {"Denmark", "Copenhagen"},
    {"Estonia", "Tallinn"},
    {"Finland", "Helsinki"},
    {"France", "Paris"},
    {"Germany", "Berlin"},
    {"Greece", "Athens"},
    {"Hungary", "Budapest"},
    {"Iceland", "Reykjavik"},
    {"Ireland", "Dublin"},
    {"Italy", "Rome"},
    {"Kosovo", "Pristina"},
    {"Latvia", "Riga"},
    {"Liechtenstein", "Vaduz"},
    {"Lithuania", "Vilnius"},
    {"Luxembourg", "Luxembourg City"},
    {"Malta", "Valletta"},
    {"Moldova", "Chisinau"},
    {"Monaco", "Monaco"},
    {"Montenegro", "Podgorica"},
    {"Netherlands", "Amsterdam"},
    {"North Macedonia", "Skopje"},
    {"Norway", "Oslo"},
    {"Poland", "Warsaw"},
    {"Portugal", "Lisbon"},
    {"Romania", "Bucharest"},
    {"Russia", "Moscow"},
    {"San Marino", "San Marino"},
    {"Serbia", "Belgrade"},
    {"Slovakia", "Bratislava"},
    {"Slovenia", "Ljubljana"},
    {"Spain", "Madrid"},
    {"Sweden", "Stockholm"},
    {"Switzerland", "Bern"},
    {"Ukraine", "Kyiv"},
    {"United Kingdom", "London"},
    {"Vatican City", "Vatican City"}};

// SHUFFLE THE INDICES OF COUNTRIES RANDOMLY USING THE FISHER-YATES SHUFFLE
void shuffle(int *array, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // GENERATE RANDOM INDEX
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main()
{
    srand(time(0)); // INITIALIZE RANDOM SEED BASED ON CURRENT TIME
    char playAgain;

    do
    {
        // GREETING MESSAGE
        printf("Welcome to the Capitals Of Europe quiz!\n");

        // INITIALIZE ARRAY OF COUNTRY INDICES
        int indices[NUM_COUNTRIES];
        for (int i = 0; i < NUM_COUNTRIES; i++)
        {
            indices[i] = i; // POPULATE WITH COUNTRY INDICES
        }

        // SHUFFLE THE COUNTRY INDICES INTO A RANDOM ORDER USING THE FISHER-YATES SHUFFLE
        shuffle(indices, NUM_COUNTRIES);

        int correctAnswers = 0; // TRACK CORRECT ANSWERS

        // LOOP THROUGH EACH COUNTRY
        for (int i = 0; i < NUM_COUNTRIES; i++)
        {
            int idx = indices[i]; // GET COUNTRY INDEX
            printf("What is the capital of %s?\n", capitals[idx].country);

            // GET USER'S GUESS FOR CAPITAL
            char userGuess[50];
            fgets(userGuess, sizeof(userGuess), stdin); // READ USER INPUT
            userGuess[strcspn(userGuess, "\n")] = 0;    // REMOVE NEWLINE CHARACTER FROM INPUT

            // COMPARE USER'S GUESS TO CORRECT CAPITAL (CASE-INSENSITIVE)
            if (strcasecmp(userGuess, capitals[idx].capital) == 0)
            {
                printf("Correct!\n");
                correctAnswers++; // INCREMENT SCORE FOR CORRECT ANSWER
            }
            else
            {
                printf("Incorrect! The capital of %s is %s.\n", capitals[idx].country, capitals[idx].capital);
            }

            printf("\n"); // ADD LINE BREAK BETWEEN QUESTIONS
        }

        // DISPLAY USER'S FINAL SCORE
        printf("You got %d out of %d right!\n", correctAnswers, NUM_COUNTRIES);
        printf("Thanks for playing!\n");

        // ASK IF USER WANTS TO PLAY AGAIN
        printf("Do you want to play again? (y for Yes, n for No): ");
        while (1) // INFINITE LOOP TO HANDLE INVALID INPUTS
        {
            if (scanf(" %c", &playAgain) == 1 && (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N'))
            {
                // VALID INPUT
                break; // EXIT THE LOOP
            }
            else
            {
                printf("Invalid input. Please enter 'y' for Yes or 'n' for No: ");
                while (getchar() != '\n') // CLEAR THE INPUT BUFFER
                    ;
            }
        }

    } while (playAgain == 'y' || playAgain == 'Y'); // REPEAT IF USER CHOOSES 'y' OR 'Y'

    // FINAL MESSAGE BEFORE EXITING
    printf("Exiting program\n");

    return 0;
}
