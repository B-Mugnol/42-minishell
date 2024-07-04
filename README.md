<h1 align="center"> 
	MiniShell
</h1>

<p align="center">
  O MiniShell é uma replicação de um shell mas não por completo, feito puramente em C
</p>

Indice
=================
<!--ts-->
  * [Sobre](#Sobre)
  * [Instalação](#instalacao)
  * [Como usar](#como-usar)
    * [Funcionalidades](#Funcionalidades)
<!--te-->

<h4 align="center"> 
	Status: ✅ Finalizado ✅
</h4>

## Sobre
  - MiniShell é um projeto da ecole 42 para replicar uma shell mas não por completo, o desafio é fazer um shell puramente em C
  com funçoes da libft (um outro projeto da ecole 42 aonde temos que refazer uma biblioteca de funções já existentes do C), e
  uma limitada lista de outras funções para conseguir fazer o projeto, sendo assim necessario planejamento como estruturar 
  funcionlidades do shell sem que uma coisa atrapalhe a outra.

## Instalação
  - Basta ter o clang instalado na sua maquina que tudo deve rodar bem.

## Como Usar
  - Baixe o repositório com Git clone, depois só rodar 'make' no terminal na pasta raiz do projeto e depois './minishell' e pronto só usar como um shell normal

  ## Funcionalidades
    - Histórico
    - aspas simples e duplas assim como a interpretação do '$'
    - redirecionamentos '<,>,<<,>>'
    - pipes ||
    - variaveis de ambiente assim como o '$?'
    - ctrl + C, ctrl + D, ctrl + \ (esse signal em especifico varia de sistema e teclado verifique aonde o seu está configurado)
    - buildtins: echo, cd, export, pwd, unset, env e exit
