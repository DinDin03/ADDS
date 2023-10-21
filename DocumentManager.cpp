#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

struct Document {
    string name;
    int id;
    int license_limit;
    int borrowed_count;
    unordered_set<int> patrons_borrowed;
};

class DocumentManager {
private:
    unordered_map<string, int> name_to_docid;
    unordered_map<int, Document> documents;
    set<int> registered_patrons;

public:
    void addDocument(string name, int id, int license_limit) {
        Document doc = {name, id, license_limit, 0};
        name_to_docid[name] = id;
        documents[id] = doc;
    }

    void addPatron(int patronID) {
        registered_patrons.insert(patronID);
    }

    int search(string name) {
        if (name_to_docid.find(name) != name_to_docid.end()) {
            return name_to_docid[name];
        }
        return 0; // not found
    }

    bool borrowDocument(int docid, int patronID) {
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

    void returnDocument(int docid, int patronID) {
        if (documents.find(docid) != documents.end() &&
            registered_patrons.find(patronID) != registered_patrons.end() &&
            documents[docid].patrons_borrowed.find(patronID) != documents[docid].patrons_borrowed.end()) {
            
            Document &doc = documents[docid];
            doc.borrowed_count--;
            doc.patrons_borrowed.erase(patronID);
        }
    }
};
