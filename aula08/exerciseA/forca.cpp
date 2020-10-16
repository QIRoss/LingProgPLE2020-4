#include "forca.hh"

Forca::Forca (int n) : maxTestes(n), testesRestantes(n) {
    fstream file;
    file.open("palavras.txt", fstream::in);
    if (!file.is_open()) {
        cerr << "Arquivo não encontrado" << endl;
        exit (0);
    }
    while (file.good()) {
        string str;
        getline (file, str, ',');
        palavras.push_back(str);
        getline (file, str);
        dicas.push_back(str);
    }
    file.close();
    srand (time(0));
}

void Forca::configure () {
    int idx = rand() % getPalavras().size ();
    setPalavra (getPalavras().at (idx));
    setDica (getDicas().at (idx));
    setCaracteresFaltantes (getPalavra().length());
    cout << "A dica eh: " << getDica()
    << "\nA palavra tem " << getCaracteresFaltantes()
    << " caracteres" <<endl;
    setSegredo('_');
    cout << endl;
    system("pause");
    imprimeSegredo();
}

bool Forca::teste () {
    char in;
    bool achou = false;
    getTestesRestantes()--;
    if (getCaracteresFaltantes() == 0) {
        cout << "\nVoce encontrou o segredo... parabens!" << endl;
        return false;
    }
    if (getTestesRestantes() < 0) {
        cout << "\nPoxa... acabaram as chances..." << endl;
        cout << "A palavra era: " << getPalavra() << endl;
        return false;
    }
    if (getTestesRestantes() == getMaxTestes() - 1) cout << "\n\n\n";
    else cout << "\n";
    cout << "Vc ainda tem " << (getTestesRestantes() + 1)
    << ((getTestesRestantes() > 0) ? " chances" : " chance");
    cout << "\nQual caractere deseja: "; cin >> in; cin.ignore();
    for (unsigned i = 0; i < getSegredo().size(); i++) {
        if (in == getPalavra()[i]) {
            getSegredo().at(i) = in;
            achou = true;
            getCaracteresFaltantes()--;
        }
    }
    imprimeSegredo ();
    cout << endl;
    cout << (achou ? "Letra encontrada!" : "Hum... Letra nao foi encontrada...") << endl;
    return true;
}

void Forca::imprimeSegredo () {
    system("cls");
    for (unsigned i = 0; i < segredo.size(); i++) {
    cout << segredo.at(i) << ' ';
    }
    cout << endl;
}

string Forca::getPalavra() {
    return palavra;
}

string Forca::getDica() {
    return dica;
}

vector <char> &Forca::getSegredo () {
    return segredo;
}

vector <string> Forca::getPalavras() {
    return palavras;
}

vector <string> Forca::getDicas() {
    return dicas;
}

int & Forca::getCaracteresFaltantes () {
    return caracteresFaltantes;
}

int & Forca::getTestesRestantes () {
    return testesRestantes;
}

int Forca::getMaxTestes() {
    return maxTestes;
}

void Forca::setPalavra (string str) {
    palavra = str;
}

void Forca::setDica (string str) {
dica = str;
}

void Forca::setCaracteresFaltantes (int i) {
caracteresFaltantes = i;
}

void Forca::setSegredo(char delim) {
    for (unsigned i = 0; i < palavra.length(); i++) {
        segredo.push_back(delim);
    }
}