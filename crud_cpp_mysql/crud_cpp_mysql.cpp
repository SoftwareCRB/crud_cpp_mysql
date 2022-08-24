#include <iostream>
#include <mysql.h>

using namespace std;

void menu() {
    cout << "---------OPCIONES------"  << endl;
    cout << "| 1 = Ver todos        |" << endl;
    cout << "| 2 = Buscar Id        |" << endl;
    cout << "| 3 = Insertar Nuevo   |" << endl;
    cout << "| 4 = Editar Id        |" << endl;
    cout << "| 5 = Eliminar Id      |" << endl;
    cout << "-----------------------"  << endl;
}
class crud {
public:
    void conexion();
    void create_id();
    void select_all(MYSQL* mycon);
    void select_id();
    void update_id();
    void delete_id();
};

void  crud::select_all(MYSQL * mycon) {
    string consulta;
    int estado;
    MYSQL_ROW row;
    MYSQL_RES* resultado;

    consulta = "SELECT * FROM divisionpolitica.estado;";
    const char* c = consulta.c_str();

    estado = mysql_query(mycon, c);

    if (!estado) {
        resultado = mysql_store_result(mycon);


        while (row = mysql_fetch_row(resultado)) {
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << endl;
        }
    }
    else {
        cout << "error en la consulta";
    }
}

int main()
{
    MYSQL* con;
 

    con = mysql_init(0);
    con = mysql_real_connect(con, "localhost", "testuser", "tstomate", "divisionpolitica", 3306, NULL, 0);

    if (con) {
        cout << "conexion Exitosa" << endl;
    }
    else
    {
        cout << "no hay conexion con servidor mysql" << endl;
    }

    menu();
    //crud c;

    //c.select_all(con);
}

