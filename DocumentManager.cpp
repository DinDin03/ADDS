#include "DocumentManager.h"

// Constructor (if any specific initialization is required)
DocumentManager::DocumentManager() {
    // Initialization code (if any)
}

// Implement the addDocument method
void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    Document doc = {name, id, license_limit, 0};
    name_to_docid[name] = id;
    documents[id] = doc;
}

// Implement the addPatron method
void DocumentManager::addPatron(int patronID) {
    registered_patrons.insert(patronID);
}

// Implement the search method
int DocumentManager::search(const std::string& name) {
    if (name_to_docid.find(name) != name_to_docid.end()) {
        return name_to_docid[name];
    }
    return 0; // not found
}

// Implement the borrowDocument method
bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (documents.find(docid) == documents.end() || 
        registered_patrons.find(patronID) == registered_patrons.end()) {
        return false; // Invalid docid or patronID
    }

    Document &doc = documents[docid];
    if (doc.borrowed_count < doc.license_limit &&
        doc.patrons_borrowed.find(patronID) == doc.patrons_borrowed.end()) {
        doc.borrowed_count++;
        doc.patrons_borrowed.insert(patronID);
        return true;
    }
    return false; // Can't be borrowed
}

// Implement the returnDocument method
void DocumentManager::returnDocument(int docid, int patronID) {
    if (documents.find(docid) != documents.end() &&
        registered_patrons.find(patronID) != registered_patrons.end() &&
        documents[docid].patrons_borrowed.find(patronID) != documents[docid].patrons_borrowed.end()) {
        
        Document &doc = documents[docid];
        doc.borrowed_count--;
        doc.patrons_borrowed.erase(patronID);
    }
}
