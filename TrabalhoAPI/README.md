# TRABALHO FINAL LINGUAGENS DE PROGRAMAÇÃO
# LUCAS DE QUEIROZ DOS REIS
# DRE 114074787

# API C++ PARA OUTRAS LINGUAGENS

# Template Engine em C++ de uma CGI + API PostgreSQL

# FUNCIONALIDADES:

Interface em SSR (Server Side Rendering) utilizando uma Template Engine (header and footer adicionáveis a qualquer página);

Preview de Imagens com a Fetch API do Javascript.

Buscar no Banco de dados PostgreSQL.

Escrever no Banco de dados PostgreSQL.

Enviar por email para mim utilizando emailjs API.
Prevenção de injeção de SQL.

# Como foi feito:

Utilizando APACHE Webserver, o makefile serve executáveis para o WebServer que funcionam como páginas dinâmicas em HTML com inserção de código javascript encapsuladas.
Algumas funcionalidades como Fetch API do Javascript foram utilizadas, porém a biblioteca de CGI captura a imagem da mesma maneira que a API Fetch.

Uma Classe Database que integra a API Postgres e uma Classe Template Engine que gerencia as páginas compõe os executáveis.

A Busca no banco PostgreSQL consiste na criação de uma linha de comando:
SELECT url FROM memes WHERE title = '#';
onde # é o campo a ser buscado.

A escrita no banco de dados cria a seguinte linha:
INSERT INTO memes VALUES ('title','url');

Foi utilizado as libs cgicc e pqxx.

Todas as funções da Template Engine são compostas de gerar um topHTML e um bottomHTML.

O código do emailjs está implementado dentro da página de preview porém não está com um email configurado neste momento (eu utilizo este mesmo serviço em uma página real que administro).

SQL Injection consiste em uma técnica de extrair ou quebrar informação de um banco de dados SQL a partir de uma entrada não tratado ao banco de dados. Uma função que verifica todas as entradas foi criada a fim de impedir esta prática.
A função privada invalidCharacters trata as entradas.