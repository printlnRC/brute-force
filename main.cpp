#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
fonction qui compte la longeur de notre tableau
*/
int ft_strlen(char *nb)
{
    int i;

    i = 0;
    while(nb[i])
        {
            i++;
        }
    return (i);
}

/*
fonction permettant de vérifier que le tableau ne contient que des nombres
*/
int ft_number(char *nb) 
{
    int i;
    int yes;

    i = 0;
    yes = 0;
    while (nb[i])
        {
            if (nb[i] >= 48 && nb[i] <= 57)
                yes++;
            else
                std::cout << "que des chiffre son demandé" << std::endl;
            i++;
        }
    return (yes);
}

/*
fonction permetant de comparer le caractère 'i' avec le carcacter 'i' du 
code que l'on essaye de brute force
*/
int ft_strcmp(char *nb, char *result) 
{
    int i = 0;
    while (i < 4) // Comparer les 4 caractères
    {
        if (nb[i] != result[i])
            return 0; // Les codes sont différents
        i++;
    }
    return 1; // Les codes sont identiques
}

/*
le coeur du brogramme la fonction qui brute force le code
*/
void fr_brute(char *nb)
{
    char result[5] = "0000"; // Inclure le caractère nul à la fin
    int i;

    i = 0;
    while (!ft_strcmp(nb, result) != 0)
    {
        i = 0;
        while (i < 4)
        {
            if (result[i] != nb[i]) //si result[i] différent de nb[i]
                result[i]++;
            if (result[i] > '9') // Empêcher de dépasser '9'
                result[i] = '0';
            i++;
        }
    }
    std::cout << "Code trouvé: " << result << std::endl;
}

int main()
{
    char nb[5];
    
    std::cout << "entrée code a craquer" << std::endl;
    cin >> nb;
    if (ft_strlen(nb) == 4)
    {
        if (ft_number(nb) == 4)
        {
            std::cout << "début du procéder" << std::endl;
            std::cout << "longeur code ok" << std::endl;
            std::cout << "nombre code ok" << std::endl;
            auto start = high_resolution_clock::now(); // début chrono
            fr_brute(nb);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start); // fin chrono
            std::cout << "Temps écoulé: " << duration.count() << " millisecondes" << std::endl;
            // resultat du  chrono
        }
    }
    else
        std::cout << "code incorrect" << std::endl;
    return 0;
}