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

# Belkhala Anis 202497143

# fonctionnalités :

Interface et Expérience Utilisateur = numérotation automatique des ID utilisateurs.

Gestion des Données = Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

Corriger un bug = Sauvegarde automatique à la sortie sans répertoire de données

# Question 1 : C++

La notion de datetime n'a pas été vue en classe. Voici l'exemple de code :
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

    char output[50];
    strftime(output, 50, "%Y-%m-%d %H:%M:%S ", &datetime);

On commence par récupérer la date actuelle. Ensuite, on la convertit avec la structure tm, qui possède toutes les valeurs (heures, minutes, secondes, etc.). On finit par l'écrire dans la variable output, qui est notre sortie de texte. Le résultat attendu est le suivant : 2026-10-19 13:43:43

# Question 2 : Options de développement possible

On pourrait utiliser une base de données pour une meilleure gestion de nos données.
Par exemple, MongoDB serait une bonne option, puisque des méthodes de recherche efficaces y sont déjà incluses.
Cela pourrait réduire la taille du code et éviter les erreurs liées à des requêtes inefficaces.
On pourrait aussi utiliser Python plutôt que C++ pour obtenir un code plus lisible, même s'il sera plus lent.
Il est plus facile à lire et à modifier, comme dans le cas de notre bibliothèque.