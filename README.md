# Nom et numero de DA
Karisik Safet 2369940

# Fonctionnalités choisies
1. Numérotation automatique des ID utilisateurs
2. Tri des résultats par titre, auteur pour affichage
3. Création d'un fichier journal de l'application

# Question 1 
Une notion qui a peu été vue en cours est le lambda. Avant de faire le tri je met le texte en minuscule avec la fonction toLower pour que les majuscules n'impactent pas le tri. J'ai utiliser std::sort pour trier les livres. Lambda permet d'écrire la règle du tri dans le std::sort. Dans le code la clé (key) sert à lambda d'utiliser pour savoir si on fait un tri par titre ou d'auteur. Lambda compare les livres "a" et "b" puis retourne "true" si "a" vien avant "b". Aussi, si les 2 sont égaux, alors sa compare les titres pour les classer. 

Extrait:
    //to lower case
    static string toLower(string text){
        transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
            return static_cast<char>(tolower(c));
        });
        return text;
    }
    //sort books
    vector<Book*> Library::getBooksSorted(SortKey key){
        vector<Book*> sorted = getAllBooks();
        sort(sorted.begin(), sorted.end(), [key](const Book* a, const Book* b){
            string first = toLower(key == SortKey::Title ? a->getTitle() : a->getAuthor());
            string second = toLower(key == SortKey::Title ? b->getTitle() : b->getAuthor());
            if(first != second){
                return first < second;
            }
            return toLower(a->getTitle()) < toLower(b->getTitle());
        });
        return sorted;
    }

# Question 2
La solution pour avoir une gestion plus organiser de la bibliotheque serait d'utiliser des bases de donnnées qui sont organisées par des clés primaires et secondaires. J'utiliserais MySql pour faire le stockage des livres, usagers, emprunts 
et retours de la librarie. Je ferais une ou plusieurs tables au besoin pour chaque critère. 
Pour connecter MySql au C++ je ferais une bibliothèque grâce à Connector/C++. Donc "FileManger" n'aurait plus d'utilité 
dans le code et je la remplacerais par une communicaiton du code C++ avec la base de données MySql. Selon moi cette 
solution pourrait être bonne pour le futur de la bibliothèque en Alexandrie ou une autre grande bibliothèque.

# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`