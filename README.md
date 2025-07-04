
# 🌬️ Ozone  
  
**Ozone** é um monitor de sistema interativo feito em C para ambientes Unix/Linux, inspirado no `htop`. Ele exibe informações em tempo real sobre processos, uso da CPU, memória e mais — tudo via terminal, com uma interface amigável construída com `ncurses`.  
  
---  
  
## 🛠️ Funcionalidades  
  
- [ ] Lista de processos com PID e nome  
- [x] Uso da CPU e memória em tempo real  
- [ ] Interface interativa com `ncurses`  
- [ ] Ordenação por uso de CPU/MEM  
- [x] Exibição de tempo de atividade do sistema  
  
---  
  
## 🚀 Como compilar  
  
Você precisa de um compilador C e da biblioteca `ncurses`.  
  
### Dependências  
  
No Debian/Ubuntu:  
  
```
sudo apt update  
sudo apt install build-essential libncurses5-dev libncursesw5-dev
```
### Compilação

```bash
make
```

Ou manualmente:

```
gcc -o ozone main.c ui.c process.c -lncurses
```

----------

## 🖥️ Como usar

Execute o programa no terminal:

```bash
./ozone
```

Use as setas para navegar (quando implementado). Pressione `q` para sair.

----------

## 🧱 Estrutura do Projeto

```plaintext
ozone/
├── src/
│   ├── main.c        // Loop principal
│   ├── ui.c/.h       // Interface de usuário com ncurses
│   ├── process.c/.h  // Leitura de /proc
│   └── utils.c/.h    // Funções auxiliares
├── Makefile
└── README.md
```

----------

## 🎯 Objetivos do Projeto

-   Aprendizado de C e manipulação de processos no Linux
    
-   Entendimento do funcionamento do /proc
    
-   Experiência com interfaces de terminal usando `ncurses`
    
-   Criação de uma ferramenta leve e útil
    

## 🙋 Sobre

Projeto pessoal criado para fins de estudo. Contribuições são bem-vindas!
