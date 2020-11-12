#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    cout << "Content-type: text/html\n\n"
    << "<!DOCTYPE html>\n"
    << "<html>\n"
    << "	<head>\n"
    << "		<title>\n"
    << "			Main Page\n"
    << "		</title>\n"
    << "	</head>\n"
    << "    <style>"
    << "        body {background-color: whitesmoke;}"
    << "        #navHeader{background-color: black; text-align: center; margin: 0px; width: 100%; display: flex; flex-direction: row; top:0px;}\n"
    << "        #logo {width: 7rem; height: auto;}\n"
    << "        #headerTitle {color: white; height: auto;}\n"
    << "        form {margin: 30px; border: 10px solid #000;}\n"
    << "        footer {bottom: 0px; background-color: black; color:white;}\n"
    << "    </style>"
    << "	<body align=\"center\">\n"
    << "		    <header id=\"navHeader\">\n"
    << "                <img id=\"logo\" src=\"https://qiross-portfolio-webpage.vercel.app/qiross.png\" alt=\"QIRoss\">\n"
    << "                <h1 id=\"headerTitle\">API PostgreSQL em CGI C++ Chromium</h1>\n"
    << "		    </header>\n"
    << "        <form action=\"results.cgi\" method=\"GET\">"
    << "            <label for=\"toSearch\">Digite a imagem que deseja capturar(preview):</label><br>"
    << "            <input type=\"text\" id=\"toSearch\" name=\"toSearch\" required><br><br>"
    << "            <input type=\"submit\" value=\"Buscar\">"
    << "        </form>"

    << "        <form action=\"readPostgres\" method=\"GET\">"
    << "            <label for=\"toRead\">Digite a imagem que deseja LER do banco:</label><br>"
    << "            <input type=\"text\" id=\"toRead\" name=\"toRead\"><br><br>"
    << "            <input type=\"submit\" value=\"Buscar\">"
    << "        </form>"

    << "        <form action=\"writePostgres\" method=\"POST\">"
    << "            <label for=\"toWrite\">Digite a URL que deseja ESCREVER no banco:</label><br>"
    << "            <input type=\"text\" id=\"toWrite\" name=\"toWrite\"><br><br>"
    << "            <input type=\"submit\" value=\"Buscar\">"
    << "        </form>"

    << "        <section>\n"
    << "                <h1>Contato</h1>\n"
    << "			    <h3>Desenvolvido por Lucas de Queiroz dos Reis</h2>\n"
    << "			    <h3>lucasqreis@poli.ufrj.br</h3>\n"
    << "        </section>\n"

    << "        <footer>\n"
    << "            <p id=\"copyright\"><small>Copyright©</small>2020 QIRoss .all rights reserved</p>"
    << "        </footer>\n"

    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}