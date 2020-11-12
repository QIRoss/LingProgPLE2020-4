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
    << "            <img src=\" \" id=\"image\"/>\n"
    << "        <script>\n"
    << "            const url = new URLSearchParams(window.location.search).get('toSearch')\n"
    << "            fetch(url)\n"
    << "                .then(response => { \n"
    << "                console.log(response);\n" 
    << "                return response.blob();\n"
    << "                })\n"
    << "                .then(blob => {\n"
    << "                    console.log(blob);\n"
    << "                    document.getElementById('image').src = URL.createObjectURL(blob);\n"
    << "                }); \n"
    << "        </script>\n"
    << "	</body>\n"
    << "</html>\n" ;
    return 0;
}