// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int k) {
    int i = 0, j = 0, cont = k;
    int mejor = v.size() + 1;
    
    while (j < v.size() || !cont) {
        if (!cont) {
            if (v[i] == 1) {
                if (j - i < mejor) mejor = j - i;
                cont++;
            }
            i++;
        }
        else {
            if (v[j] == 1)
                cont--;
            j++;
        }

    }

    return mejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;

    cin >> n;

    if (n == - 1)
        return false;

    vector<int> v(n);

    for (int& x : v) cin >> x;

    int k;
    cin >> k;
    cout << resolver(v, k ) << '\n';

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
