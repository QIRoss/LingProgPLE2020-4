#include <iostream>
#include "templateEngine.hh"

using namespace std;

void templateEngine::generateTopHTML(){
    cout << "Content-type: text/html\n\n"
    << "<!DOCTYPE html>\n"
    << "<html>\n"
    << "	<head>\n"
    << "		<title>\n"
    << "			Lucas de Queiroz dos Reis API Postgres Interface Web\n"
    << "		</title>\n"
    << "	</head>\n"
    << "    <style>"
    << "        body {background-color: whitesmoke;}"
    << "        #navHeader{background-color: black; text-align: center; margin: 0px; width: 100%; display: flex; flex-direction: row; top:0px;}\n"
    << "        #logo {width: 7rem; height: auto;}\n"
    << "        #headerTitle {color: white; height: auto;}\n"
    << "        form {margin: 30px; border: 10px solid #000;}\n"
    << "        footer {bottom: 0px; background-color: black; color:white;}\n"
    << "    </style>\n"
    << "	<body align=\"center\">\n"
    << "		    <header id=\"navHeader\">\n"
    << "                <img id=\"logo\" src=\"https://qiross-portfolio-webpage.vercel.app/qiross.png\" alt=\"QIRoss\">\n"
    << "                <h1 id=\"headerTitle\">API PostgreSQL em CGI C++ Chromium</h1>\n"
    << "                <a href=\"/cgi-bin/main\">Back to Main Page</a>\n"
    << "		    </header>\n";
}

void templateEngine::generateBottomHTML(){
    cout 
    << "        <section>\n"
    << "                <h1>Contato</h1>\n"
    << "			    <h3>Desenvolvido por Lucas de Queiroz dos Reis</h2>\n"
    << "			    <h3>lucasqreis@poli.ufrj.br</h3>\n"
    << "        </section>\n"

    << "        <footer>\n"
    << "            <p id=\"copyright\"><small>Copyright©</small>2020 QIRoss .all rights reserved</p>\n"
    << "        </footer>\n"

    << "	</body>\n"
    << "</html>\n" ;
}

void templateEngine::generatePreviewImgForm(){
    cout 
    << "        <form action=\"imgPreview\" method=\"GET\">\n"
    << "            <label for=\"toSearch\">Digite a url da imagem que deseja capturar(preview):</label><br>\n"
    << "            <input type=\"text\" id=\"toSearch\" name=\"toSearch\" placeholder=\"url\" required><br><br>\n"
    << "            <input type=\"submit\" value=\"Buscar\">\n"
    << "        </form>\n";
}

void templateEngine::generateReadDbForm(){
    cout
    << "        <form action=\"readDb\" method=\"GET\">\n"
    << "            <label for=\"toRead\">Digite o titulo da imagem que deseja LER do banco:</label><br>\n"
    << "            <input type=\"text\" id=\"toRead\" name=\"toRead\" placeholder=\"titulo da imagem\"required><br><br>\n"
    << "            <input type=\"submit\" value=\"Buscar\">\n"
    << "        </form>\n";
}

void templateEngine::generateWriteDbForm(){
    cout
    << "        <form action=\"writeDb\" method=\"GET\">\n"
    << "            <label for=\"toWriteTitle\">Digite o Titulo a URL que deseja ESCREVER no banco:</label><br><br>\n"
    << "            <input type=\"text\" id=\"toWriteTitle\" name=\"toWriteTitle\" placeholder=\"insira o titulo aqui\" required><br><br>\n"
    << "            <input type=\"text\" id=\"toWriteTitle\" name=\"toWriteTitle\" placeholder=\"insira a url aqui\" required><br><br>\n"
    << "            <input type=\"submit\" value=\"Salvar\">\n"
    << "        </form>\n";
}

void templateEngine::generateInnerImgPreviewPage(){
    cout
    << "			<h1>Resultados</h1>\n"
    << "            <img src=\" \" id=\"image\"/>\n"
    << "            <form action=\"writeDb\" method=\"GET\">\n"
    << "                <label for=\"toWriteTitle\">Digite um titulo para imagem:</label><br>\n"
    << "                <input type=\"text\" id=\"toWriteTitle\" name=\"toWriteTitle\" required><br><br>\n"
    << "                <input type=\"submit\" value=\"Salvar\">\n"
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
    << "        </script>\n";
}

void templateEngine::generateAllForms(){
    generatePreviewImgForm();
    generateReadDbForm();
    generateWriteDbForm();
}

void templateEngine::generateMainPage(){
    generateTopHTML();
    generateAllForms();
    generateBottomHTML();
}

void templateEngine::generateImgPreviewPage(){
    generateTopHTML();
    generateInnerImgPreviewPage();
    generateBottomHTML();
}

void templateEngine::generateReadDbPage(){
    generateTopHTML();
    
    generateBottomHTML();
}

void templateEngine::generateWriteDbPage(){
    generateTopHTML();
    
    generateBottomHTML();
}
