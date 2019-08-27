# LilSQL
a very *smol* c++ based dbms

## Estrutura de diretórios
### Data
- `data/` Diretório que armazena os dados binários no sistema de arquivos
- `data/tables` Diretório que armazena os dados binários das tabelas
- `data/tables/{tableName}.dat` Arquivo binário da tabela
- `data/metadata.dat` Arquivo binário com os metadados do banco de dados
### Worker
- `workers/` Diretório que armazena a implementação dos diferentes setores de ação que o DBMS executará
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

