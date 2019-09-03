#include <vector>
#include <string>
#include <fstream>
#include "Helpers.cpp"

using namespace std;

class Field {
public:
    string type;
    string name;
    bool valid;

    Field(bool valid){
        this->valid = valid;
    }

    Field(string name, string type){
        this->name = name;
        this->type = type;
        this->valid = true;
    }

    static Field fromString(string source){
        vector<string> args = splitString(source, ":");
        if (args.size() == 2) {
            return Field(args[0], args[1]);
        } else {
            return Field(false);
        }
    }
    
};

class Table {
public:
    string name;
    int rowCount;
    vector<Field> fields;
    string fieldIndex;

    Table(){
        this->rowCount = 0;
    }

    Table(string name) {
        this->name = name;
        this->rowCount = 0;
        this->fieldIndex = "None";
    }

    ~Table(){
        this->fields = vector<Field>(); 
    }

    void addField(string type, string name) {
        this->fields.push_back(Field(type, name));
    }

    void saveHeader(){
        ofstream tableHeaderFile("data/tables/" + name + ".header");
        tableHeaderFile << (*this);
    }

    static Table loadFromHeader(string name){
        ifstream tableHeaderFile("data/tables/" + name + ".header");
        Table table;
        tableHeaderFile >> table;
        return table;
    }

    void init(){
        ofstream tableDataFile("data/tables/" + name + ".data");
        this->saveHeader();
        tableDataFile << endl;
    }

    // Override nas operações de stream das Tabelas
    friend istream & operator>>(istream& is, Table& table){
        string fieldSourceList;

        is >> table.name;
        is >> table.rowCount;
        is >> table.fieldIndex;
        is >> fieldSourceList;

        for (auto& fieldSource : splitString(fieldSourceList, ";")) {
            vector<string> fieldData = splitString(fieldSource, ":");
            if(fieldData.size() == 2) {
                table.addField(fieldData[0], fieldData[1]);
            }
        }

        return is;
    }

    friend ostream & operator<<(ostream& os, Table& table){
        string fieldSourceList;
        
        os << table.name << endl;
        os << table.rowCount << endl;
        os << table.fieldIndex << endl;

        for (auto& field: table.fields) {
            fieldSourceList.append(field.name + ":" + field.type + ";");
        }

        os << fieldSourceList << endl;
    }

};


class Database {
public:
    int tableCount;
    vector<Table> tables;

    Database(){
        this->tableCount = 0;
    }

    ~Database(){
        this->tables = vector<Table>();
    }

    void save(){
        ofstream dbFile("data/database.header");
        dbFile << (*this);
    }

    static Database load(){
        ifstream dbFile("data/database.header");
        Database db;
        dbFile >> db;
        return db;
    }

    Table* getTable(string tableName) {
        for( auto& Table : this->tables ) {
            if (Table.name == tableName) {
                return &Table;
            }
        }
        return NULL;
    }

    void addTable(Table table){
        this->tables.push_back(table);
        this->tableCount++;        
    }

    bool removeTable(string tableName){
        int idx = -1;
        for (int i = 0; i < this->tableCount; i++) {
            if (this->tables[i].name == tableName) {
                idx = i;
            }
        }
        if (idx == -1) {
            return false;
        }
        this->tables.erase(this->tables.begin() + idx);
        this->tableCount--;
        return true;
    }

    friend istream & operator>>(istream& is, Database& database){
        is >> database.tableCount;
        int tableCount = database.tableCount;
        for (int i = 0; i < tableCount; i++) {
            Table currentTable;
            is >> currentTable;
            database.tables.push_back(currentTable);
        }
        return is;
    }

    friend ostream & operator<<(ostream& os, Database& database){
        os << database.tableCount << endl;
        for (int i = 0; i < database.tableCount; i++) {
            os << database.tables[i];
        }
        return os;
    }

};

