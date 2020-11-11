#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    cout << "Content-type: text/html\n\n"
    << "<!DOCTYPE html>\n"
    << "<html>\n"
    << "	<head>\n"
    << "		<title>\n"
    << "			Page Fetcher\n"
    << "		</title>\n"
    << "	</head>\n"
    << "    <style>"
    << "        form{ margin: 10vh;}"
    << "    </style>"
    << "	<body align=\"center\">\n"
    << "		<header>\n"
    << "			<h1>Desenvolvido por Lucas de Queiroz dos Reis</h1>\n"
    << "			<h2>lucasqreis@poli.ufrj.br</h2>\n"
    << "		</header>\n"

    << "        <form action=\"fetchPage\" method=\"GET\">"
    << "            <label for=\"toSearch\">Digite uma pagina que deseja capturar:</label>"
    << "            <input type=\"text\" id=\"toSearch\" name=\"toSearch\"><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "        <form action=\"readPostgres\" method=\"GET\">"
    << "            <label for=\"toRead\">Digite algo pagina que deseja escrever no banco:</label>"
    << "            <input type=\"text\" id=\"toRead\" name=\"toRead\"><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "        <form action=\"writePostgres\" method=\"POST\">"
    << "            <label for=\"toWrite\">Digite algo pagina que deseja escrever no banco:</label>"
    << "            <input type=\"text\" id=\"toWrite\" name=\"toWrite\"><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}