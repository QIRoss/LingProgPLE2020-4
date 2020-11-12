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
    << "    <style>"
    << "        body{ margin-left: 24vw; width: 50vw;}"
    << "    </style>"
    << "	<body align=\"center\">\n"
    << "			<h1>Resultados</h1>\n"
    << "        <script>\n"
    << "            const queryString = window.location.search;\n"
    << "            const urlParams = new URLSearchParams(queryString);\n"
    << "            console.log(urlParams);\n"
    << "            console.log(resultsList);\n"
    << "        </script>\n"
    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}