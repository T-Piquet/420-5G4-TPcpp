# Système de Gestion de Bibliothèque Personnelle

## Flavius Racoveanu

---

## Fonctionnalités implémentées
Le projet intègre les fonctionnalités principales suivantes :
* **numérotation automatique des ID utilisateurs**
* **Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).** 
* **Journal d'activités**

---

## Question 1 : C++
Une notion avancée utilisée dans ce projet est l'utilisation de la bibliothèque standard `<filesystem>`, introduite avec la norme C++17. Dans notre code, elle est notamment exploitée au sein du module `Journal` avec l'instruction `std::filesystem::create_directories("data");` ainsi que dans le `main.cpp` pour valider l'existence du répertoire de données. Avant C++17, la création de dossiers ou la vérification de l'existence de fichiers nécessitait l'utilisation d'API dépendantes du système d'exploitation. L'apport de `<filesystem>` permet de manipuler le système de fichiers de manière totalement portable, native et sécurisée. Grâce à cette fonctionnalité, le programme peut vérifier ou créer automatiquement l'arborescence nécessaire au stockage des journaux d'activité sans risque de plantage, garantissant ainsi une grande robustesse lors de l'exécution sur différentes plateformes.


## Question 2 : Options de développement possible
Pour faire face à une bibliothèque de l'envergure d'Alexandrie contenant des millions de livres, l'utilisation de fichiers textes atteint rapidement ses limites en termes de performance, d'intégrité et de concurrence d'accès. La solution la plus adaptée consisterait à migrer vers un SGBD relationnel robuste (comme PostgreSQL) ou une base de données orientée documents pour indexer efficacement les requêtes de recherche par ISBN, auteur ou titre. Pour interférer cette base de données avec le cœur du programme en C++, on pourrait concevoir une API REST ou gRPC (par exemple en C++ avec des bibliothèques comme *Crow* ou *Pistache*, ou via un micro-service intermédiaire). Le programme C++ communiquerait ainsi avec le serveur de base de données par le biais de requêtes HTTP/JSON ou de protocoles binaires optimisés, permettant de déporter la gestion massive des données, d'assurer la persistance transactionnelle (ACID) et de permettre à plusieurs utilisateurs d'interroger la bibliothèque simultanément sans saturer la mémoire locale.