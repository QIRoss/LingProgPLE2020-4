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
    << "        form{ margin: 10vh; border: 10px solid #555;}"
    << "        body{ margin-left: 24vw; width: 50vw;}"
    << "    </style>"
    << "	<body align=\"center\">\n"
    << "		<header>\n"
    << "			<h1>Desenvolvido por Lucas de Queiroz dos Reis</h1>\n"
    << "			<h2>lucasqreis@poli.ufrj.br</h2>\n"
    << "		</header>\n"

    << "        <form action=\"results.cgi\" method=\"GET\">"
    << "            <label for=\"name\">Digite uma pagina que deseja capturar:</label>"
    << "            <input type=\"text\" id=\"name\" name=\"name\" required><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "        <form action=\"readPostgres\" method=\"GET\">"
    << "            <label for=\"toRead\">Digite algo pagina que deseja LER do banco:</label>"
    << "            <input type=\"text\" id=\"toRead\" name=\"toRead\"><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "        <form action=\"writePostgres\" method=\"POST\">"
    << "            <label for=\"toWrite\">Digite algo pagina que deseja ESCREVER no banco:</label>"
    << "            <input type=\"text\" id=\"toWrite\" name=\"toWrite\"><br><br>"
    << "            <input type=\"submit\" value=\"Submit\">"
    << "        </form>"

    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}