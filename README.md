# LilSQL
a very *small* c++ based dbms

## Estrutura de diretórios
### Data
- `data/` Diretório que armazena os dados binários no sistema de arquivos
- `data/tables` Diretório que armazena os dados binários das tabelas
- `data/tables/{tableName}.header` Arquivo com os metadados da tabela
- `data/tables/{tableName}.data` Arquivo com os dados da tabela
- `data/database.header` Arquivo com os metadados do banco de dados
### Worker
- `workers/` Diretório que armazena a implementação dos diferentes setores de ação que o DBMS executará
- `workers/Broker.cpp`
    - Gerencia o dispatch table e interfaceia os workers
- `workers/Result.cpp`
    - Define estrutura do resultado que os workers enviam
- `workers/TableWorker.cpp`
    - Interfaceia as ações de gerenciamento de tabelas
- `Commands.cpp`
    - Define a estrutura e o tratamento dos comandos
- `CommandsSource.csv`
    - Arquivo de campos separados por virgula contendo todos os comandos disponíveis, sua quantidade de argumentos e uma breve descrição
- `Helpers.cpp`
    - Contém funções que ajudam na implementação de algumas funcionalidades
- `Parser.cpp`
    - Contém implementação do interpretador que processa uma requisição e retorna um comando e sua validez
- `Structures.cpp`
    - Contém implementação das estruturas e seus metadados

