#include <iostream>
#include <vector>
#include <string>

#include <pqxx/pqxx>

#include "templateEngine.hh"
#include "database.hh"

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

using namespace std;
using namespace cgicc;

void templateEngine::generateTopHTML(){
    cout << "Content-type: text/html\n\n"
    << "<!DOCTYPE html>\n"
    << "<html>\n"
    << "	<head>\n"
    << "		<title>\n"
    << "			Lucas de Queiroz dos Reis API Postgres\n"
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
    << "                <h1 id=\"headerTitle\">API Postgres e CGIs gerenciado por C++</h1>\n"
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
    << "            <p id=\"copyright\"><small>Copyright©</small><span id=\"year\"></span> QIRoss .all rights reserved</p>\n"
    << "        </footer>\n"

    << "        <script>\n"
    << "            document.getElementById(\"year\").innerHTML = new Date().getFullYear();\n"
    << "        </script>\n"

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
    << "            <input type=\"text\" id=\"toWriteUrl\" name=\"toWriteUrl\" placeholder=\"insira a url aqui\" required><br><br>\n"
    << "            <input type=\"submit\" value=\"Salvar\">\n"
    << "        </form>\n";
}

void templateEngine::generateInnerImgPreviewPage(){
    cout
    << "			<h1>Resultados</h1>\n"
    << "            <img src=\" \" id=\"image\"/>\n"
    << "            <form id=\"form\">\n"
    << "                <label for=\"toWriteTitle\">Digite um titulo para imagem:</label><br>\n"
    << "                <input type=\"text\" id=\"toWriteTitle\" name=\"toWriteTitle\" required><br><br>\n"
    << "                <input id=\"button\"type=\"submit\" value=\"Envie para o admin\">\n"
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
    // EMAIL SCRIPT
    << "        <script>\n"
    << "            const btn = document.getElementById('button');"
    << "            document.getElementById('form')"
    << "            .addEventListener('submit', function(event) {"
    << "            event.preventDefault();"
    << "            btn.value = 'Sending...';"
    << "            const serviceID = 'default_service';"
    << "            const templateID = 'template_HtIWhoRJ';"
    << "            emailjs.sendForm(serviceID, templateID, this)"
    << "                .then(() => {"
    << "                btn.value = 'Send Email';"
    << "                alert('Sent!');"
    << "                }, (err) => {"
    << "                btn.value = 'Send Email';"
    << "                alert(JSON.stringify(err));"
    << "                });"
    << "            });"
    << "        </script>\n";
}

void templateEngine::writeDb(){
    Cgicc formData;
    Database database;
    string title,url;

    form_iterator fi = formData.getElement("toWriteTitle");  
    if( !fi->isEmpty() && fi != (*formData).end()) { 
        title = **fi;
        cout << "<h3>Title: " << **fi << "</h3>" << endl;  
    } else {
        cout << "<h3>No text entered for title</h3>" << endl;  
    }
   cout << "<br/>\n";
   
   fi = formData.getElement("toWriteUrl");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
        url = **fi;
        cout << "<h3>Url: " << **fi << "</h3>" << endl;  
        cout << "<img src=\"" << url << "\" id=\"image\"/>\n" << endl;
   } else {
      cout << "<h3>No text entered for url</h3>" << endl;  
   }
   cout << "<br/>\n";

   if(database.writeData(title,url)){
       cout << "<h3> Escrito no banco de dados com sucesso!</h3>\n";
   } else {
       cout << "<h3> Falha ao escrever no banco</h3>\n";
   }
}

void templateEngine::readDb(){
    Cgicc formData;
    Database database;
    string title;
    result list;
    form_iterator fi = formData.getElement("toRead");  
    if( !fi->isEmpty() && fi != (*formData).end()) {  
        title = **fi;
        cout << "<h3>Title " << **fi << "</h3>" << endl;  
    } else {
        cout << "<h3>No text entered for title</h3>" << endl;  
    }
    cout << "<br/>\n";
    list = database.query(title);
    for (auto row: list){
        cout << "<h3><a href=\""<< row["url"] << "\" target=\"_blank\">" << row["url"] << "</a></h3></br>" << endl;
        cout << "<img src=\"" << row["url"] << "\" id=\"image\"/>\n" << endl;
    }
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
    readDb();
    generateBottomHTML();
}
void templateEngine::generateWriteDbPage(){
    generateTopHTML();
    writeDb();
    generateBottomHTML();
}