# Samuel Ringuette

# Fonctionnalités
- Nom à la place du userId lors de l'affichage des livres
- Tri lors de la recherche des livres par titre et auteur (quand on recherche par titre on trie par auteur et vice versa)
- Fonctionnalité de sauvegarde dans le journal
- Correction du bug

# Question 1
La fonctionnalité du projet qu'il n'y avait pas en détail dans les notes de cours est l'écriture dans un fichier soit le fichier journal. Voici mon utilisation

void FileManager::saveJournal(const string& choix, const string& description){
    filesystem::path journalPath = filesystem::path("data") / "journal.txt";
    ofstream file(journalPath, ios::app);
    if (!file.is_open()) {
        cout << "Le fichier " << journalPath << " n'a pas pu être ouvert.\n";
    }else{
        time_t maintenant = time(nullptr);
        tm* dateHeure = localtime(&maintenant);
        file << put_time(dateHeure, "%Y-%m-%d %H:%M:%S") << " - [" << choix << "] " << description << "\n";
    }
}

Pour utiliser cette fonctionnalité, il faut premièrement définir le chemin pour ensuite ouvrir le fichier avec ofstream. Aussi, il faut verifier que le fichier à bien été ouvert. Finalement on peut écrir ce qu'on veut dans le fichier

# Question 2
Je proposerais un système de base de données comme mysql à la place de fichiers texte pour la gestion de la bibliothèque. Ceci permettrait d'avoir des types de données plus strict, une meilleure efficacité lors de la recherche, de l'ajout ou du retrait et ceci permettrait à plusieurs système de travailler avec les mêmes données en même temps