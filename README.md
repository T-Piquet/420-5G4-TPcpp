# Projet de gestion de bibliothèque

*Étienne Desaulniers*

## Fonctionnalités implémentées choisies:

** Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres **

** Tri des résultats par titre, auteur pour l’affichage **

** Correction du bug si on lance sans –data-dir **

## Question 1: C++

Une notion qu'on a pas vraiment abordée dans le cours est l'utilisation de l'en-tête **<ctime>**. J'ai utilisé cette en-tête pour pouvoir inscrire l'heure exacte a laquel une action à été enregistrée dans le fichier journal.

```C++
    const time_t now = time(nullptr);
    const tm* localTime = localtime(&now);

    if (localTime != nullptr) {
        file << put_time(localTime, "%Y-%m-%d %H:%M:%S") << " - " << "[" << action << "] " << message << '\n';
    }
```

Explication du code:

```C++
    const time_t now = time(nullptr);
```
- récupère l’heure actuelle et la stocke sous forme de secondes écoulées

```C++
    const tm* localTime = localtime(&now);
```
- convertit cette heure en date et heure locale

``` C++
    if (localTime != nullptr) {
```
- vérifie que la conversion a réussi avant d’utiliser le résultat

```C++
    file << put_time(localTime, "%Y-%m-%d %H:%M:%S") << " - " << "[" << action << "] " << message << '\n';
```
- écrit dans le fichier la date et l’heure formatées, suivies de l’action et du message

## Question 2: Options de développement possible

Pour gérer une bibliothèque pouvant contenir des millions de livres, je choisirais PostgreSQL, qui permet de stocker les livres, les utilisateurs et les emprunts dans une base de données. Le programme pourrait rester en C++ et communiquer avec PostgreSQL à l’aide d’une bibliothèque cliente, en envoyant des requêtes SQL pour rechercher ou modifier les données. Les index de la base de données aideraient à accélérer les recherches et le tri.