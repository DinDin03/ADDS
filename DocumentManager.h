#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

class DocumentManager {
private:
    struct Document {
        std::string name;
        int id;
        int license_limit;
        int borrowed_count;
        std::unordered_set<int> patrons_borrowed;
    };

    std::unordered_map<std::string, int> name_to_docid;
    std::unordered_map<int, Document> documents;
    std::set<int> registered_patrons;

public:
    // Constructor
    DocumentManager();

    // Add a new document to the system
    void addDocument(const std::string& name, int id, int license_limit);

    // Register a new patron
    void addPatron(int patronID);

    // Search for a document by its name
    // Returns the document ID if found, otherwise returns 0
    int search(const std::string& name);

    // Borrow a document
    // Returns true if the operation is successful, otherwise returns false
    bool borrowDocument(int docid, int patronID);

    // Return a borrowed document
    void returnDocument(int docid, int patronID);
};

#endif // DOCUMENTMANAGER_H
