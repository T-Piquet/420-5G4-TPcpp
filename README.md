# TP C++ - Systeme de Gestion de Bibliotheque

**Nom et prenom :** Noah Lefebvre

## Construire et executer le projet

Voici les lignes de commandes pour compiler et lancer le projet :
```bash
mkdir build
cd build
cmake ..
make
./bibliotheque -d ../data
```

## Fonctionnalites implementees

- **Completion du code manquant :** Implementation de la classe `Book` dans `book.cpp` a partir du fichier d'entete `book.h`.
- **Correction de bug :** Verification des chemins de fichiers vides dans `FileManager::saveLibraryData` quand l'application est lancee sans l'argument `--data-dir` (`-d`). Un message explicite est affiche et la sauvegarde est ignoree.
- **Journal d'activites (obligatoire) :** Creation et mise a jour du fichier `activity.log` en mode ajout (`ios::app`) avec la date et l'heure (`YYYY-MM-DD HH:MM:SS`) pour enregistrer les ajouts, suppressions, emprunts, retours et sauvegardes.
- **Interface et Experience Utilisateur :** Affichage du nom complet de l'utilisateur emprunteur a la place de son id pendant la recherche des livres.
- **Gestion des Donnees :** Tri des livres par titre ou par auteur lors de l'affichage et des recherches avec la fonction `std::sort` de la bibliotheque standard (`<algorithm>`).

## Veille technologique

### Question 1 : Notion C++ (`std::unique_ptr`)

Une notion qu'on a peu vue en cours, ce sont les smart pointers, surtout unique_ptr. En cours, on a vu qu'avec new il faut faire delete nous meme. Un unique_ptr fait ca tout seul donc quand il est detruit, il libere la memoire de l'objet.

Dans mon projet, la bibliotheque garde ses livres comme ca dans library.h :

```cpp
vector<unique_ptr<Book>> books;
```

Et on ajoute un livre avec make_unique (dans library.cpp) :

```cpp
books.push_back(make_unique<Book>(book));
```

Quand on supprime un livre avec books.erase(it), le livre est detruit automatiquement. Il n'y a aucun delete dans le projet, donc pas de fuite de memoire. Pour acceder a un livre sans en devenir le proprietaire, on utilise .get(), qui donne un pointeur normal Book*.

### Question 2 : Options de developpement possibles pour une grande bibliotheque

Le programme garde tout en memoire et sauvegarde dans des fichiers texte. C'est correct pour quelques livres, mais pas beaucoup et ca fait plusieurs choses, les recherches sont pas simples, on reecrit tout le fichier a chaque sauvegarde donc c'est pas trop pratique.

Je proposerais d'utiliser une base de donnees a la place, avec trois tables : livres, utilisateurs et emprunts. Les index pour les titres et avoir une table auteur ca rendrait les recherches plus rapides et plus simples.