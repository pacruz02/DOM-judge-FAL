// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
long long int resolver(vector<long long int> & v) {
    sort(v.begin(),v.end());
    int cont = 1, max = 1;
    long long int val = v[0], sol = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] == val) cont++;
        else {
            if (cont > max) {
                max = cont;
                sol = val;
            }
            val = v[i];
            cont = 1;
        }
    }

    if (cont > max) {
        max = cont;
        sol = val;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long long int n;

    cin >> n;

    if (n == -1)
        return false;

    vector <long long int> v(n);

    for (long long int & x : v) cin >> x;

    cout << resolver(v) << '\n';

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
