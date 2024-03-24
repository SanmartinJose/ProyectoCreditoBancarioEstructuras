#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
class MenuPrincipal{
    private:
    bool repite = true;
    int opcion;
    public:
    void menuPrincipal();
    int menu(const char *titulo,const char *opciones[], int n);

};


#endif // MENUPRINCIPAL_H_INCLUDED
