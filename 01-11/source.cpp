// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
    int nPartidos = 0, veces = 0, desde = 0;
};

// función que resuelve el problema
tSol resolver(vector<int> const & v) {
    tSol sol;
    sol.desde = (int)v.size();
    int racha = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0)
            racha++;
        else if(racha > 0){
            if (racha > sol.nPartidos) {
                sol.desde = (int)v.size() - i;
                sol.nPartidos = racha;
                sol.veces = 1;
            }
            else if (racha == sol.nPartidos) {
                sol.desde = (int)v.size() - i;
                sol.veces ++;
            }
            racha = 0;
        }
    }

    if (racha > 0) {

        if (racha > sol.nPartidos) {
            sol.desde = 0;
            sol.nPartidos = racha;
            sol.veces = 1;
        }
        else if (racha == sol.nPartidos) {
            sol.desde = 0;
            sol.veces++;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;

    if (!(cin >> n))
        return false;

    vector <int> v(n);

    for (int& x : v)cin >> x;

    tSol sol = resolver(v);

    cout << sol.nPartidos << ' ' << sol.veces << ' ' << sol.desde << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}