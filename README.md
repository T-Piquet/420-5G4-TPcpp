# Raphael Maceno

## Fonctionalité
1. Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.
2. Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).
3. Journal d’activités
4. Correction du bug. Ajout de fonction de départ qui permet d'enregistrer les données sans données de fichier de départ

## Question 1 : C++
Je vais expliquer comment j'ai fait le journal de progression.
On regarde toujours si le fichier existe ou pas puis si il existe on continu nos action sinon
on créer un nouveau fichier. La première chose a faire est de lire les informations qui sont déja dans le fichier grace ifstream. Si il a des information il l'ajoute au message sinon il ajoute rien. Ensuite on ouvre le fichier avec ofstream puis on écrit dans le fichier notre messsage. On s'assure de fermer le fichier à la fin.

## Question 2 : Options de développement possible
Une eventuel solution serait que le c++ deveinne juste un backend et que le frontend soit du html ou react ou autre. Cela permettrait un facilité pour avoir une interface plus adapté a l'expérience utilisateur. Puis pour les data on utiliserait une base de données selfhost pour avoir un controle total sur l'epasce, la sécurité et les dénnées. Je sait que faire du selfhost c'est beaucoup plus compliquer mais je pense que c'est fesable avec l'ia (en gardant un controle sur le code) et beaucoup de patience. 

## Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`