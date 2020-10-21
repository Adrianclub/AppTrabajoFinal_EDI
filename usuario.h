#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

class Usuario
{
public:
    Usuario( const QString& nombre,const QString& contrasenya);
    //getters

    QString nombre() const {return mNombre;}
    QString contrasenya () const {return mContrasenya;}
    //setters

    void setNombre(const QString& nombre){mNombre = nombre;}
    void setContrasenya(const QString& contrasenya) {mContrasenya = contrasenya;}

private:

   QString mNombre;
   QString mContrasenya;


};




#endif // USUARIO_H
