<p align="center">
  <img width="100px" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png" alt="Brasão da Ufersa" />
</p>

<h1 align="center">📒 Dicionário com Hash</h1>
<p align="center"><b>Projeto do Laboratório de Algoritmos e Estruturas de Dados 2</b></p>

<div align="center">

![Status](https://img.shields.io/badge/Status-Em%20desenvolvimento-yellow)
![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue.svg?logo=c&logoColor=white)
![Suporte](https://img.shields.io/badge/Suporte-Windows%20%7C%20Linux-blue)

</div>

<br>

<h2>📄 Sobre o Projeto</h2>
Aplicação que tem a função de um dicionário, permitindo que o usuário registre palavras e seus significados, incluindo funções para consultar registros bem como editar e excluir termos inseridos.

<br>

<h2>📝 Funcionalidades</h2>

Este projeto implementa um dicionário que utiliza uma tabela hash para armazenar palavras e seus significados. O usuário pode:  
- Adicionar palavras e definições  
- Buscar palavras  
- Editar palavras e significados 
- Remover palavras  
- Salvar e carregar o dicionário de um arquivo texto

<br>

## 🏗️ Estrutura do Projeto  

- `include/` — arquivos `.h` (headers)  
- `src/` — arquivos `.c` com implementação  
- `apps/` — arquivo principal `main.c`  
- `dicionario.txt` — arquivo de dados onde o dicionário é salvo (gerado automaticamente)

---
<br>

## 💻 Como Compilar e Executar

### 🗹 Requisitos  
- GCC instalado (MinGW para Windows, GCC padrão no Linux)  
- Terminal/Prompt de comando

---

## 🪟 Windows
1. Abra o PowerShell ou Prompt de Comando (cmd)
2. Navegue até a pasta do projeto:
```
cd C:\Users\seunome\Dicionario_com_Hash
```
3. Compile o projeto:
```
gcc apps/main.c src/dict.c src/listaD.c src/util.c -Iinclude -o main.exe
```
4. Execute o programa:
```
.\main.exe
```
5. Após a execução, o arquivo `dicionario.txt` será gerado na pasta do projeto.
---

## 🐧 Linux
1. Abra o terminal
2. Navegue até a pasta do projeto:
```
cd ~/Dicionario_com_Hash
```
3. Compile o projeto:
```
gcc apps/main.c src/dict.c src/listaD.c src/util.c -Iinclude -o main
```
4. Execute o programa:
```
./main
```
5. Após a execução, o arquivo `dicionario.txt` será gerado na pasta do projeto.
---
<br>

# 🧑‍💻 desenvolvedores 
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/155568241?v=4](https://avatars.githubusercontent.com/u/155568241?v=4](https://avatars.githubusercontent.com/u/155568241?v=4" width=115><br><sub> Maria Francisca </sub>](https://github.com/mariafr73) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/106347376?v=4" width=115><br><sub> Alice Pinheiro </sub>](https://github.com/AliceSantoi) |
| :------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/157031016?v=4](https://avatars.githubusercontent.com/u/155568241?v=4](https://avatars.githubusercontent.com/u/155568241?v=4" width=115><br><sub> Gabrielle Naiare </sub>](https://github.com/gabinaiare) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/218805338?v=4" width=115><br><sub> Pedro Cordeiro </sub>](https://github.com/pedrocordeiro-l)| :------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/196652464?v=4](https://avatars.githubusercontent.com/u/155568241?v=4](https://avatars.githubusercontent.com/u/155568241?v=4" width=115><br><sub> Felipe Chaves </sub>](https://github.com/FelipeChl)
