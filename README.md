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

# Nom, Prénom
Rahman Ashifur
# DA
2152097

# Les fonctionnalités
1. La fonctionnalité que j'ai choisi d'implémentrer pour l'interface et expérience Utilisateur : 
La numérotation automatique des ID utilisateurs

2. La fonctionnalité que j'ai choisi d'implémenter pour la Gestion des Données :
Le tri des résultats par titre et auteur pour l'affichage

3. Le journal d'activités qui crée un fichier de journal de l'application. Il est conservé au fur et à mesure des sessions
Exemple : 
2026-10-16 17:51:18 - [SUPPRIMER LIVRE] ISBN: 55
2026-10-16 17:52:01 - [AJOUT UTILISATEUR] Name: Bobby, User ID: USR029
2026-10-16 18:09:53 - [AJOUT LIVRE] Formatage|TP|111|1|
2026-10-16 18:10:47 - [EMPRUNT LIVRE] Formatage|TP|111|0|Bob Billy
2026-10-16 23:35:31 - [RETOUR LIVRE] ISBN: 111


# Question 1
# L'utilisation de <ctime>
void journalActivites(const string& fichier, const string& action, const string& details) {
    ofstream journal(fichier, ios::app);
    if (journal.is_open()) {
        time_t maintenant = time(0);
        tm* dateTemps = localtime(&maintenant);
        journal << put_time(dateTemps, "%Y-%m-%d %H:%M:%S");
        journal << " - [" << action << "] " << details << endl;
        journal.close();
    } else {
        cout << "Erreur : Impossible de créer le journal d'activités" << endl;
    }
}

La fonction journalActivites utilise <ctime> et <iomanip> qui permet de récupérer et formater la date et l'heure.
ios::app permet d'ajouter les actions que nous fesons.
time_t maintenant = time(0) nous permet d'avoir l'heure actuelle
tm* dateTemps = localtime(&maintenant) va faire la conversion qui contient la date et l'heure comme année, mois, jour, heures, minutes et secondes.
put_time(dateTemps, "%Y-%m-%d %H:%M:%S") permet d'afficher la date dans un format (année, mois, jour, heures, minutes et secondes)
- [" << action << "] " << details << ici on fait qu'afficher l'action de l'utilisateur comme AJOUT, EMPRUNT, SUPPRIMER, AJOUT UTILISATEUR et RETOUR LIVRE
journal.close() permet de fermer le fichier après l'écriture


# Question 2
Pour améliorer la gestion de bibliothèque et permettre à la bibliothèque d'Alexandrie qui contient des millions de livres, je propose d'utiliser MySQL 
tout en restant avec C++. Avec MySQL, on peut organiser les informations comme les users et les books dans des tables et utiliser des id pour la recherche des livres. Nous pouvons utiliser MySQL Connector/C++ qui va nous donner l'option d'exécuter des requêtes SQL. Ceci va faciliter la gestion de la bibliothèque d'Alexandrie qui contient des millions de livres.
