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


# Veille Technologique

## Giancarlo Vardaro
### TP C++

### Fonctionnalites Choisies :
- Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres (Afficher tous les livres)
- Tri des résultats par titre, auteur pour l’affichage (Soit par auteur, par titre ou ne pas trier)

### Question 1

Une fonctionnalite que nous n'avons peu vu en cours est celle du temps et le formattage du temps. l'exemple sorti du code revient a ceci:
```cpp
  auto now = chrono::system_clock::now();
  time_t temps = chrono::system_clock::to_time_t(now);
  tm *tempsLocal = localtime(&temps);
  logFile << put_time(tempsLocal, "%Y-%m-%d %H:%M:%S") << " - [" << action
          << "] " << titre << "|" << auteur << "|" << isbn << "|"
          << int(disponible) << "|" << nomEmprunteur << "\n";
  logFile.close();
```

Avec les librairies iomanip, ctime et chrono

Chrono permet de recuperer l'heure regler sur le systeme d'exploitation qui execute le programme. Ensuite, on doit transferer la variable now (temps de l'ordi) en time_t afin qu'on puisse utiliser les methodes classiques de cpp (Premierement transformer en temps local et ensuite formatter de la maniere que l'on veut pour l'affichage avec put_time). J'ai utiliser cette notion pour la journalisation des evenements pour l'ajout, le retrait et l'emprunt d'un livre.

### Question 2

Il faudrait utiliser un SGBD comme MySQL qui permet d'acceder efficacement aux donnees et qui va permettre plusieurs utilisateurs simultanes d'utiliser le systeme lorsque la base de donnees est hebergee sur soit un serveur local ou un serveur distant. C'est plus adapte car lorsqu'il arrive le cas qu'il faut plusieurs gestionnaires avec plusieurs ordinateurs, le format fichier text ne convient plus. des operations d'ecriture en meme temps qu'un autre personne peut corrompre des fichiers de donnees. 