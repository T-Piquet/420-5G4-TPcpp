# Configuration et Instructions

## Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.  
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet :
```bash
mkdir build
cd build
cmake ..
make
```

## Répertoire data
Il contient 2 fichiers `books.txt` et `users.txt` que vous pouvez utilisez pour tester votre code.  
Pour cela, il suffit de donner le chemin vers le répertoire data avec l'application :
```bash
bibliotheque -d <chemin_vers_data>
```

---

## ⚠️ INFO
* **Nom / Prénom :** Guillaume Goyette
* **Fonctionnalité choisie (Interface) :** Détection des doublons plus intelligente
* **Fonctionnalité choisie (Gestion des Données) :** Triage des reponse avec STD
* **Ajout du journal de sauvegarde :** 

---

## Questions !

### Question 1 : C++
Je crois que nous n'avons pas vraiment parlé du management des fichiers en général. Comment les DIR sont callés et handled by filesystem.

```cpp
void FileManager::createBackup() {
    if (!fileExists(booksFileName)) {
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }else{
        filesystem::remove(booksFileName + ".backup");
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }
    
    if (!fileExists(usersFileName)) {
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }else{
        filesystem::remove(usersFileName + ".backup");
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }
}
```

Ceci n'est sûrement pas la meilleure façon de handle la situation.

### Question 2 : Options de développement possibles
Je crois le plus important serait d'avoir un database hors code. Ceci serait mieux que chercher un file ou de loader tous les livres locally.

On peut prendre facilement soit de SQL, MariaDB, etc. Ceci pourrait centrer les données et peut laisser les utilisateurs faire beaucoup plus de backup (Main, Onsite, Offsite) multiplicative. Un peu comme Anna's Archive.
