#include <iostream>

using namespace std;


int main(int argc, char *argv[]){
    cout << "Content-type: text/html\n\n"
    << "<!DOCTYPE html>\n"
    << "<html>\n"
    << "	<head>\n"
    << "		<title>\n"
    << "			Results Page\n"
    << "		</title>\n"
    << "	</head>\n"
    << "	<body align=\"center\">\n"
    << "			<h1>Resultados</h1>\n"
    << "            <img src=\" \" id=\"image\"/>\n"
    << "            <form>\n"
    << "                <label for=\"toSave\">Digite um titulo para imagem:</label><br>"
    << "                <input type=\"text\" id=\"toSave\" name=\"toSave\" required><br><br>"
    << "                <input type=\"submit\" value=\"Salvar\">"
    << "            </form>\n"
    << "        <script>\n"
    << "            const url = new URLSearchParams(window.location.search).get('toSearch')\n"
    << "            fetch(url)\n"
    << "                .then(response => { \n"
    << "                return response.blob();\n"
    << "                })\n"
    << "                .then(blob => {\n"
    << "                    document.getElementById('image').src = URL.createObjectURL(blob);\n"
    << "                }); \n"
    << "        </script>\n"
    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}