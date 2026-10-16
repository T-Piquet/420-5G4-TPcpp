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

# Nom et prénom
Tang Quoc Khang 202364093

# Les fonctionnalités que vous avez choisi d’implémenter.
- Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.

- Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

- Si on lance sans –data-dir, saveLibraryData essaie d’écrire dans "" et échoue silencieusement.

# Les réponses aux questions, un paragraphe par questions est suffisant. (une phrase est insuffisant.)

Question 1 : C++

Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours. Montrez ici l’exemple sorti du code du projet.

Reponse 1 : La notion <sstream> que j'ai utilisé dans mon fichier book.cpp dans la méthode fromFileFormat.
Cette bibliothèque permet de prendre une chaine de caractères et de la manipuler comme si c'était un flux de données. Dans le projet, ca permet de prendre la ligne par exemple de user ou book et de la séparer à l'aide du "|". Ainsi, grace a la fonction getLine(), chaque partie de la ligne est extrait et directement assignee a un attribut du livre (title, author, isbn etc...).




Question 2 : Options de développement possible

Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Quelle solution technologique utiliseriez vous ? Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.

Reponse 2 : Pour géréer une biblothèque à une grande échelle qui contient de millions de livres je conseilleurais à Alexandrie de remplacer la sauvegarde de livre. La manière dont la sauvegarde est faite peu être bonne pour une petite quantité de livre, mais si on est sur des milliers ou mêmes des millions de livres, il sertait préférable de sauvegarder tous ces livres/utilisateurs sur une base de donnée externe et non en local. Pour combiner cette base de donnée avec son projet c++, je changerais le fichier fileManager pour connectér une base de donnée dans ce fichier. 