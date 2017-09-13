#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    printf("Hoeveel deelnemers zijn er?\n");
    int aantal = get_int();
    string deel[aantal + 2];
    string drink[aantal + 2];
    for (int i = 1; i <= aantal; i++)
    {
        printf("Deelnemer: ");
        string naam = get_string();
        deel[i] = naam;
        drink[i] = naam;
    }
    printf("Leuk dat jullie meedoen ");
    for (int i = 1; i < aantal; i++)
    {
        printf("%s ", deel[i]);
    }
    printf("en %s!\n", deel[aantal]);
    deel[0] = "Niemand";
    deel[aantal + 1] = 0;
    drink[0] = "Niemand";
    drink[aantal + 1] = 0;
    srand(time(NULL));
    int n = 0;
    string naam;
    string anderenaam;
    int buddies;
   // int beurt;
    printf("Hoeveel rondes willen jullie spelen: ");
    int rondes = get_int();
    for (int i = 0; i < rondes; i++)
    {
        int r = 0;
        while (r == 0)
        {
            r = rand() % aantal + 1;
        }
        printf("%s, jij bent aan de beurt!\n", deel[r]);
        int opdrachtgever = 0;
        do
        {
            opdrachtgever = rand() % aantal;
        }
        while (opdrachtgever == r || opdrachtgever == 0);
        int opdracht = rand() % 5;
        if (opdracht == 0)
        {
            printf("What are the odds dat je een opdracht doet die %s bedenkt?: ", deel[opdrachtgever]);
            int odds = get_int();
            int kans = rand() % odds;
            printf("Eerste getal: %i\nDruk op Enter\n", kans);
            getchar();
            int kans2 = rand() % odds;
            printf("Tweede getal: %i\n", kans2);
            if (kans == kans2)
            {
                printf("Lol je moet het doen!! HAHAHA\n");
            }
            else
            {
                printf("Niet gelijk, backfire! Druk op Enter");
                odds = odds - 1;
                getchar();
                printf("%s, deze is voor jou. The odds zijn nu %i MUHAHA!!\n", deel[opdrachtgever], odds);
                kans = rand() % odds;
                printf("Druk op Enter\n");
                getchar();
                printf("Eerste getal: %i\nDuk op Enter\n", kans);
                getchar();
                kans2 = rand() % odds;
                printf("Tweede getal: %i\n", kans2);
                if (kans == kans2)
                {
                    printf("HAHAHA JE MOET JE EIGEN OPDRACHT DOEN, SUKKEL\n");
                }
                else
                {
                    printf("jammer... de volgende is aan de beurt.\n");
                }
            }
        }
        else if (opdracht == 1)
        {
            printf("%s, hoeveel slokken moet %s drinken?", deel[r], deel[opdrachtgever]);
            int slokken = get_int();
            int getal = rand() % 5;
            if (getal == 3)
                printf("%s, drink trouwens zelf maar die %i slokken!!!\n", drink[r], slokken);
            else
                printf("%s, drink %i slokken.\n", drink[opdrachtgever], slokken);
        }
        else if (opdracht == 2)
        {
            printf("%s, stel je voor aan iemand in de ruimte (die niet meedoet aan het spel) en vraag een getal tussen 1 en 10.\n Wat was de naam:", deel[r]);
            naam = get_string();
            printf("Wat was het getal? ");
            int drinken = get_int();
            printf("%s, drink %i slokken\n", drink[r], drinken);
            n = 1;
            anderenaam = deel[r];

        }
        else if (opdracht == 3)
        {
            if (n == 1)
            {
                printf("%s, wat is de naam van degene waar %s zich net aan heeft voorgesteld? ", deel[r], anderenaam);
                string antwoord = get_string();
                if (strcmp(antwoord, naam) == 0)
                    printf("GOEDZO! Je mag 3 slokken uitdelen.\n");
                else
                    printf("lekker geinteresseerd... dat was niet goed. %s, drink 5 slokken.\n", drink[r]);
                n = 0;
            }
            else
            {
                int getal = rand() % 3;
                if (getal == 2)
                {
                    printf("%s, ga voor iedereen bier halen die nodig heeft.\n", deel[r]);
                }
                else
                {
                    printf("%s, stel een persoonlijke vraag aan %s.\n", deel[r], deel[opdrachtgever]);
                }
            }
        }
        else if (opdracht == 4)
        {
            if (buddies <= 2)
            {
                printf("Gefeliciteerd %s, jij bent nu drinkingbuddies met %s! Wat is jullie teamnaam als buddy?\n", deel[r], deel[opdrachtgever]);
                string teamnaam = get_string();
                string juisteantwoord = "ik zit al in een team";
                if (strcmp(drink[r], deel[r]) == 0 && strcmp(drink[opdrachtgever], deel[opdrachtgever]) == 0)
                {
                    drink[r] = teamnaam;
                    drink[opdrachtgever] = teamnaam;
                    buddies = buddies + 1;
                }
                else if (strcmp(drink[opdrachtgever], drink[r]) == 0)
                {
                    if (strcmp(teamnaam, juisteantwoord) == 0)
                    {
                        printf("Heel goed, een echte teamspeler. Bravo voor jou. Deel als team 5 slokken uit\n");
                    }
                    else
                    {
                        printf("Haha grapje jullie waren al een team. Waren jullie dat vergeten ofzo?? Sukkels. %s, drink maar 5 slokken.\n", drink[r]);
                    }
                }
                else if (strcmp(drink[opdrachtgever], deel[opdrachtgever]) != 0)
                {
                    if (strcmp(teamnaam, juisteantwoord) == 0)
                    {
                        printf("Heel goed, een echte teamspeler. Bravo voor jou. Deel als team 5 slokken uit\n");
                    }
                    else
                    {
                        printf("Oh %s, jij zat al in een team. Verrader. %s, drink maar 10 slokjes. En %s, jij drinkt ze allemaal. Niet nog een keer je teamgenoot naaien!\n", deel[opdrachtgever], drink[opdrachtgever], deel[opdrachtgever]);
                    }
                }
                else
                {
                    if (strcmp(teamnaam, juisteantwoord) == 0)
                    {
                        printf("Heel goed, een echte teamspeler. Bravo voor jou. Deel als team 5 slokken uit.\n");
                    }
                    else
                    {
                        printf("Oh %s, jij zat al in een team. Verrader. %s, drink maar 10 slokjes. En %s, jij drinkt ze allemaal. Niet nog een keer je teamgenoot naaien!\n", deel[r], drink[r], deel[r]);
                    }

                }

            }
        }
        else if (opdracht == 5)
        {

            printf("%s, vanaf nu moet je 3 rondes met je ogen dicht zitten. Als je ze open doet moet je een slok drinken.\n", deel[r]);
        }

        printf("Druk op Enter...");
        getchar();
    }

    /*int r = rand() % argc - 1;
    printf("%i", r);
    printf("%s is aan de beurt", argv[r]);*/
}