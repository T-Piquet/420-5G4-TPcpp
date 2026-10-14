# El Maazouzi Youssef

# Fonctionnalités choisies
-numérotation automatique des ID utilisateurs.
-Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).
-Créez un fichier de journal de l’application. Ce fichier est conservé au fur et à mesure des sessions (créez le fichier s’il n’existe pas à la première exécution).
-ne pas sauvegarder si les chemins sont vides et afficher un message explicite

# Question 1 : Fonction peu vue 
Pour créer le fichier journal.log, j'ai utilisé ofstream en m'inspirant de la fonction FileManager::saveBooksToFile tout en utilisant ios::app qui permet d'ajouter du texte à la fin du fichier afin de garder la session précédente. On vérifie avec is_open() pour s'assurer que le fichier est ouvert et puis on peut ajouter nos éléments avec file << "". Exemple : ofstream file(journalLog, ios::app); 
file << " - [" <<action << "] " << details << "\n";

# Question 2 : Options de développement possible 
Pour le futur, avec certainement des millions de livres, je stockerais toutes les données de la bibliothèque dans un serveur NAS qui peut contenir plusieurs HDD. On accèderait à l'interface web du serveur grâce à un vpn et par une requête HTTP afin que cela soit plus sécurisé. Pour toutes les transactions, comme l'emprunt ou encore le retour d'un livre, on peut communiquer le C++ avec des requêtes SQL pour gérer la base de données.  

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

