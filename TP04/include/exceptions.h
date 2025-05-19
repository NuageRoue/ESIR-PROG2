#include "composant_exception.h"

class fichier_introuvable_exception : public composant_exception {
public:
    fichier_introuvable_exception(const std::string& msg) : composant_exception(msg) {}
};

class fin_de_fichier_exception : public composant_exception {
public:
    fin_de_fichier_exception(const std::string& msg) : composant_exception(msg) {}
};

class lecture_fichier_exception : public composant_exception {
public:
    lecture_fichier_exception(const std::string& msg) : composant_exception(msg) {}
};
