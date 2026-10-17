1. Jérémie Prévost
2. fonctionnalités: Numerotation automatique des ID utilisateurs et tri des résultats par titre, auteur pour l’affichage

Question 1: C++

Le stringstream est une classe en C++ qui permet de lire un string comme si c'était un ficher ouvert. Il faut inclure #include <sstream> pour l'utiliser. Par exemple si j'ai une ligne avec plusieurs éléments à lire, je peux lire ces éléments en les découpants avec getline(). Stringstream sert aussi à assembler plusieurs variables de types différents en une seule string (comme stringBuilder en java). Exemple: 

string ligne = "2005,Jeremie,21";
stringstream ss(ligne);

string ddn, nom, age;

getline(ss, ddn, ","); --- Lit le texte jusqu'a la virgule et met le resultat dans ddn
getline(ss, nom, ","); // la lecture continue
getline(ss, age, ",");


Question 2: Options de développement possible

Il faudrait lier l'application a un SGBD et le c++ ferait le pont entre les deux. MySql pourrait fonctionner mais il faudrait installer la biblioteque MySQL Connector/C++. Ensuite il faudrait lier cette bibliotheque a l'executable dans cmake. Créer une nouvelle classe databaseManager pour remplacer filemanager et recoder toutes les methodes qui accedent aux données pour utiliser des requetes SQL. Si l'application contient un tres grand nombre de livres et d'utilisateurs, il ne sera plus possible d'utiliser un fichier texte pour les données car les fonctions seront trop lentes. mysql peut chercher instantanément à travers des milliers d'enregistrements.