//Title - Save The Kingdom
//Author - Priyanshu Gupta
//Date - 27 oct 2020


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

int main() {


    int number, number1, choice, choice1, guess, nguesses = 1, attempts = 7, win = 0, lose = 0;
    char you, book;


    printf("\n\n\n**********Hello Saviour!!!***********\n");
    printf("You are called here for a secret mission.\n");
    printf("There was a theif, he stole the magical book of the king from his room.\n");
    printf("King's army began to search him so he went in a dark room.\n");
    printf("The magic book could have a password of 8 digits {first 5 capital letters and then 3 digits}.\n");
    printf("Somebody told theif that the password of the book was \"MAGIC143\".\n");
    printf("For changing password, he had to perform a task & he did it successfully.\n");
    printf("The army arrested him with the book and presented him before king.\n");
    printf("He bas beaten badly so king asked him to tell password before he died.\n");
    printf("He said that the password was - \n\tG\n\tU\n\tE\n\tS\n\tS\n\t7\n\t.\n\t.\n\t.\n\t.\n");
    printf("Alas! he died before telling the last two digits.\n");
    printf("The book is very useful for kingdom and it can bear only 7 wrong passwords.\n");
    printf("Please save the kingdom by guessing the correct two digits within 7 guesses.\n");


    do {

        do {

            srand(time(0));
            number = rand() % 90 + 10;

            do {

                if (attempts == 7)
                {
                    printf("You have 7 attempts to enter the password. All the best SUPERHERO!!!\n");
                }

                printf("\tEnter the password :\t GUESS7");
                scanf("%d", &guess);

                if ((guess > number) && (attempts > 1)) {
                    printf("Wrong password.\n\'HINT\' : Enter LOWER number please!\n");
                }

                else if ((guess < number) && (attempts > 1)) {
                    printf("Wrong password.\n'HINT\' : Enter HIGHER number please!\n");
                }

                else if (guess == number) {
                    printf("Congratulations!!! You guessed it in %d attempts\n", nguesses);
                    break;
                }

                nguesses++;
                attempts--;

                switch (attempts)
                {
                case 6:
                    printf("\nWe believe our superhero. You have %d attempts left.\n", attempts);
                    break;

                case 5:
                    printf("\nDon't worry. You have %d attempts left\n", attempts);
                    break;

                case 4:
                    printf("\nKeep trying. You still have %d attempts left\n", attempts);
                    break;

                case 3:
                    printf("\nPLease Save us. You have %d attempts left\n", attempts);
                    break;

                case 2:
                    printf("\nWe don't want to die. You have only %d attempts left\n", attempts);
                    break;

                case 1:
                    printf("\nThis is your last try. Please save us.\n");
                    break;
                case 0:
                    printf("\nOOPS! You have used all of your attempts.\n");
                    break;

                }
            } while ((guess != number) && (attempts > 0));

            if (guess == number)
            {
                printf("WOW SAVIOUR ! You saved the kingdom!!!!\n\n\n");
                choice = 2;
            }

            else
            {
                printf("You could not save the kingdom !!!\n Better luck next time. \n\n\n");
                printf("Would you like to play again?\n(enter 1 for YES and 0 for NO ) :\t");
                scanf("%d", &choice);
            }

            nguesses = 1, attempts = 7;

        } while (choice == 1);

        if (choice == 2)
        {
            printf("\n\n\n*****************************************\n\n\n");
            printf("Hey Saviour ! now, there is some more work left to do.\n");
            printf("Since everyone knows the password, you need to change it.\n");
            printf("Else anyone can steal it again and use it for his personal assistence.\n");
            printf("You will have to perform a task for that. Be ready for your task.\n");
            printf("Your task is to win rock-paper-scissor against book in order to change password.\n");
            printf("you have 7 chances and you need to win more. Equal win will make this book blocked.\n");
            printf("\n\n");

            srand(time(NULL));

            for (int i = 0; i < 7; i++)
            {
                number1 = rand() % 3 + 1;

                if (number1 == 1)
                    book = 'r';

                else if (number1 == 2)
                    book = 'p';

                else if (number1 == 3)
                    book = 's';


                printf("Enter 'r' for rock, 'p' for paper and 's' for scissor :\n");
                scanf(" %c", &you);

                you = tolower(you);

                if (you == book) {
                    printf("\nGame draw!\n");
                }

                else if ((you == 'p' && book == 'r') || (you == 's' && book == 'p') || (you == 'r' && book == 's')) {
                    printf("\nYou win!\n");
                    win++;
                }

                else if ((you == 'r' && book == 'p') || (you == 'p' && book == 's') || (you == 's' && book == 'r')) {
                    printf("\nYou Lose!\n");
                    lose++;
                }

                printf("You chose %c and book chose %c.\n", you, book);
            }

            if (win > lose)
            {
                printf("\nWOW SAVIOUR ! You have changed the password!!!!\n\n\n");
            }

            else
            {
                printf("\nThe book is blocked !!!\n Better luck next time. \n\n\n");
            }

            printf("\nWould you like to play the whole game again?\n(enter 1 for YES and 0 for NO ) :\t");
            scanf("%d", &choice1);

            win = 0, lose = 0;
        }

    } while (choice1 == 1);

    return 0;
}