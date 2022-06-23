#include <iostream>
using namespace std;

unsigned int maxSum(int value, int maxint);

int main(void)
{
    string value;
    int maxint;
    while(true)
    {
        cout << "Entrez 'q' pour quitter." << endl;
        cout << "Saisissez value : ";
        cin >> value;
        if(value=="q")
        {
            break;
        }
        int valeur = stoi(value);
        cout << "Saisissez maxint : ";
        cin >> maxint;
        try{
            maxSum(valeur,maxint);
        } catch(string s){
            cerr << "Erreur::" << s << endl;
        };
    }
    return 0;
}

unsigned int maxSum(int value, int maxint)
{
    if(maxint<0)
    {
        throw string("XZVF - maxint (RIGHT VALUE) est negatif.");
    }
    //Valeur absolue
    unsigned int somme = 0;
    if(value<0)
    {
        value=-value;
    }
    for(int i = 0 ; i <= value ; i++)
    {
        somme+=i;
    }
    if(somme<=maxint)
    {
        return somme;
    } else {
        throw string("SGBD - Exception, somme > maxint");
    }
    
}