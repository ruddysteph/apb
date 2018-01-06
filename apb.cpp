#include <vector>
#include <map>
#include <cassert>
#include <iostream>
#include <random>
#include <algorithm>

using std::vector;
using std::map;
using std::cout;
using std::iostream;

enum { NB_ETABLISSEMENT = 10 , NB_ETUDIANT = 20 , NB_MAX_CHOIX = 10};


struct lEtud 
{
  	vector<int> listEtab;
  	double classement;
};

typedef map<int, lEtud> myList;


myList init(int nb)
{
    myList l;
    int rdm;

    // Générateur de nombres pseudo-aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long> dis(0, NB_ETABLISSEMENT - 1);

    for(int i = 0; i < nb; i++) 
    {
        for(int j = 0; j < NB_MAX_CHOIX; j++) 
        {
        	rdm = dis(gen);
        	//Si l'element n'existe pas déja
        	if (!(std::find(l[i].listEtab.begin(), l[i].listEtab.end(),rdm) != l[i].listEtab.end()))
        	{
        		l[i].listEtab.push_back(rdm);
        	}
        }
    }
    return l;
}

void affiche (myList l)
{
	for(auto it=l.begin() ; it != l.end() ; ++it)
	{
		cout << "num étudiant : " << it->first << "\n";
		lEtud tmp = it->second;
		cout << "Liste d'établissement : ";
    	for(auto pair_it = tmp.listEtab.begin() ; pair_it != tmp.listEtab.end() ; ++pair_it)
    	{
    		cout << " " << *pair_it << " ";
    	}
    	cout << "\n";
	}
}

// map<int, int> affectation (myList l)
// {
// 	map<int, int> affecter;

// 	if(mycmp(l) == 1)
		

// 	return affecter;
// }


int main ()
{
	myList l = init(NB_ETUDIANT);
	affiche(l);
	return 0;
}