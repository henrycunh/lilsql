#include <cstdio>
#include "Result.cpp"
#include "../Helpers.cpp"
#include "../Structures.cpp"

Result createTable(vector<string> args, Database& context) {
    // Fetching the data from arguments
    string tableName = args[0];
    Table * table = context.getTable(args[0]);
    if (table == NULL) {
        bool hasInvalidFields = false;
        vector<Field> fieldList;
        
        log("CREATING TABLE " + tableName);
        vector<string> fieldSourceList = splitString(args[1], ";");
        
        for (const auto& fieldSource : fieldSourceList) {
            Field field = Field::fromString( fieldSource );
            if (field.valid) {
                fieldList.push_back(field);
            } else {
                log("Invalid field: " + fieldSource);
                hasInvalidFields = true;
            }
        }

        Table newTable = Table(tableName);
        newTable.fields = fieldList;
        newTable.init();
        context.addTable(newTable);
    } else {
        log("Table already exists");
    }

    return Result("yes");
}

Result removeTable(vector<string> args, Database& context) {
    string tableName = args[0];
    int status = context.removeTable(tableName);
    if (status) {
        log("DELETING TABLE " + tableName);
        return Result("yes");
    } else {
        log("Table doesn't exists");
        return Result("no");
    }
}

Result showTable(vector<string> args, Database& context) {
    string tableName = args[0];
    Table * table = context.getTable(tableName);
    if (table == NULL) {
        log("Table doesn't exists");
        return Result("no");
    }

    cout << "===============================" << endl;
    cout << "| Tabela                      |" << endl;
    cout << "===============================" << endl;
    cout << "| NOME         | REGISTROS    |" << endl;
    cout << "|-----------------------------|" << endl;
    printf ("| %-12s | %-12d |\n", table->name.c_str(), table->rowCount);
    cout << "===============================" << endl;
    cout << endl;
    cout << "===============================" << endl;
    cout << "| Campos                      |" << endl;
    cout << "===============================" << endl;
    cout << "| NOME         | TIPO         |" << endl;
    cout << "|-----------------------------|" << endl;
    for (int i = 0; i < table->fields.size(); i++) {
        Field field = table->fields[i];
        printf ("| %-12s | %-12s |\n", field.name.c_str(), field.type.c_str());
    }
    cout << "===============================" << endl;
    return Result("yes");
}

Result listTables(vector<string> args, Database& context) {
    cout << "===============================" << endl;
    cout << "| Tabela                      |" << endl;
    cout << "===============================" << endl;
    cout << "| NOME         | REGISTROS    |" << endl;
    cout << "|-----------------------------|" << endl;
    for (int i = 0; i < context.tableCount; i++) {
        Table table = context.tables[i];
        printf ("| %-12s | %-12d |\n", table.name.c_str(), table.rowCount);
    }
    cout << "===============================" << endl << endl;
    return Result("yes");
}